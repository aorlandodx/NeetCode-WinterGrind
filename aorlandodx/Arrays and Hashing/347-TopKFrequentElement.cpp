#include <iostream>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (int num : nums) {
        count[num]++;
    }

    vector<pair<int, int>> arr;
    for (const auto& p : count) {
        arr.push_back({p.second, p.first});
    }
    sort(arr.rbegin(), arr.rend());

    vector<int> res;
    for (int i = 0; i < k; ++i) {
        res.push_back(arr[i].second);
    }
    return res;
}

int main(){

    vector<int> nums = {1,2,2,3,3,3};
    int k = 2;

    topKFrequent(nums, k);
    
    return 0;
}