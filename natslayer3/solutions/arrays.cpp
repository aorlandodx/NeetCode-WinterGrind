/*
217. Contains Duplicate S

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i<n; i++){
            if (i != n-1){
                if (nums[i] == nums[i+1]){
                    return true;
                }
            }
        }
        return false;
    }
};

/* 
242. Valid Anagram S

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t){
            return true;
        }
        else {
            return false;
        }
    }
};

/*
1. Two Sum S
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        bool stop = false;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (i != n-1){
                int search = target - nums[i];
                for (int j = 0; j < n; j++){
                    if (j != i){
                        if (nums[j] == search){
                            ans.push_back(i);
                            ans.push_back(j);
                            stop = true;
                            break;
                        }
                    }
                }
            }
            if (stop){
                break;
            }
        }
       return ans; 
    }
};

/*
49. Group Anagrams M 

Given an array of strings strs, group the anagrams together. You can return the answer in any order.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for (const auto &s : strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            ans[sortedS].push_back(s);
        }
        vector<vector<string>> results;
        for (auto &pair : ans){
            results.push_back(pair.second);
        }
        return results;
    }
};

/*
347. Top K Frequent Elements M 

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> counts;
        for (int i = 0; i < nums.size(); i++){
            counts[nums[i]].push_back(nums[i]);
        }
        vector<pair<int, vector<int>>> elementos;
        for (auto & pair : counts){
            elementos.push_back(pair);
        }

        sort(elementos.begin(), elementos.end(), 
            [](const auto& a, const auto& b) {
            return a.second.size() > b.second.size();
        });

        /*
        for (int i = 0; i < elementos.size(); i++){
            cout << elementos[i].first << " ";
            for (int x : elementos[i].second) {
                cout << x << " ";
            }
            cout << endl;
        }
        */

        vector<int> ans;
        for (int i = 0; i < k; i++){
            ans.push_back(elementos[i].first);
        }

        return ans;
    }
};

/*
238. Product of Array Except Self M

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int countZ = 0;
        vector<int> answer(n, 0);
        int prod = 1;

        for (int i = 0; i < n; i++){
            if (nums[i] != 0){
                prod = prod*nums[i];
            }
            else {
                countZ++;
            }
        }

        if (countZ > 1){
            return answer;
        }

        for (int i = 0; i < n; i++){
            if (countZ > 0) {
                answer[i] = (nums[i] == 0) ? prod : 0;
            }
            else{
                answer[i] = prod / nums[i];
            }
        }
        return answer;   
    }
};

/*

        if (nums[0] == '0'){
            countZ++;
        }

        for (int i = 1; i < n; i++){
            if (nums[i] == '0'){
                countZ++;
                int pos = i;
            }
            prefixM[i] = prefixM[i-1] * nums[i];




            if (countZ >= '2'){
                bool zer = true; 
            }
        }

        for (int i = 0; i < n; i++){
            answer[i] = prefixM[n-1] / prefixM[i];
        }
        */




