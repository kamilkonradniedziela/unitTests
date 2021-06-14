#include "pch.h"

TEST(Rank, CheckRankInitializerFunc) {
	int width = 5, height = 5;
	Matrix A(height, width, [](int i, int j) {return (double)i; });
	ASSERT_EQ(A.rank(), 1);
}
