#include "image_class.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main(){
    string TEST_IMAGE_DIR = "/home/kurisute/projects/CG/assignments/base/Assignment_1/images/";
    string TEST_OUTPUT_DIR = "/home/kurisute/projects/CG/assignments/assignment-1/test_outputs/";

    PPMImage pic1(TEST_IMAGE_DIR+"Mandrill.ppm");
    PPMImage pic2(TEST_IMAGE_DIR+"Mandrill-gray.ppm");
    PPMImage pic3(TEST_IMAGE_DIR+"tandon_stacked_black.ppm");
    PPMImage pic4(TEST_IMAGE_DIR+"tandon_stacked_color.ppm");

    //change pic to binary
    ofstream fout1;
    fout1.open(TEST_OUTPUT_DIR+"Mandrill_binary.ppm",ios::trunc|ios::out);
    PPMImage pic2_binary = pic2;
    pic2_binary.head_info();
    pic2_binary.trans_binary(100);
    pic2_binary.head_info();
    fout1 << pic2_binary;
    fout1.close();

    ofstream fout2;
    fout2.open(TEST_OUTPUT_DIR+"tandon_binary.ppm",ios::trunc|ios::out);
    PPMImage pic3_binary = pic3;
    pic3_binary.head_info();
    pic3_binary.trans_binary(50);
    pic3_binary.head_info();
    fout2 << pic3_binary;
    fout2.close();

    ofstream fout3;
    fout3.open(TEST_OUTPUT_DIR+"Mandrill_erosion.ppm",ios::trunc|ios::out);
    PPMImage pic2_erosion = pic2_binary.square_erosion(5);
    fout3 << pic2_erosion;
    fout3.close();

    ofstream fout4;
    fout4.open(TEST_OUTPUT_DIR+"Mandrill_dilation.ppm",ios::trunc|ios::out);
    PPMImage pic2_dilation = pic2_binary.square_dilation(5);
    fout4 << pic2_dilation;
    fout4.close();

    ofstream fout5;
    fout5.open(TEST_OUTPUT_DIR+"optional_task_result.ppm",ios::trunc|ios::out);
    PPMImage final_result = pic2_dilation - pic2_erosion;
    fout5 << final_result;
    fout5.close();

    return 0;

}