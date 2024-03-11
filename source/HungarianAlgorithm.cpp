#include "HungarianAlgorithm.hpp"

#include <algorithm>
#include <limits>
#include <vector>

using std::min;
using std::numeric_limits;
using std::size_t;
using std::vector;

HungarianAlgorithm::HungarianAlgorithm(){

}

HungarianAlgorithm::~HungarianAlgorithm(){

}

Matrix<bool> HungarianAlgorithm::execute(const Matrix<int>& matrix){
    size_t rows = matrix.getRows();
    size_t cols = matrix.getColumns();

    //Avoiding negative elements matrix
    for(size_t i = 0; i < rows; ++i){
		for(size_t j = 0; j < cols; ++j){
			if(matrix(i, j) < 0){
		        return Matrix<bool>();
			}
		}
	}

    //Avoiding invalid size matrix
    if(rows != cols || rows == 0 || cols == 0){
        return Matrix<bool>();
    }else{
        if(rows == 1 || cols == 1){
            return Matrix<bool>(1, 1, true);
        }
    }

    //Doing the 2x2 size manually
    Matrix<bool> optimalAssignment = Matrix<bool>(rows, cols, false);
    if(rows == 2 && cols == 2){
        int cost0x0to0x1 = matrix(0, 0) + matrix(0, 1);
        int cost0x0to1x1 = matrix(0, 0) + matrix(1, 1);
        int cost1x0to0x1 = matrix(1, 0) + matrix(0, 1);
        int cost1x0to1x1 = matrix(1, 0) + matrix(1, 1);

        if(cost0x0to0x1 <= cost0x0to1x1 && cost0x0to0x1 <= cost1x0to0x1 && cost0x0to0x1 <= cost1x0to1x1){
            optimalAssignment(0, 0) = true;
            optimalAssignment(0, 1) = true;
        }else if(cost0x0to1x1 <= cost0x0to0x1 && cost0x0to1x1 <= cost1x0to0x1 && cost0x0to1x1 <= cost1x0to1x1){
            optimalAssignment(0, 0) = true;
            optimalAssignment(1, 1) = true;
        }else if(cost1x0to0x1 <= cost0x0to0x1 && cost1x0to0x1 <= cost0x0to1x1 && cost1x0to0x1 <= cost1x0to1x1){
            optimalAssignment(1, 0) = true;
            optimalAssignment(0, 1) = true;
        }else{
            optimalAssignment(1, 0) = true;
            optimalAssignment(1, 1) = true;
        }
        return optimalAssignment;
    }


    Matrix<int> result = Matrix<int>(rows, cols, 0);

    //Step 1: Row reduction
    for(size_t i = 0; i < rows; ++i){
        int minVal = matrix(i, 0);
        for(size_t j = 0; j < cols; ++j){
            if(matrix(i, j) < minVal){
                minVal = matrix(i, j);
            }
        }

        for(size_t j = 0; j < cols; ++j){
            result(i, j) = matrix(i, j) - minVal;
        }
    }

    //Step 2: Column reduction
    for(size_t j = 0; j < cols; ++j){
        int minVal = result(0, j);
        for(size_t i = 0; i < rows; ++i){
            if(result(i, j) < minVal){
                minVal = result(i, j);
            }
        }
        for(size_t i = 0; i < rows; ++i){
            result(i, j) -= minVal;
        }
    }

    while(true){
    	//Step 3: Cover zeros
		vector<bool> coveredRows(rows, false);
		vector<bool> coveredCols(cols, false);

		//cover rows with multiple zeros
		for(size_t i = 0; i < rows; ++i){
			int totalZeros = 0;
			for(size_t j = 0; j < cols; ++j){
				if(result(i, j) == 0){
					totalZeros++;
				}
			}

			if(totalZeros > 1){
				coveredRows[i] = true;
			}
		}

		//cover columns with multiple zeros
		for(size_t j = 0; j < cols; ++j){
			int totalZeros = 0;
			for(size_t i = 0; i < rows; ++i){
				if(result(i, j) == 0){
					totalZeros++;
				}
			}

			if(totalZeros > 1){
				coveredCols[j] = true;
			}
		}

		//cover missing zeros elements
		for(size_t i = 0; i < rows; ++i){
			for(size_t j = 0; j < cols; ++j){
				if(result(i, j) == 0 && !coveredRows[i] && !coveredCols[j]){
					coveredRows[i] = true;
					break;
				}
			}
		}

		//count minimum total lines to cover all zeros
		int numberOfCoveredLines = 0;
		for(size_t i = 0; i < rows; ++i){
			if(coveredRows[i] == true){
				numberOfCoveredLines++;
			}
		}

		for(size_t j = 0; j < cols; ++j){
			if(coveredCols[j] == true){
				numberOfCoveredLines++;
			}
		}

		int matrixSize = rows;//size is row or column due to the fact the matrix is square, N x N
	    if(numberOfCoveredLines >= matrixSize){
	    	break;
	    }

		// Find the smallest uncovered element off the previous lines
		int minUncovered = numeric_limits<int>::max();
		for(size_t i = 0; i < rows; ++i){
			for(size_t j = 0; j < cols; ++j){
				if(result(i, j) != 0 && !coveredRows[i] && !coveredCols[j]){
					minUncovered = min(minUncovered, result(i, j));
				}
			}
		}

		//Step 4: Subtract the smallest uncovered number from all uncovered elements and add the smallest uncovered number to all elements covered twice
		for(size_t i = 0; i < rows; ++i){
			for(size_t j = 0; j < cols; ++j){
				if(!coveredRows[i] && !coveredCols[j]){
					result(i, j) -= minUncovered;
				}else if(coveredRows[i] && coveredCols[j]){
					result(i, j) += minUncovered;
				}
			}
		}
    }

    //Step 5: Find the optimal assignment path
	vector<bool> coveredCols(cols, false);
	for(size_t i = 0; i < rows; ++i){
		for(size_t j = 0; j < cols; ++j){
			if(result(i, j) == 0 && !coveredCols[j]){
				coveredCols[j] = true;
				optimalAssignment(i, j) = true;
				break;
			}
		}
	}

    return optimalAssignment;
}

int HungarianAlgorithm::getOptimalCost(const Matrix<int>& matrix, const Matrix<bool>& optimalAssignment){
    size_t mRows = matrix.getRows();
    size_t mCols = matrix.getColumns();

    size_t oRows = optimalAssignment.getRows();
	size_t oCols = optimalAssignment.getColumns();

    if((mRows != mCols || mRows == 0 || mCols == 0) && (mRows != oRows || mCols != oCols)){
        return 0;
    }else{
        if(mRows == 1 || mCols == 1){
            return 1;
        }
    }

    int optimalCost = 0;
	for(size_t i = 0; i < mRows; ++i){
		for(size_t j = 0; j < mCols; ++j){
			if(optimalAssignment(i, j) == true){
				optimalCost += matrix(i, j);
			}
		}
	}

	return optimalCost;
}

