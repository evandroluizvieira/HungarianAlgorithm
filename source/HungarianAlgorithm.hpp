#ifndef HUNGARIANALGORITHM_HPP
#define HUNGARIANALGORITHM_HPP

#include "Matrix.hpp"

class HungarianAlgorithm {
	private:
		HungarianAlgorithm();

	public:
		virtual ~HungarianAlgorithm();

	public:
		static Matrix<int> execute(const Matrix<int>& matrix);
};

#endif /* HUNGARIANALGORITHM_HPP */
