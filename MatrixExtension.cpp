#define _USE_MATH_DEFINES
#include "MatrixLibrary.h"
#include "iostream"
#include "math.h"

using namespace std;


int MatrixExtension::inputSize()
{

	int matrixSize;

	cout << "Enter size of your square matrix: ";
	cin >> matrixSize;

	return matrixSize;

}


int MatrixExtension::inputAccuracy()
{

	int accuracy;

	cout << "Enter accurance: ";
	cin >> accuracy;

	return accuracy;

}


double** MatrixExtension::allocateMemoryDouble(int rows, int colums)
{

	double** matrix = new double*[rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[colums];
	}

	return matrix;

}


void MatrixExtension::fillMatrix(double** matrix, int rows, int colums, value formula)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			matrix[i][j] = formula(i, j);
		}
	}

}


void MatrixExtension::fillMatrix(double** matrix, int rows, int colums, int accuracy, exactValue formula)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			matrix[i][j] = formula(i, j, accuracy);
		}
	}

}


void MatrixExtension::displayMatrix(double** matrix, int rows, int colums)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			cout << " " << matrix[i][j];
		}

		cout << endl;
	}

}


double MatrixExtension::taylorSin(double number, int accuracy)
{
	number = fmod(number, M_PI * 2);

	double sin = 0, term = number;

	int i = 1;



	while (abs(term) > pow(0.1, accuracy))
	{
		sin += term;

		term *= -1.0*(number * number) / (2 * i) / (2 * i + 1);

		i++;

	}

	return sin;

}


double MatrixExtension::taylorCos(double number, int accuracy)
{
	number = fmod(number, M_PI * 2);
	double cos = 0, term = 1;
	int i = 1;

	while (abs(term) > pow(0.1, accuracy))
	{
		cos += term;

		term *= -1.0*(number * number) / (2 * i) / (2 * i - 1);

		i++;
	}

	return cos;

}


double MatrixExtension::maxMatrixDifference(double** firstMatrix, double** secondMatrix, int rows, int colums)
{
	double maxDifference = 0;
	double currentDifference = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			currentDifference = fabs(secondMatrix[i][j] - firstMatrix[i][j]);

			if (currentDifference > maxDifference)
			{
				maxDifference = currentDifference;
			}

		}

	}

	return maxDifference;

}


double MatrixExtension::formula(int i, int j)
{

	if (i != j)
	{
		return (sin(i+j)+sin(i-j) / pow(i +j+1, 2));
	}
	else
	{
		return (double) 1;
	}

}


double MatrixExtension::formulaTeylor(int i, int j, int accuracy)
{

	if (i != j)
	{
		return (taylorSin(i + j, accuracy) + taylorSin(i - j, accuracy) / pow(i + j + 1, 2));
	}
	else
	{
		return (double) 1;
	}

}


