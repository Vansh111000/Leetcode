/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp(nums.size());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            tmp[(i+k)%n]= nums[i];
        }
        for(int i = 0 ; i<n;i++) nums[i]=tmp[i];
    }
};
// @lc code=end

