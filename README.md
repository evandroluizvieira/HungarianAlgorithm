# Hungarian Algorithm

![Logo](https://github.com/evandroluizvieira/HungarianAlgorithm/blob/main/resource/Brand.png)

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
```c++
#include "Matrix.hpp"
#include "HungarianAlgorithm.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main(){
    Matrix<int> matrix({
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    });

    cout << "Matrix" << endl;
    cout << matrix << endl;

    Matrix<int> result = HungarianAlgorithm::execute(matrix);

    cout << "Result" << endl;
    cout << result << endl;

    return 0;
}

```
