#include "pch.h"

//Mnożenie macierzy przez liczbę
class MultiplicationByIntTests : public ::testing::TestWithParam<tuple<Matrix, int, Matrix>> {

};


TEST_P(MultiplicationByIntTests, CheckMultiplicationByInt)
{
	Matrix A = get<0>(GetParam());
	int multiplier = get<1>(GetParam());
	Matrix expected_result = get<2>(GetParam());
	A = A * multiplier;
	ASSERT_TRUE(A == expected_result) << "multiplier: " << multiplier;
}

INSTANTIATE_TEST_CASE_P(CheckMultiplicationByInt, MultiplicationByIntTests,
	::testing::Values(
		make_tuple(Matrix(2, 1.0), 2, Matrix(2, 2.0)),
		make_tuple(Matrix(5,3, 1.0), 2, Matrix(5,3, 2.0)),
		make_tuple(Matrix(5, 1.0), 10, Matrix(5, 10.0)),
		make_tuple(Matrix(5, 1.0), 0, Matrix(5, 0.0)),
		make_tuple(Matrix(5, 1.0), -1, Matrix(5, -1.0)),
		make_tuple(Matrix(2, 1.0), 4, Matrix(2, 4.0)),
		make_tuple(Matrix(2, 2.0), 2, Matrix(2, 4.0)),
		make_tuple(Matrix(2, 3.0), 2, Matrix(2, 6.0)),
		
		//Moje testy
		//Macierze kwadratowe
		make_tuple(Matrix(2, 0.0), 1, Matrix(2, 0.0)),		//Test negatywny
		make_tuple(Matrix(2, 2.0), -1, Matrix(2, -2.0)),	//Test pozytywny
		make_tuple(Matrix(4, 3.0), 2, Matrix(4, 6.0)),		//Test pozytywny
		make_tuple(Matrix(4, 3.0), -2, Matrix(4, -6.0)),	//Test pozytywny
		make_tuple(Matrix(3, 0.0), 3, Matrix(3, 0.0)),		//Test negatywny
		make_tuple(Matrix(3, 1.0), -3, Matrix(3, -3.0)),	//Test pozytywny
		make_tuple(Matrix(5, 0.0), 4, Matrix(5, 0.0)),		//Test pozytywny
		make_tuple(Matrix(5, 6.0), -4, Matrix(5, -24.0)),	//Test pozytywny
		make_tuple(Matrix(6, 0.0), 5, Matrix(6, 0.0)),		//Test negatywny
		make_tuple(Matrix(6, 5.1), -5, Matrix(6, -25.5)),	//Test pozytywny
		make_tuple(Matrix(5, 6.0), 6, Matrix(5, 36.0)),		//Test pozytywny
		make_tuple(Matrix(5, 6.0), -6, Matrix(5, -36.0)),	//Test pozytywny
		make_tuple(Matrix(5, 1.0), 6, Matrix(5, 6.0)),		//Test pozytywny

		//Macierze niekwadratowe
		make_tuple(Matrix(2, 3, 1.0), 2, Matrix(2, 3, 2.1)),	//Test negatywny
		make_tuple(Matrix(5, 3, 1.0), 2, Matrix(5, 3, 2.2)),	//Test negatywny
		make_tuple(Matrix(5, 7, 1.0), 10, Matrix(5, 7, 10.0)),	//Test pozytywny
		make_tuple(Matrix(10, 5, 1.0), 0, Matrix(10, 5, 0.0)),	//Test pozytywny	
		make_tuple(Matrix(17, 5, 1.0), -1, Matrix(17, 5, -1.0)),//Test pozytywny
		make_tuple(Matrix(8, 2, 1.0), 4, Matrix(8, 2, 4.0)),	//Test pozytywny	
		make_tuple(Matrix(9, 2, 2.0), 2, Matrix(9, 2, 4.0)),	//Test pozytywny
		make_tuple(Matrix(16, 2, 3.0), 2, Matrix(16, 2, 6.0))	//Test pozytywny
));

//WNIOSKI: Występuje błąd podczas mnożenia macierzy przez liczbę nieparzystą dodatnią



//Mnożenie macierzy przez macierz
class MultiplicationByMatrixTests : public ::testing::TestWithParam<tuple<Matrix, Matrix, Matrix>> {

};

