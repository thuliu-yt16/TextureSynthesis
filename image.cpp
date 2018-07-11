#include "image.h"

Image::Image():width(0),height(0),image(NULL){}
Image::Image(int _w,int _h):width(_w),height(_h){
    image = new Color* [width];
    for(int i = 0; i < width; i ++){
        image[i] = new Color[height];
    }
}
Image::Image(const string& filename){
    ifstream in(filename);
    in >> width >> height;
    image = new Color*[width];
    for(int i = 0; i < width; i ++)
        image[i] = new Color[height];
    for(int j = 0; j < height; j ++){
        for(int i = 0; i < width; i ++){
            in >> image[i][j];
        }
    }

}
void Image::save(const string& filename){
    ofstream out(filename);
    out << "P3" << endl;
    out << width << ' ' << height << endl;
    out << 255 << endl;
    for(int j = 0; j < height;j++){
        for(int i = 0; i < width;i++){
            out << int(image[i][j].r) << ' '  << int(image[i][j].g) << ' ' << int(image[i][j].b) << endl;
        }
    }
}
void Image::SetColor(int x,int y, Color color){
    if(0 <= x && x < width && 0 <= y && y < height)
        image[x][y] = color;
    else{
        cout << "Set Error1 : " << Vector2(x,y) << endl;
    }
}
Color Image::GetColor(int x, int y) const{
    if(0 <= x && x < width && 0 <= y && y < height)
        return image[x][y];
    else{
        cout << "Get Error1 : " << Vector2(x,y) << endl;
        return Color();
    }
}

Image::~Image(){
    for(int i = 0;i < width; i++){
        delete[] image[i];
    }
    delete[] image;
}

Color Image::GetColor(const Pixel& p) const{
    if(0 <= p.x && p.x < width && 0 <= p.y && p.y < height)
        return image[p.x][p.y];
    else{
        cout << "Get Error2 : " << p << endl;
        return Color();
    }
}
void Image::SetColor(const Pixel& p, Color color){
    if(0 <= p.x && p.x < width && 0 <= p.y && p.y < height)
        image[p.x][p.y] = color;
    else{
        cout << "Set Error2 : " << p << endl;
    }
}
