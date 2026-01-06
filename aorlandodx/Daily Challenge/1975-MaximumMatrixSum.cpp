#include <iostream>
using namespace std;


long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long totalSum = 0;
    int minAbsVal = INT_MAX;
    int negativeCount = 0;

    for (const auto& row : matrix){
        for (int val : row){
            totalSum += abs(val);
            if (val < 0){
                negativeCount++;
            }
            minAbsVal = min(minAbsVal, abs(val));
        }
    }
    if (negativeCount % 2 != 0){
        totalSum -= 2LL * minAbsVal;
    }
    return totalSum;
}

int main(){

    vector<vector<int>> matrix = {{1,-1},{-1,1}};
    cout << maxMatrixSum(matrix) << endl;

    return 0;
}