TEST_P(MultiplicationByMatrixTests, CheckMultiplicationByMatrix)
{
	Matrix A = get<0>(GetParam());
	Matrix B = get<1>(GetParam());
	Matrix expected_result = get<2>(GetParam());
	A = A * B;
	ASSERT_TRUE(A == expected_result);
}

INSTANTIATE_TEST_CASE_P(CheckMultiplicationByMatrix, MultiplicationByMatrixTests,
	::testing::Values(
		make_tuple(Matrix(3, 4.0), Matrix(3, 5.0), Matrix(3, 60.0)),	//Test pozytywny
		make_tuple(Matrix(2, 1.1), Matrix(2, 1.0), Matrix(2, 2.2)),		//Test negatywny
		make_tuple(Matrix(3, 2.0), Matrix(3, 1.0), Matrix(3, 6.0)),		//Test pozytywny	
		make_tuple(Matrix(3, 2.2), Matrix(3, 1.1), Matrix(3, 7.26)),	//Test negatywny
		make_tuple(Matrix(3, 3.0), Matrix(3, 1.0), Matrix(3, 9.0)),		//Test pozytywny
		make_tuple(Matrix(4, 1.2), Matrix(4, -0.5), Matrix(4, -2.4)),	//Test negatywny
		make_tuple(Matrix(3, -4.0), Matrix(3, 5.0), Matrix(3, -60.0))	//Test pozytywny
		//make_tuple(Matrix(3, 1.0), Matrix(4, 1.0), Matrix(3, 2.0))
	));

//WNIOSKI: Występuje błąd gdy w macierzy są wartości niecałkowite



//Dodawanie macierzy do macierzy
class AddMatrixToMatrixTests : public ::testing::TestWithParam<tuple<Matrix, Matrix, Matrix>> {

};

TEST_P(AddMatrixToMatrixTests, CheckAddingMatrix)
{

	Matrix A = get<0>(GetParam());
	Matrix B = get<1>(GetParam());
	Matrix expectedResult = get<2>(GetParam());
	A = A + B;
	ASSERT_TRUE(A == expectedResult);
}

INSTANTIATE_TEST_CASE_P(CheckAddingMatrix, AddMatrixToMatrixTests,
	::testing::Values(
		make_tuple(Matrix(2, 0.0), Matrix(2, 0.0), Matrix(2, 0.0)),		//Test pozytwny
		make_tuple(Matrix(2, 1.5), Matrix(2, 1.5), Matrix(2, 3.0)),		//Test pozytywny
		make_tuple(Matrix(2, 1.75), Matrix(2, 1.5), Matrix(2, 3.25)),	//Test negatywny
		make_tuple(Matrix(2, 3.0), Matrix(2, 4.0), Matrix(2, 7.0)),		//Test pozytywny
		make_tuple(Matrix(3, 5.0), Matrix(3, 7.0), Matrix(3, 12.0)),	//Test pozytywny
		make_tuple(Matrix(3, 5.1), Matrix(3, 7.2), Matrix(3, 12.3)),	//Test negatywny
		make_tuple(Matrix(3, 1.0), Matrix(4, 1.0), Matrix(3, 2.0))		//Test pozytywny
	));

//WNIOSKI: Występuje błąd gdy w dodawanych macierzach są liczby nie całkowite oraz gdy jednocześnie są rózne od siebie



//Test konstruktora, tworzenie macierzy
class ConstructorTests : public ::testing::TestWithParam<tuple<int, double>> {

};

TEST_P(ConstructorTests, CheckCreatingMatrix)
{

	int matrixShape = get<0>(GetParam());
	double initializer = get<1>(GetParam());
	Matrix A(matrixShape, initializer);
	ASSERT_TRUE((matrixShape == A.rows) && (matrixShape == A.columns)) << "shape: " << matrixShape << " " << " A.rows: " << A.rows << " A.cols: " << A.columns;
	for (int i = 0; i < matrixShape; i++) 
	{
		for (int j = 0; j < matrixShape; j++) 
		{
			ASSERT_TRUE(A(i, j) == initializer);
		}

	}
}

