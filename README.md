# Assignment-1-images-Kurisute
Author : Yichen Xie\
Date: Sep/22/2021

## Assignment Tasks
For the introduction to assignment tasks, see
[Assignment 1:Image](https://github.com/nyu-cs-cy-6533-fall-2021/base/blob/main/Assignment_1/requirements/Assignment-1_Images.md)

## Installation
This project is built by CMAKE. Try:
```shell
> cmake .
> make
```
## Result Generation
You can generate experiment results in **test_outputs** folder by running bin file in the project folder:
```shell
./computer_graphics_assignment1_bin
```
However, you have to change the project path in main.cpp for your own environment. And you also have to remove all the .ppm files in the test_output folder before this generation to avoid overwritting problems.


## Mandatory Tasks Results
The pre-produced results can be found in the **test_outputs** folder.

### Overloading of add(+), subtraction(-):
![add.ppm](sample/add.png "add.ppm")

![sub.ppm](sample/sub.png "sub.ppm")

### Overloading of add-assignment(+=), subtraction-assignment(-=):
![add_assignment.ppm](sample/add_assignment.png "add_assignment.ppm")

![sub_assignment.ppm](sample/sub_assignment.png "sub_assignment.ppm")

### Overloading of scale operation(*):
![scale.ppm](sample/scale.png "scale.ppm")

### Gamma Correction with gamma=2.2
![gamma.ppm](sample/gamma.png "gamma.ppm")

### Alpha Composition with alpha=0.50 and 0.85
![alpha050.ppm](sample/alpha050.png "alpha050.ppm")

![alpha085.ppm](sample/alpha085.png "alpha085.ppm")

### Mirror operation on X axis
![mirror.ppm](sample/mirror.png "mirror.ppm")

## Optional Tasks Results
### Binaryzation of Mandrill-gray with threshold=100
![Mandrill_binary.ppm](sample/Mandrill_binary.png "Mandrill_binary.ppm")

### Erosion operation with 5*5 square filter
![Mandrill_erosion.ppm](sample/Mandrill_erosion.png "Mandrill_erosion.ppm")

### Dilation operation with 5*5 square filter
![Mandrill_dilation.ppm](sample/Mandrill_dilation.png "Mandrill_dilation.ppm")

### The final Result: Dilation minus Erosion
![optional_task_result.ppm](sample/optional_task_result.png "optional_task_result.ppm")
