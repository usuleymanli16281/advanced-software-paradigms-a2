#include <cassert>
#include <iostream>

#define main matrixProgramMain
#include "matrix_cpp.cpp"
#undef main

using namespace std;

void testRectangularMatrices()
{
    vector<vector<double>> first = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<double>> second = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    vector<vector<double>> expected = {
        {58, 64},
        {139, 154}
    };

    assert(multiplyMatrices(first, second) == expected);

    cout << "Rectangular matrix test passed." << endl;
}

void testNegativeAndDecimalValues()
{
    vector<vector<double>> first = {
        {1.5, -2},
        {0.5, 4}
    };

    vector<vector<double>> second = {
        {2, 1},
        {-1, 0.5}
    };

    vector<vector<double>> expected = {
        {5, 0.5},
        {-3, 2.5}
    };

    assert(multiplyMatrices(first, second) == expected);

    cout << "Negative and decimal values test passed." << endl;
}

void testIdentityMatrix()
{
    vector<vector<double>> first = {
        {2, 4, 6},
        {1, 3, 5},
        {7, 8, 9}
    };

    vector<vector<double>> identity = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    assert(multiplyMatrices(first, identity) == first);

    cout << "Identity matrix test passed." << endl;
}

int main()
{
    testRectangularMatrices();
    testNegativeAndDecimalValues();
    testIdentityMatrix();

    cout << "All tests passed." << endl;

    return 0;
}