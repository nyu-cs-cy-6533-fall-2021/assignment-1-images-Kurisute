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
        unsigned int channel;
        unsigned int max_color_value;
        string coding_type;

        vector<vector<vector<unsigned int> > > data;
        //Three dimensions in order: width, height, channel 

        friend ostream &operator<<(ostream &os, PPMImage &image);
        friend istream &operator>>(istream &is, PPMImage &image);

    public:
        PPMImage();
        PPMImage(const string filepath);
        PPMImage(const PPMImage &image);
        
        void head_info();
        void image_info();

        PPMImage operator+(const PPMImage &image);
        PPMImage operator-(const PPMImage &image);
        PPMImage operator*(const float &scalar);
        void mirrorX();
        void operator+=(const PPMImage &image);
        void operator-=(const PPMImage &image);
        vector<vector<unsigned int> > operator[](const int i);

        void gamma_correction(const float gamma);
        PPMImage square_erosion(const int size);
        PPMImage square_dilation(const int size);
        void trans_binary(const int threshold);
};


ostream &operator<<(ostream &os, PPMImage &image);
istream &operator>>(istream &is, PPMImage &image);


PPMImage alpha_composition(PPMImage &foreground,PPMImage &background,float alpha);


#endif