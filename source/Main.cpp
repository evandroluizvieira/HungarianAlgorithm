#include "Matrix.hpp"
#include "HungarianAlgorithm.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main(){
	//Size 2x2
	//Matrix<int> matrix({
	//	{20, 10},
	//	{ 5, 25}
	//});

	//Size 3x3
	//Matrix<int> matrix({
	//	{20,  9, 96},
	//	{28, 88, 11},
	//	{21, 56, 59}
	//});

	//Size 4x4
	//Matrix<int> matrix({
	//	{82, 83, 69, 92},
	//	{77, 37, 49, 92},
	//	{11, 69,  5, 86},
	//	{ 8,  9, 98, 23}
	//});


	//Size 5x5
	Matrix<int> matrix({
		{39,  6, 54, 33, 17},
		{40, 88, 96, 34, 73},
		{57, 34, 32, 66, 30},
		{22, 61, 93, 88, 78},
		{76, 10, 78, 67, 21}
	});

    cout << "Matrix" << endl;
    cout << matrix << endl;

    Matrix<bool> optimalAssignment = HungarianAlgorithm::execute(matrix);

    cout << "Optimal Assignment" << endl;
    cout << optimalAssignment << endl;

    int optimalCost = HungarianAlgorithm::getOptimalCost(matrix, optimalAssignment);

    cout << "Optimal Cost " << endl;
    cout << optimalCost << endl;

    return 0;
}
