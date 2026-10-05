#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<double>> multiplyMatrices(const vector<vector<double>>& first,
                                        const vector<vector<double>>& second)
{
    int row = first.size();
    int common = second.size();
    int col = second[0].size();
 
    vector<vector<double>> result(row, vector<double>(col, 0.0));
 
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < common; k++)
            {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
 
    return result;
}
 
void readMatrix(vector<vector<double>>& matrix, const string& name)
{
    cout << "\nEnter element of " << name << " matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << name << "[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix[i][j];
        }
    }
}
 
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
    int rowsFirst, colsFirst;
    int rowsSecond, colsSecond;

    cout << "Enter number of rows for first matrix: ";
    cin >> rowsFirst;

    cout << "Enter number of columns for first matrix: ";
    cin >> colsFirst;

    cout << "Enter number of rows for second matrix: ";
    cin >> rowsSecond;

    cout << "Enter number of columns for second matrix: ";
    cin >> colsSecond;

    if (rowsFirst <= 0 || colsFirst <= 0 ||
        rowsSecond <= 0 || colsSecond <= 0)
    {
        cout << "Matrix dimension must be positive." << endl;
        return 0;
    }

    if (colsFirst != rowsSecond)
    {
        cout << "Matrix multiplcation is not possible." << endl;
        return 0;
    }

    vector<vector<double>> first(rowsFirst, vector<double>(colsFirst));
    vector<vector<double>> second(rowsSecond, vector<double>(colsSecond));
 
    readMatrix(first, "first");
    readMatrix(second, "second");
 
    vector<vector<double>> result = multiplyMatrices(first, second);
 
    cout << "\nResult matrix (" << rowsFirst << "x" << colsSecond << "):" << endl;
    printMatrix(result);

    return 0;
}