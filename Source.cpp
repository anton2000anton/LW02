#include <iostream>
#include "MatrixLibrary.h"
using namespace MatrixExtension;
using namespace std;

int main()
{
	int matrixSize = inputSize();
	int accuracy = inputAccuracy();
	double** firstMatrix = allocateMemoryDouble(matrixSize, matrixSize);
	double** secondMatrix = allocateMemoryDouble(matrixSize, matrixSize);


	cout << endl << "Matrix without Taylor series: \n";

	fillMatrix(firstMatrix, matrixSize, matrixSize, formula);

	displayMatrix(firstMatrix, matrixSize, matrixSize);



	cout << endl << "Matrix with Taylor series: \n";

	fillMatrix(firstMatrix, matrixSize, matrixSize, accuracy, formulaTeylor);

	displayMatrix(firstMatrix, matrixSize, matrixSize);

	cout << endl << "Max difference of matrix: " << maxMatrixDifference(firstMatrix, secondMatrix, matrixSize, matrixSize) << endl;

	system("pause");

	return 0;

}