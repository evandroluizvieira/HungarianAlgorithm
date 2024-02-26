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
