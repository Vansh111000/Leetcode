// 26. Remove Duplicates from Sorted Array
/* Solved
Easy

Topics
premium lock icon
Companies

Hint
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored. */

class Solution {

public:
    int removeDuplicates(vector<int>& nums) {
     vector<int> temp;
        int left = 0;
        int right = nums.size() ;
        // temp = new vector<int>;
        while(left < right){
            temp.emplace_back(nums[left]);
            while(((left+1) < right)and(nums[left] == nums[left+1])) left++;
            left++;
        }
        // nums = temp;
        nums.clear();
        for(auto i : temp) nums.emplace_back(i);
        return temp.size();
    }
};