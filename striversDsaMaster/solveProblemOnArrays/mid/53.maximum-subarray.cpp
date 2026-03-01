/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i],(nums[i]+dp[i-1]));
        }

        int m = dp[0];
        for(int i = 1; i < nums.size(); i++){
            if(dp[i]>m) m = dp[i];
        }

        return m;
    }
};
// @lc code=end

