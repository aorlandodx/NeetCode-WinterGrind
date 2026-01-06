/*
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

#include <vector>
#include <algorithm>
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
242. Valid Anagram

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
1. Two Sum
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