INSTANTIATE_TEST_CASE_P(CheckCreatingMatrix, ConstructorTests,
	::testing::Values(
		make_tuple(2, 0.0),			//Test pozytywny
		make_tuple(2, 7.2),			//Test pozytywny
		make_tuple(-5, 1.0),		//Test negatywny
		make_tuple(4, 1.2),			//Test pozytywny
		make_tuple(-3, 0.0),		//Test negatywny
		make_tuple(7, -12.0),		//Test pozytywny
		make_tuple(-1, 2.0),		//Test negatywny
		make_tuple(255, 2.0),		//Test pozytywny
		make_tuple(256, 0.0),		//Test negatywny
		make_tuple(257, 0.0)		//Test negatywny
	));

//WNIOSKI: Występuje błąd podczas wywołania konstruktora dla macierzy z ujemnym rozmiarem oraz dla macierzy z rozmiarem powyżej 255




//Wczytywanie danych do macierzy
double f(int a, int b) 
{
	int x = a;
	int y = b;
	double avg = (x + y) / 2.0;
	return avg;
}

class loadingDataToMatrixTests : public ::testing::TestWithParam<tuple<double(*)(int, int), int>> {

};

TEST_P(loadingDataToMatrixTests, CheckLoadingDataToMatrix)
{

	double(*initializer_func)(int, int) = get<0>(GetParam());
	int shape = get<1>(GetParam());
	Matrix A(shape, 0.0);
	A.load_data(initializer_func);
	for (int i = 0; i < shape; i++)
	{
		for (int j = 0; j < shape; j++) 
		{
			ASSERT_TRUE(A(i, j) == initializer_func(i, j));
		}
	}
}

INSTANTIATE_TEST_CASE_P(CheckLoadingDataToMatrix, loadingDataToMatrixTests,
	::testing::Values(
		make_tuple(f, 3),
		make_tuple(f, 7),
		make_tuple(f, 4),
		make_tuple(f, 12),
		make_tuple(f, 1)
	));

//WNIOSKI: Poprawne działanie




//Wczytywanie danych z vectora do macierzy
class loadingVecDataTests : public ::testing::TestWithParam<tuple<int, int, vector<double>, Matrix>> {

};

TEST_P(loadingVecDataTests, CheckLoadingVecData)
{

	int matrixRows = get<0>(GetParam());
	int matrixCols = get<1>(GetParam());
	vector<double> matrixData = get<2>(GetParam());
	Matrix expectedMatrix = get<3>(GetParam());
	Matrix A(matrixRows, matrixCols, 0.0);
	A.load_data(matrixData, matrixRows, matrixCols);
	ASSERT_TRUE((expectedMatrix.rows == A.rows) && (expectedMatrix.columns == A.columns));
	for (int i = 0; i < matrixRows; i++)
	{
		for (int j = 0; j < matrixCols; j++) 
		{
			ASSERT_TRUE(A(i, j) == expectedMatrix(i, j));
		}
	}
}

INSTANTIATE_TEST_CASE_P(CheckLoadingVecData, loadingVecDataTests,
	::testing::Values(
		make_tuple(2, 2, vector<double>({ 9.0, 9.0, 9.0, 9.0 }), Matrix(2, 9.0)),
		make_tuple(2, 3, vector<double>({ 2.0, 2.0, 2.0, 2.0, 2.0, 2.0 }), Matrix(2, 3, 2.0)),
		make_tuple(3, 2, vector<double>({ 4.0, 4.0, 4.0, 4.0, 4.0, 4.0 }), Matrix(3, 2, 4.0)),
		make_tuple(2, 2, vector<double>({ 5.0, 5.0, 5.0, 5.0 }), Matrix(2, 5.0)),
		make_tuple(3, 3, vector<double>({ 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0, 12.0 }), Matrix(3, 12.0)),
		make_tuple(4, 4, vector<double>({ 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0 }), Matrix(4, 3.0))
	));

//WNIOSKI: Poprawne działanie



// Sprawdzanie poprawności wyznacznika macierzy
class DeterminantMatrixTests : public ::testing::TestWithParam<tuple<Matrix, double>> {

};
TEST_P(DeterminantMatrixTests, CheckDeterminant)
{
	Matrix A = get<0>(GetParam());
	double expectedMatDeterminant = get<1>(GetParam());
	ASSERT_TRUE(A.determinant() == expectedMatDeterminant) << "A.determinant(): " << A.determinant();
}

