#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMedian(vector<vector<int>> &matrix) {
    vector<int> allElements;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            allElements.push_back(matrix[i][j]);
        }
    }

    sort(allElements.begin(), allElements.end());

    int middle = allElements.size() / 2;

    return allElements[middle];
}

int main() {
    vector<vector<int>> myMatrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    int medianValue = findMedian(myMatrix);
    cout << "The median is: " << medianValue << endl;

    return 0;
}
