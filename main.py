import numpy as np
import random
import matplotlib.pyplot as plt
from PIL import Image


def GetGaussianKernel(sigma, w):
    p = - 1 / (2 * sigma ** 2)
    p2 = 1 / (2 * np.pi * sigma ** 2)

    def GaussianFunction(x, y):
        return p2 * np.exp(p * ((x - (w - 1) * 0.5) ** 2 + (y - (w - 1) * 0.5) ** 2))

    a = np.array([[GaussianFunction(i,j) for j in xrange(0, w)] for i in xrange(0, w)])
    a /= np.sum(a)
    return a



def GetTraversalSequence(center, r):
    l = [center]
    def addTraversalSequence(ts, w):

        x = center[0] + w
        y = center[1] + w
        for i in xrange(2 * w):
            ts.append((x,y))
            x -= 1
        for i in xrange(2 * w):
            ts.append((x,y))
            y -= 1
        for i in xrange(2 * w):
            ts.append((x,y))
            x += 1
        for i in xrange(2 * w):
            ts.append((x,y))
            y += 1
    for i in xrange(1, r + 1):
        addTraversalSequence(l, i)
    return l

def SquaredDis(clr1,clr2):
    return np.linalg.norm(clr1 - clr2)

def TextureSynthesis(sample):
    samwidth, samheight = sample.size
    width = 512
    height = 512
    w = 11
    epsilon = 0.1

    samplepixel = np.array(sample)
    res = Image.new("RGB",(width,height),(0,0,0))

    respixel = np.array(Image.new("RGB",(width, height),(255,0,0)))
    kernel = GetGaussianKernel(1, w)
    flag = np.zeros((height, width), dtype = 'bool')
    center = (height / 2, width / 2)
    ts = GetTraversalSequence(center, 25)
    delta = (w - 1) / 2

    def GetDistanceOfBatch(samplepos, respos):
        samplebegin = np.array(samplepos) - [delta, delta]
        resbegin = np.array(respos) - [delta, delta]

        valid = np.zeros((w,w), dtype = 'bool')
        validcnt = 0
        for i in xrange(w):
            for j in xrange(w):
                rp1 = samplebegin + [i,j]
                rp2 = resbegin + [i,j]
                if rp1[0] >= 0 and rp1[0] < samheight and rp1[1] >= 0 and \
                rp1[1] < samwidth and rp2[0] >= 0 and rp2[0] < height and \
                rp2[1] >= 0 and rp2[1] < width and flag[tuple(rp2)]:
                    validcnt += 1
                    valid[i,j] = True
        if validcnt == 0:
            return 1e6
        disMatrix = np.array([[SquaredDis(samplepixel[tuple(samplebegin + [i,j])], respixel[tuple(resbegin + [i,j])]) if valid[i,j] else 0 for j in xrange(w)] for i in xrange(w)])

        return np.sum(disMatrix * kernel) / validcnt

    init_x = random.randint(0, samheight - 3)
    init_y = random.randint(0, samwidth - 3)
    respixel[height / 2 - 1 : height / 2 + 2, width / 2 - 1 : width / 2 + 2 , :] = samplepixel[init_x:init_x + 3, init_y : init_y + 3, :]
    flag[height / 2 - 1 : height / 2 + 2, width / 2 - 1 : width / 2 + 2 ] = True

    cnt = 0
    print len(ts)
    for pos in ts:
        if flag[pos]:
            print "Done"
            continue
        dis = np.zeros((samheight, samwidth), dtype = 'float32')
        for x in xrange(0, samheight):
            for y in xrange(0, samwidth):
                #print x,y
                dist = GetDistanceOfBatch((x,y), pos)
                if dist == 0:
                    dist = 1
                dis[x,y] = dist
        minDis = np.min(dis)
        print minDis
        candidatePos = np.where(dis <= minDis * (1 + epsilon))
        candidateColor = samplepixel[candidatePos]
        color = random.choice(candidateColor)
        respixel[pos] = np.array(color)
        flag[pos] = True
        print color
        print cnt
        cnt += 1

    res = Image.fromarray(respixel)
    res.show()
    res.save('./res.jpg')

sample = Image.open('./src/2.jpg')
TextureSynthesis(sample)