INSTANTIATE_TEST_CASE_P(CheckDeterminant, DeterminantMatrixTests,
	::testing::Values(
		make_tuple(Matrix(1, 1.0), 1.0),	//Test negatywny
		make_tuple(Matrix(2, 1.0), 0.0),	//Test pozytywny
		make_tuple(Matrix(3, 2.0), 0.0),	//Test pozytywny
		make_tuple(Matrix(4, 1.0), 0.0),	//Test pozytywny
		make_tuple(Matrix(1, 2.0), 2.0),	//Test negatywny
		make_tuple(Matrix(1, 3.0), 3.0),	//Test negatywny
		make_tuple(Matrix(1, 5.0), 5.0)		//Test negatywny
	));

//WNIOSKI: Występuje błąd podczas obliczania wyznacznika macierzy o jednym elemencie


TEST(matrixRankTests, checkMatRank) {
	int shape1 = 1;
	int shape2 = 2;
	int shape3 = 3;

	int rowsMatrixC = 4;
	int colsMatrixC = 3;

	int rowsMatrixD = 3;
	int colsMatrixD = 2;

	vector<double> A({ 0.0, 1.0, 2.0, 3.0 });
	vector<double> B({ 0.8, 5.3, 1.2, 3.1, 4.8, 1.7, 7.3, 1.5, 2.5 });

	vector<double> C({ 0.8, 5.3, 1.2, 3.1, 4.8, 1.7, 7.3, 1.5, 2.5, 1.1, 3.3, 2.2 });
	vector<double> D({ 1.0, 3.0, 5.0, 7.0, 4.0, 2.0 });

	vector<double> E({ 5.0 });
	vector<double> F({ -7.0 });
	vector<double> G({ 1.75 });

	vector<double> X({ 1.0, 1.0, 1.0, 1.0 });
	vector<double> Y({ 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 });


	Matrix matA(shape2, A);
	Matrix matB(shape3, B);

	Matrix matD(rowsMatrixD, colsMatrixD, D);
	Matrix matC(rowsMatrixC, colsMatrixC, C);

	Matrix matE(shape1, E);
	Matrix matF(shape1, F);
	Matrix matG(shape1, G);

	Matrix matX(shape2, X);
	Matrix matY(shape3, Y);

	ASSERT_EQ(matY.rank(), 1);		//Test negatywny
	//ASSERT_EQ(matX.rank(), 1);	//Test negatywny

	//ASSERT_EQ(matA.rank(), 2);	//Test pozytywny
	//ASSERT_EQ(matB.rank(), 3);	//Test pozytywny

	//ASSERT_EQ(matC.rank(), 3);	//Test pozytywny
	//ASSERT_EQ(matD.rank(), 2);	//Test pozytywny

	//ASSERT_EQ(matE.rank(), 1);	//Test negatywny
	//ASSERT_EQ(matF.rank(), 1);	//Test negatywny
	//ASSERT_EQ(matG.rank(), 1);	//Test negatywny
}

// Test sprawdzający czy da się pomnożyć macierze przez siebie
TEST_P(MultiplicationByMatrixTests, CheckIfMatrixIsMultiplicated)
{
	Matrix A = get<0>(GetParam());
	Matrix B = get<1>(GetParam());
	Matrix expected_result = get<2>(GetParam());
	bool areMatrixesEqual = false;
	if (A.columns == B.columns && A.rows == B.rows)
	{
		areMatrixesEqual = true;
	}
	ASSERT_TRUE(areMatrixesEqual);
}

//Test czy da się dodać macierze do siebie
TEST_P(AddMatrixToMatrixTests, CheckIfMatrixIsAddingable)
{
	Matrix A = get<0>(GetParam());
	Matrix B = get<1>(GetParam());
	Matrix expected_result = get<2>(GetParam());
	bool areMatrixesEqual = false;
	if (A.columns == B.columns && A.rows == B.rows)
	{
		areMatrixesEqual = true;
	}
	ASSERT_TRUE(areMatrixesEqual);
}
