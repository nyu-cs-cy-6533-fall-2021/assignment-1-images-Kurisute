#include "image_class.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
    // ifstream fin;
    // fin.open(argv[1], ios::in | ios::binary);
    // PPMImage myimage;
    // fin >> myimage;
    PPMImage myimage(argv[1]);
    //myimage.image_info();
    myimage.head_info();
    ofstream fout;
    fout.open(argv[2]);
    fout << myimage;
    fout.close();
    
    return 0;
}