#ifndef HUNGARIANALGORITHM_HPP
#define HUNGARIANALGORITHM_HPP

#include "Matrix.hpp"

/*
 * @brief Class implementing the Hungarian Algorithm for solving the assignment problem.
 */
class HungarianAlgorithm {
	private:
		/*
		 * @brief Private constructor to prevent instantiation.
		 */
		HungarianAlgorithm();

	public:
		/*
		 * @brief Virtual Destructor.
		 */
		virtual ~HungarianAlgorithm();

		/*
		 * @brief Executes the Hungarian Algorithm on the given cost matrix.
		 *
		 * @param matrix The cost matrix representing the assignment problem.
		 *
		 * @return The optimal assignment matrix indicating the assignment of tasks to agents.
		 */
		static Matrix<bool> execute(const Matrix<int>& matrix);

		/*
		 * @brief Calculates the optimal cost of the assignment based on the cost matrix and the optimal assignment matrix.
		 *
		 * @param matrix The cost matrix representing the assignment problem.
		 * @param optimalAssignment The optimal assignment matrix indicating the assignment of tasks to agents.
		 *
		 * @return The optimal cost of the assignment.
		 */
		static int getOptimalCost(const Matrix<int>& matrix, const Matrix<bool>& optimalAssignment);
};

#endif /* HUNGARIANALGORITHM_HPP */
