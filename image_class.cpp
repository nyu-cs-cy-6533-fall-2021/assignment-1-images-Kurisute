#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include "image_class.h"

using namespace std;


PPMImage::PPMImage(){}


PPMImage::PPMImage(const string filepath){
    ifstream fin;
    fin.open(filepath, ios::in | ios::binary);
    fin >> *this;
}


PPMImage::PPMImage(const PPMImage &image){
    this->magic_number = image.magic_number;
    this->width = image.width;
    this->height = image.height;
    this->channel = image.channel;
    this->coding_type = image.coding_type;
    this->max_color_value = image.max_color_value;

    //allocate memory for the res
    this->data.resize(this->height);
    for(int i = 0;i < this->height;i++){
        this->data[i].resize(this->width);
        for(int j = 0;j < this->width;j++){
            this->data[i][j].resize(this->channel);
        }
    }

    for(int i = 0;i < this->height;i++){
        for(int j = 0;j < this->width;j++){
            for(int k = 0;k < this->channel;k++){
                this->data[i][j][k] = image.data[i][j][k];
            }
        }
    }
}


istream &operator>>(istream &is, PPMImage &image){
    string readline;

    //get the magic number
    getline(is, image.magic_number, '\n');

    //skip all the comment lines
    while(getline(is, readline)){
        if(readline[0]=='#')
            continue;
        else
            break;
    }

    //get width, height and max_value
    istringstream iss;
    iss.str(readline);
    iss >> image.width;
    iss >> image.height;
    is >> image.max_color_value;

    /*File Type:
    P2: grey and in ascii
    P3: rgb and in ascii
    P5: grey and in binary
    P6: rgb and in binary
    */
    if(image.magic_number == "P1"){
        image.channel = 1;
        image.coding_type = "ascii";
    }
    if(image.magic_number == "P2"){
        image.channel = 1;
        image.coding_type = "ascii";
    }
    if(image.magic_number == "P3"){
        image.channel = 3;
        image.coding_type = "ascii";
    }
    if(image.magic_number == "P4"){
        image.channel = 1;
        image.coding_type = "binary";
    }
    if(image.magic_number == "P5"){
        image.channel = 1;
        image.coding_type = "binary";
    }
    if(image.magic_number == "P6"){
        image.channel = 3;
        image.coding_type = "binary";
    }

    //allocate memory for imagedata
    image.data.resize(image.height);
    for(int i = 0;i < image.height;i++){
        image.data[i].resize(image.width);
        for(int j = 0;j < image.width;j++){
            image.data[i][j].resize(image.channel);
        }
    }

    //read data from istream
    if(image.coding_type == "ascii"){
        for(int i = 0; i < image.height; i++)
            for(int j = 0; j < image.width; j++)
                for(int k = 0; k < image.channel;k++){
                    is >> image.data[i][j][k];
                }
    }
    else if(image.coding_type == "binary"){
        for(int i = 0; i < image.height; i++)
            for(int j = 0; j < image.width; j++)
                for(int k = 0; k < image.channel;k++){
                    is.read((char*)&image.data[i][j][k],1);
                }
    }
}


ostream &operator<<(ostream &os, PPMImage &image){
    //write head
    os << image.magic_number << endl;
    os << image.width << " " << image.height << endl;
    os << image.max_color_value << endl;

    //write imagedata
    if(image.coding_type == "ascii"){
        for(int i = 0; i < image.height; i++){
            for(int j = 0; j < image.width; j++){
                for(int k = 0; k < image.channel;k++){
                    os << image.data[i][j][k] << " ";
                }
                os << " ";
            }
            os << endl;
        }
    }
    else if(image.coding_type == "binary"){
        for(int i = 0; i < image.height; i++)
            for(int j = 0; j < image.width; j++)
                for(int k = 0; k < image.channel;k++){
                    os.write((char*)&image.data[i][j][k],1);
                }
    }
};


void PPMImage::head_info(){
    //show the head information of PPM file
    cout << "magic_number:" << this->magic_number << endl;
    cout << "size:" << this->width << " " << this->height << endl;
    cout << "max_value:"<< this->max_color_value << endl;
    cout << "channel:" << this->channel << endl;
    cout << "coding_type:" << this->coding_type << endl;
}


