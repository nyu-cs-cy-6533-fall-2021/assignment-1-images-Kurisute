#ifndef IMAGE_CLASS_H
#define IMAGE_CLASS_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class PPMImage{
    private:
        string magic_number;
        unsigned int width;
        unsigned int height;
        unsigned int max_color_value;

        vector<vector<vector<unsigned int> > > data;
        //Three dimensions in order: width, height, channel 

        friend ostream &operator<<(ostream &os, PPMImage &image);
        friend istream &operator>>(istream &is, PPMImage &image);
    public:
        PPMImage();
        PPMImage(const string filepath);
        void head_info();
        void image_info();
};


ostream &operator<<(ostream &os, PPMImage &image);
istream &operator>>(istream &is, PPMImage &image);

#endif