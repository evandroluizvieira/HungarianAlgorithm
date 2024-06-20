# Hungarian Algorithm

![Logo](https://github.com/evandroluizvieira/HungarianAlgorithm/blob/master/resource/Brand.png)

[![C++](https://img.shields.io/badge/C++-004488)](https://cplusplus.com/)
[![BSL1.0 License](https://img.shields.io/badge/License-BSL-green.svg)](https://choosealicense.com/licenses/bsl-1.0/)

## Overview
The Hungarian algorithm, also known as the Munkres algorithm, is a method for solving the assignment problem efficiently. It works by finding the optimal assignment of tasks to workers in a way that minimizes the total cost or maximizes the total benefit. The algorithm iteratively reduces the costs in a cost matrix and finds the optimal assignment by covering zeros with the minimum number of lines. This process continues until all zeros are covered, resulting in the optimal assignment solution.

## Installation
To get started, clone the repository:
```bash
git clone https://github.com/evandroluizvieira/HungarianAlgorithm.git
```

## Usage
Example:
```c++
#include "Matrix.hpp"
#include "HungarianAlgorithm.hpp"

#include <iostream>
using std::cout;
using std::endl;

/*
 * @brief Main function to demonstrate the Hungarian Algorithm.
 * The program creates a cost matrix and uses the Hungarian Algorithm
 * to find the optimal assignment and its cost.
 */
int main(){
    //Define a cost matrix
    Matrix<int> matrix({
	{39,  6, 54, 33, 17},
	{40, 88, 96, 34, 73},
	{57, 34, 32, 66, 30},
	{22, 61, 93, 88, 78},
	{76, 10, 78, 67, 21}
    });

    //Display the input matrix
    cout << "Matrix:" << endl;
    cout << matrix << endl;

    //Execute the Hungarian Algorithm
    Matrix<bool> optimalAssignment = HungarianAlgorithm::execute(matrix);

    //Display the optimal assignment matrix
    cout << "Optimal Assignment:" << endl;
    cout << optimalAssignment << endl;

    //Calculate the optimal cost
    int optimalCost = HungarianAlgorithm::getOptimalCost(matrix, optimalAssignment);

    //Display the optimal cost
    cout << "Optimal Cost:" << endl;
    cout << optimalCost << endl;

    return 0;
}
```
Output:
```console
Matrix:
39  6 54 33 17 
40 88 96 34 73 
57 34 32 66 30 
22 61 93 88 78 
76 10 78 67 21 

Optimal Assignment:
0 1 0 0 0 
0 0 0 1 0 
0 0 1 0 0 
1 0 0 0 0 
0 0 0 0 1 

Optimal Cost:
115
```
