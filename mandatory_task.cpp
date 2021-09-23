#include "image_class.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char* argv[]){
    string TEST_IMAGE_DIR = "/home/kurisute/projects/CG/assignments/base/Assignment_1/images/";
    string TEST_OUTPUT_DIR = "/home/kurisute/projects/CG/assignments/assignment-1/test_outputs/";
 
    PPMImage pic1(TEST_IMAGE_DIR+"Mandrill.ppm");
    PPMImage pic2(TEST_IMAGE_DIR+"Mandrill-gray.ppm");
    PPMImage pic3(TEST_IMAGE_DIR+"tandon_stacked_black.ppm");
    PPMImage pic4(TEST_IMAGE_DIR+"tandon_stacked_color.ppm");

    //test operators
    ofstream fout;
    fout.open(TEST_OUTPUT_DIR+"add.ppm",ios::trunc|ios::out);
    PPMImage add_pic = pic1 + pic4;
    fout << add_pic;
    fout.close();

    fout.open(TEST_OUTPUT_DIR+"sub.ppm",ios::trunc|ios::out);
    PPMImage sub_pic = pic1 - pic4;
    fout << sub_pic;
    fout.close();

    fout.open(TEST_OUTPUT_DIR+"add_assignment.ppm",ios::trunc|ios::out);
    PPMImage add_assign = pic1;
    add_assign += pic4;
    fout << add_assign;
    fout.close();

    fout.open(TEST_OUTPUT_DIR+"sub_assignment.ppm",ios::trunc|ios::out);
    PPMImage sub_assign = pic1;
    sub_assign -= pic4;
    fout << sub_assign;
    fout.close();

    fout.open(TEST_OUTPUT_DIR+"scale.ppm",ios::trunc|ios::out);
    PPMImage scale_pic = pic1;
    scale_pic = scale_pic*2;
    fout << scale_pic;
    fout.close();

    fout.open(TEST_OUTPUT_DIR+"mirror.ppm",ios::trunc|ios::out);
    PPMImage mirror_pic = pic1;
    mirror_pic.mirrorX();
    fout << mirror_pic;
    fout.close();

    fout.open(TEST_OUTPUT_DIR+"gamma.ppm",ios::trunc|ios::out);
    PPMImage gamma_pic = pic1;
    gamma_pic.gamma_correction(2.2);
    fout << gamma_pic;
    fout.close();

    fout.open(TEST_OUTPUT_DIR+"alpha050.ppm",ios::trunc|ios::out);
    PPMImage alpha050_pic = alpha_composition(pic1,pic4,0.50);
    fout << alpha050_pic;
    fout.close();

    fout.open(TEST_OUTPUT_DIR+"alpha085.ppm",ios::trunc|ios::out);
    PPMImage alpha085_pic = alpha_composition(pic1,pic4,0.85);
    fout << alpha085_pic;
    fout.close();

    //test operator[]
    cout << "pic1[1][1][1]=" << pic1[1][1][1] << endl;

    return 0;
}

