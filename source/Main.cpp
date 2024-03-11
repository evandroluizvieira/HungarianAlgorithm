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
	//Define a cost matrix size 2x2
	//Matrix<int> matrix({
	//	{20, 10},
	//	{ 5, 25}
	//});

	//Define a cost matrix size 3x3
	//Matrix<int> matrix({
	//	{20,  9, 96},
	//	{28, 88, 11},
	//	{21, 56, 59}
	//});

	//Define a cost matrix size 4x4
	//Matrix<int> matrix({
	//	{82, 83, 69, 92},
	//	{77, 37, 49, 92},
	//	{11, 69,  5, 86},
	//	{ 8,  9, 98, 23}
	//});

	//Define a cost matrix size  5x5
	Matrix<int> matrix({
		{39,  6, 54, 33, 17},
		{40, 88, 96, 34, 73},
		{57, 34, 32, 66, 30},
		{22, 61, 93, 88, 78},
		{76, 10, 78, 67, 21}
	});

    //Display the input matrix
    cout << "Matrix" << endl;
    cout << matrix << endl;

    //Execute the Hungarian Algorithm
    Matrix<bool> optimalAssignment = HungarianAlgorithm::execute(matrix);

    //Display the optimal assignment matrix
    cout << "Optimal Assignment" << endl;
    cout << optimalAssignment << endl;

    //Calculate the optimal cost
    int optimalCost = HungarianAlgorithm::getOptimalCost(matrix, optimalAssignment);

    //Display the optimal cost
    cout << "Optimal Cost " << endl;
    cout << optimalCost << endl;

    return 0;
}
