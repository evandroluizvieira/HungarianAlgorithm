#include "HungarianAlgorithm.hpp"

HungarianAlgorithm::HungarianAlgorithm(){

}

HungarianAlgorithm::~HungarianAlgorithm(){

}

Matrix<int> HungarianAlgorithm::execute(const Matrix<int>& matrix){
	size_t rows = matrix.getRows();
	size_t cols = matrix.getColumns();

    Matrix<int> result(rows, cols, 0);
    return result;
}
