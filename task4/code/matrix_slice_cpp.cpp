#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<double>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << "\t";
        }

        cout << endl;
    }
}

int main()
{
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0)
    {
        cout << "Matrix dimensions must be positive." << endl;
        return 0;
    }

    vector<vector<double>> matrix(rows, vector<double>(cols));

    cout << "Enter matrix elements:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int rowStart, rowEnd;
    int colStart, colEnd;

    cout << "Enter starting row index: ";
    cin >> rowStart;

    cout << "Enter ending row index: ";
    cin >> rowEnd;

    cout << "Enter starting column index: ";
    cin >> colStart;

    cout << "Enter ending column index: ";
    cin >> colEnd;

    if (rowStart < 0 || rowEnd > rows ||
        colStart < 0 || colEnd > cols ||
        rowStart >= rowEnd ||
        colStart >= colEnd)
    {
        cout << "Invalid slice boundaries." << endl;
        return 0;
    }

    vector<vector<double>> slicedMatrix;

    for (int i = rowStart; i < rowEnd; i++)
    {
        vector<double> row;

        for (int j = colStart; j < colEnd; j++)
        {
            row.push_back(matrix[i][j]);
        }

        slicedMatrix.push_back(row);
    }

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    cout << "Sliced matrix:" << endl;
    printMatrix(slicedMatrix);

    return 0;
}