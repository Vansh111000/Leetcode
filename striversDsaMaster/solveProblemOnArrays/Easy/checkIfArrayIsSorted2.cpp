//link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
class Solution {
public:
    bool check(vector<int>& nums) {
        //lets check the order
        int i = 0;
        int n = nums.size();
        int breaking;
        while((i < (n-1))and(nums[i]<=nums[i+1])) i++;
        i++;
        breaking = i;
        while((i<(n-1))and(nums[i]<=nums[i+1])and(nums[i]<=nums[0]))i++;
        cout<<i;
        if(i < n)
        if(nums[i] > nums[0]) return false;
        if(i < n-1) return false;
        return true;

    }
};