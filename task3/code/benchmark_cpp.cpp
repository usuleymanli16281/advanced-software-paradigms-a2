#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<vector<double>> multiplyMatrices(const vector<vector<double>>& first,
                                        const vector<vector<double>>& second)
{
    int rows = first.size();
    int common = second.size();
    int cols = second[0].size();

    vector<vector<double>> result(rows, vector<double>(cols, 0.0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = 0; k < common; k++)
            {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    return result;
}

int main()
{
    vector<int> sizes = {100, 300, 500};
    int runs = 20;

    for (int size : sizes)
    {
        vector<vector<double>> first(size, vector<double>(size, 1.0));
        vector<vector<double>> second(size, vector<double>(size, 1.0));

        multiplyMatrices(first, second);

        double totalTime = 0;

        for (int i = 0; i < runs; i++)
        {
            auto start = chrono::high_resolution_clock::now();

            vector<vector<double>> result =
                multiplyMatrices(first, second);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double> elapsed = end - start;
            totalTime += elapsed.count();
        }

        double averageTime = totalTime / runs;

        cout << size << "x" << size
             << ": " << averageTime
             << " seconds" << endl;
    }

    return 0;
}