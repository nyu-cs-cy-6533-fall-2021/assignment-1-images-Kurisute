#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/image_class.h"

using namespace std;


int main(){
    //You have to change these directories to adapt your own system
    string TEST_IMAGE_DIR = "/home/kurisute/projects/CG/assignments/assignment-1/images/";
    string TEST_OUTPUT_DIR = "/home/kurisute/projects/CG/assignments/assignment-1/test_outputs/";
 
    PPMImage pic1(TEST_IMAGE_DIR+"Mandrill.ppm");
    PPMImage pic2(TEST_IMAGE_DIR+"Mandrill-gray.ppm");
    PPMImage pic3(TEST_IMAGE_DIR+"tandon_stacked_black.ppm");
    PPMImage pic4(TEST_IMAGE_DIR+"tandon_stacked_color.ppm");

    //test operators
    ofstream fout1;
    fout1.open(TEST_OUTPUT_DIR+"add.ppm",ios::out|ios::trunc);
    PPMImage add_pic = pic1 + pic4;
    fout1 << add_pic;
    fout1.close();

    ofstream fout2;
    fout2.open(TEST_OUTPUT_DIR+"sub.ppm",ios::out|ios::trunc);
    PPMImage sub_pic = pic1 - pic4;
    fout2 << sub_pic;
    fout2.close();

    ofstream fout3;
    fout3.open(TEST_OUTPUT_DIR+"add_assignment.ppm",ios::out|ios::trunc);
    PPMImage add_assign = pic1;
    add_assign += pic4;
    fout3 << add_assign;
    fout3.close();

    ofstream fout4;
    fout4.open(TEST_OUTPUT_DIR+"sub_assignment.ppm",ios::out|ios::trunc);
    PPMImage sub_assign = pic1;
    sub_assign -= pic4;
    fout4 << sub_assign;
    fout4.close();

    ofstream fout5;
    fout5.open(TEST_OUTPUT_DIR+"scale.ppm",ios::out|ios::trunc);
    PPMImage scale_pic = pic1;
    scale_pic = scale_pic*2;
    fout5 << scale_pic;
    fout5.close();

    ofstream fout6;
    fout6.open(TEST_OUTPUT_DIR+"mirror.ppm",ios::out|ios::trunc);
    PPMImage mirror_pic = pic1;
    mirror_pic.mirrorX();
    fout6 << mirror_pic;
    fout6.close();

    ofstream fout7;
    fout7.open(TEST_OUTPUT_DIR+"gamma.ppm",ios::out|ios::trunc);
    PPMImage gamma_pic = pic1;
    gamma_pic.gamma_correction(2.2);
    fout7 << gamma_pic;
    fout7.close();

    ofstream fout8;
    fout8.open(TEST_OUTPUT_DIR+"alpha050.ppm",ios::out|ios::trunc);
    PPMImage alpha050_pic = alpha_composition(pic1,pic4,0.50);
    fout8 << alpha050_pic;
    fout8.close();

    ofstream fout9;
    fout9.open(TEST_OUTPUT_DIR+"alpha085.ppm",ios::out|ios::trunc);
    PPMImage alpha085_pic = alpha_composition(pic1,pic4,0.85);
    fout9 << alpha085_pic;
    fout9.close();

    //test operator[]
    cout << "pic1[1][1][1]=" << pic1[1][1][1] << endl;

    //Optional tasks
    //change pic to binary
    ofstream fout10;
    fout10.open(TEST_OUTPUT_DIR+"Mandrill_binary.ppm",ios::out|ios::trunc);
    PPMImage pic2_binary = pic2;
    pic2_binary.trans_binary(100);
    fout10 << pic2_binary;
    fout10.close();

    ofstream fout11;
    fout11.open(TEST_OUTPUT_DIR+"tandon_binary.ppm",ios::out|ios::trunc);
    PPMImage pic3_binary = pic3;
    pic3_binary.trans_binary(50);
    fout11 << pic3_binary;
    fout11.close();

    ofstream fout12;
    fout12.open(TEST_OUTPUT_DIR+"Mandrill_erosion.ppm",ios::out|ios::trunc);
    PPMImage pic2_erosion = pic2_binary.square_erosion(5);
    fout12 << pic2_erosion;
    fout12.close();

    ofstream fout13;
    fout13.open(TEST_OUTPUT_DIR+"Mandrill_dilation.ppm",ios::out|ios::trunc);
    PPMImage pic2_dilation = pic2_binary.square_dilation(5);
    fout13 << pic2_dilation;
    fout13.close();

    ofstream fout14;
    fout14.open(TEST_OUTPUT_DIR+"optional_task_result.ppm",ios::out|ios::trunc);
    PPMImage final_result = pic2_dilation - pic2_erosion;
    fout14 << final_result;
    fout14.close();

    cout << "Test image generation complete!" << endl;

    return 0;
}

