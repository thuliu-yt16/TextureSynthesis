#ifndef API_H
#define API_H
#include "image.h"
#include "vector3.h"
#include "vector2.h"
void GetGaussianKernel(double sigma, int w, double** kernel);

string int2str(int x);

void TextureSynthesis(const Image& sample, const string& savefolder, int radius, int w);

void GetTraversalSequence(const Pixel& center, int radius, vector<Pixel>& ts);

double GetDistanceOfBatch(const Pixel& so, const Pixel& ro,const Image& sample, const Image& res, double** kernel, bool** flag, int w);

int randint(int N);
#endif
