# Assignment-1-images-Kurisute
Author : Yichen Xie\
Date: Sep/22/2021

## Assignment Tasks
---
For the introduction to assignment tasks, see
[Assignment 1:Image](https://github.com/nyu-cs-cy-6533-fall-2021/base/blob/main/Assignment_1/requirements/Assignment-1_Images.md)

## Installation
---
This project is built by CMAKE. Try:
```shell
> cmake .
> make
```
## Result Generation
---
You can generate experiment results in **test_outputs** folder by running bin file in the project folder:
```shell
./computer_graphics_assignment1_bin
```
However, you have to change the project path in main.cpp for your own environment. And you also have to remove all the .ppm files in the test_output folder before this generation to avoid overwritting problems.


## Mandatory Tasks Results
---
The pre-produced results can be found in the **test_outputs** folder.

### Overloading of add(+), subtraction(-):
![add.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "add.ppm")

![sub.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "sub.ppm")

### Overloading of add-assignment(+=), subtraction-assignment(-=):
![add_assignment.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "add_assignment.ppm")

![sub_assignment.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "sub_assignment.ppm")

### Overloading of scale operation(*):
![scale.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "scale.ppm")

### Gamma Correction with gamma=2.2
![gamma.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "gamma.ppm")

### Alpha Composition with alpha=0.50 and 0.85
![alpha050.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "alpha050.ppm")

![alpha085.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "alpha085.ppm")

### Mirror operation on X axis
![mirror.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "mirror.ppm")

## Optional Tasks Results
---
### Binaryzation of Mandrill-gray with threshold=100
![Mandrill_binary.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "Mandrill_binary.ppm")

### Erosion operation with 5*5 square filter
![Mandrill_erosion.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "Mandrill_erosion.ppm")

### Dilation operation with 5*5 square filter
![Mandrill_dilation.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "Mandrill_dilation.ppm")

### The final Result: Dilation minus Erosion
![optional_task_result.ppm](https://github.com/nyu-cs-cy-6533-fall-2021/assignment-1-images-Kurisute/blob/master/test_outputs/add.ppm "optional_task_result.ppm")
