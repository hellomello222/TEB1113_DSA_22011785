#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int getMaxRectangleInHistogram(vector<int>& heights) {
    stack<int> indexStack;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i < n; i++) {
        while (!indexStack.empty() && heights[indexStack.top()] >= heights[i]) {
            int topIndex = indexStack.top();
            indexStack.pop();

            int width;
            if (indexStack.empty()) {
                width = i;
            } else {
                width = i - indexStack.top() - 1;
            }

            int area = heights[topIndex] * width;
            maxArea = max(maxArea, area);
        }

        indexStack.push(i);
    }

    while (!indexStack.empty()) {
        int topIndex = indexStack.top();
        indexStack.pop();

        int width;
        if (indexStack.empty()) {
            width = n;
        } else {
            width = n - indexStack.top() - 1;
        }

        int area = heights[topIndex] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int getMaxRectangleArea(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> histogram(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                histogram[j] += 1;
            } else {
                histogram[j] = 0;
            }
        }

        int area = getMaxRectangleInHistogram(histogram);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<vector<int>> binaryMatrix = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    int result = getMaxRectangleArea(binaryMatrix);
    cout << "The maximum rectangle area of 1s is: " << result << endl;

    return 0;
}
