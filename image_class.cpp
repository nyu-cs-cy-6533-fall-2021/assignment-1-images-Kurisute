#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "image_class.h"

using namespace std;


PPMImage::PPMImage(){}


PPMImage::PPMImage(const string filepath){
    ifstream fin;
    fin.open(filepath, ios::in | ios::binary);
    fin >> *this;
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

    //allocate memory for imagedata
    if(image.magic_number == "P2" || image.magic_number == "P5"){
        image.data.resize(image.height);
        for(int i = 0;i < image.height;i++){
            image.data[i].resize(image.width);
            for(int j = 0;j < image.width;j++){
                image.data[i][j].resize(1);
            }
        }
    }

    if(image.magic_number == "P3" || image.magic_number == "P6"){
        image.data.resize(image.height);
        for(int i = 0;i < image.height;i++){
            image.data[i].resize(image.width);
            for(int j = 0;j < image.width;j++){
                image.data[i][j].resize(3);
            }
        }
    }

    //read data from istream
    if(image.magic_number == "P2"){
        for(int i = 0; i < image.height; i++)
            for(int j = 0; j < image.width; j++){
                is >> image.data[i][j][0];
            }
    }
    else if(image.magic_number == "P5"){
        for(int i = 0; i < image.height; i++)
            for(int j = 0; j < image.width; j++){
                is.read((char*)&image.data[i][j][0],1);
            }
    }
    else if(image.magic_number == "P3"){
        for(int i = 0; i < image.height; i++)
            for(int j = 0; j < image.width; j++)
                for(int k = 0; k < 3;k++){
                    is >> image.data[i][j][k];
                }
    }
    else if(image.magic_number == "P6"){
        for(int i = 0; i < image.height; i++)
            for(int j = 0; j < image.width; j++)
                for(int k = 0; k < 3;k++){
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
    if(image.magic_number == "P2"){
        for(int i = 0; i < image.height; i++){
            for(int j = 0; j < image.width; j++){
                os << image.data[i][j][0] << "";
            }
            os << endl;
        }
    }
    else if(image.magic_number == "P5"){
        for(int i = 0; i < image.height; i++)
            for(int j = 0; j < image.width; j++){
                os.write((char*)&image.data[i][j][0],1);
            }
    }
    else if(image.magic_number == "P3"){
        for(int i = 0; i < image.height; i++){
            for(int j = 0; j < image.width; j++){
                for(int k = 0; k < 3;k++){
                    os << image.data[i][j][k] << " ";
                }
                os << " ";
            }
            os << endl;  
        }
    }
    else if(image.magic_number == "P6"){
        for(int i = 0; i < image.height; i++){
            for(int j = 0; j < image.width; j++){
                for(int k = 0; k < 3;k++){
                    os.write((char*)&image.data[i][j][k],1);
                }
            }
        }
    }
};


void PPMImage::head_info(){
    //show the head information of PPM file
    cout << this->magic_number << endl;
    cout << this->width << " " << this->height << endl;
    cout << this->max_color_value << endl;
}


void PPMImage::image_info(){
    //show the imagedata matrix of PPM file
    int pixel = (this->magic_number=="P2" || this->magic_number=="P5")?1:3;
    for(int i = 0; i < this->height;i++){
        for(int j = 0;j < this->width;j++){
            for(int k = 0;k < pixel;k++){
                cout << this->data[i][j][k] << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
}