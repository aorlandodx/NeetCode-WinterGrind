#include <iostream>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
}


int main(){

    vector<int> vector = {1, 2, 3};
    cout << containsDuplicate(vector) << endl;

    return 0;
}