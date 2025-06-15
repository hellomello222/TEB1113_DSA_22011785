#include <iostream>
#include <vector>
using namespace std;

void multiplyMatrices(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, vector<vector<int>> &result) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    if (cols1 != rows2) {
        cout << "Matrix multiplication is not possible (columns of first != rows of second)." << endl;
        return;
    }

    result.resize(rows1, vector<int>(cols2, 0));

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix1 = {
        {1, 1},
        {2, 2}
    };

    vector<vector<int>> matrix2 = {
        {1, 1},
        {2, 2}
    };

    vector<vector<int>> result;

    multiplyMatrices(matrix1, matrix2, result);

    cout << "Result of matrix multiplication:\n";
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
