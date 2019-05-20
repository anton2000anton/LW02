#pragma once

namespace MatrixExtension
{
	int inputSize();
	int inputAccuracy();


	typedef double(*value)(int, int);


	typedef double(*exactValue)(int, int, int);


	double** allocateMemoryDouble(int, int);


	void fillMatrix(double**, int, int, value);


	void fillMatrix(double**, int, int, int, exactValue);


	void displayMatrix(double**, int, int);


	double taylorSin(double, int);


	double taylorCos(double, int);


	double maxMatrixDifference(double**, double**, int, int);


	double formula(int, int);


	double formulaTeylor(int, int, int);
}