void PPMImage::image_info(){
    //show the imagedata matrix of PPM file
    for(int i = 0; i < this->height;i++){
        for(int j = 0;j < this->width;j++){
            for(int k = 0;k < this->channel;k++){
                cout << this->data[i][j][k] << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
}


PPMImage PPMImage::operator+(const PPMImage &image){
    if(this->width != image.width 
        || this->height != image.height 
        || this->channel != image.channel){
        throw "Images are not in the same size or channel.";
    }

    PPMImage res = *this;

    for(int i = 0;i < res.height;i++){
        for(int j = 0;j < res.width;j++){
            for(int k = 0;k < res.channel;k++){
                res.data[i][j][k] = res.data[i][j][k] + image.data[i][j][k];
            }
        }
    }

    return res;
}


PPMImage PPMImage::operator-(const PPMImage &image){
    if(this->width != image.width 
        || this->height != image.height 
        || this->channel != image.channel){
        throw "Images are not in the same size or channel.";
    }

    PPMImage res = *this;

    for(int i = 0;i < res.height;i++){
        for(int j = 0;j < res.width;j++){
            for(int k = 0;k < res.channel;k++){
                res.data[i][j][k] = (res.data[i][j][k]>image.data[i][j][k])?res.data[i][j][k] - image.data[i][j][k]:0;
            }
        }
    }

    return res;
}


PPMImage PPMImage::operator*(const float &scalar){
    PPMImage res = *this;
    for(int i = 0;i < res.height;i++){
        for(int j = 0;j < res.width;j++){
            for(int k = 0;k < res.channel;k++){
                res.data[i][j][k] = (unsigned int)(res.data[i][j][k] * scalar);
            }
        }
    }

    return res;
}


void PPMImage::mirrorX(){
    for(int i = 0;i < this->height/2;i++){
        for(int j = 0;j < this->width;j++){
            for(int k = 0;k < this->channel;k++){
                swap(this->data[i][j][k],this->data[this->height-i-1][j][k]);
            }
        }
    }
}


void PPMImage::operator+=(const PPMImage &image){
    if(this->width != image.width 
        || this->height != image.height 
        || this->channel != image.channel){
        throw "Images are not in the same size or channel.";
    }

    for(int i = 0;i < this->height;i++){
        for(int j = 0;j < this->width;j++){
            for(int k = 0;k < this->channel;k++){
                this->data[i][j][k] = (this->data[i][j][k]+image.data[i][j][k])/2;
            }
        }
    }
}


void PPMImage::operator-=(const PPMImage &image){
    if(this->width != image.width 
        || this->height != image.height 
        || this->channel != image.channel){
        throw "Images are not in the same size or channel.";
    }

    for(int i = 0;i < this->height;i++){
        for(int j = 0;j < this->width;j++){
            for(int k = 0;k < this->channel;k++){
                this->data[i][j][k] = (this->data[i][j][k]>image.data[i][j][k])?this->data[i][j][k]-image.data[i][j][k]:0;
            }
        }
    }
}


vector<vector<unsigned int> > PPMImage::operator[](const int i){
    return this->data[i];
}

void PPMImage::gamma_correction(const float gamma){
    for(int i = 0;i < this->height;i++){
        for(int j = 0;j < this->width;j++){
            for(int k = 0;k < this->channel;k++){
                this->data[i][j][k] = (unsigned int)(pow((this->data[i][j][k]+0.5)/256,1/gamma)*256-0.5);
            }
        }
    }
}


PPMImage PPMImage::square_erosion(const int size){
    if(this->max_color_value != 1 || this->channel != 1){
        throw "Cannot apply erosion to a non-binary image.";
    }
    if(size%2 == 0){
        throw "The size of square structing element should be odd.";
    }

    //create a empty binary image
    PPMImage res = *this;
    for(int i = 0;i < res.height;i++){
        for(int j = 0;j < res.width;j++){
            for(int k = 0;k < res.channel;k++){
                res.data[i][j][k] = 0;
            }
        }
    }

    //Radius of element
    int r = size/2;

    for(int i = 0;i < this->height;i++){
        for(int j = 0;j < this->width;j++){
            for(int k = 0;k < this->channel;k++){
                bool fitflag = true;
                int up = (r < i)?r:i;
                int down = (r < this->height-1-i)?r:this->height-1-i;
                int left = (r < j)?r:j; 
                int right = (r < this->width-1-j)?r:this->width-1-j;
               
                if(this->data[i][j][k] != 1){
                    fitflag = false;
                }
                for(int m = i-up;m <= i+down;m++){
                    for(int n = j-left;n <= j+right;n++){
                        if(this->data[m][n][k] != 1)
                            fitflag = false;
                    }
                }
                res.data[i][j][k] = fitflag?1:0;
            }
        }
    }

    return res;
}


PPMImage PPMImage::square_dilation(const int size){
    if(this->max_color_value != 1 || this->channel != 1){
        throw "Cannot apply dilation to a non-binary image.";
    }
    if(size%2 == 0){
        throw "The size of square structing element should be odd.";
    }

    //create a empty binary image
    PPMImage res = *this;
    for(int i = 0;i < res.height;i++){
        for(int j = 0;j < res.width;j++){
            for(int k = 0;k < res.channel;k++){
                res.data[i][j][k] = 0;
            }
        }
    }

    //Radius of element
    int r = size/2;

    for(int i = 0;i < this->height;i++){
        for(int j = 0;j < this->width;j++){
            for(int k = 0;k < this->channel;k++){
                bool fitflag = false;
                int up = (r < i)?r:i;
                int down = (r < this->height-1-i)?r:this->height-1-i;
                int left = (r < j)?r:j; 
                int right = (r < this->width-1-j)?r:this->width-1-j;
                for(int m = i-up;m <= i+down;m++){
                    for(int n = j-left;n <= j+right;n++){
                        if(this->data[m][n][k] == 1)
                            fitflag = true;
                    }
                }
                res.data[i][j][k] = fitflag?1:0;
            }
        }
    }

    return res;
}


void PPMImage::trans_binary(const int threshold){
    // if(this->channel != 1){
    //     throw "Only gray-scale image can be binarilized.";
    // }
    this->max_color_value = 1;
    this->magic_number = "P1";
    this->channel = 1;
    this->coding_type = "ascii";
    for(int i = 0;i < this->height;i++){
        for(int j = 0;j < this->width;j++){
            for(int k = 0;k < this->channel;k++){
                this->data[i][j][k] = (this->data[i][j][k] > threshold)?0:1;
            }
        }
    }
    return;
}


PPMImage alpha_composition(PPMImage &foreground,PPMImage &background,float alpha){
    return foreground*alpha+background*(1-alpha);
}