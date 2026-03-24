// 209. Minimum Size Subarray Sum
// Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
  int left=0;
  int right=0;
  int sum=0;
        int minLen=INT_MAX;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>=target){
                minLen=min(minLen,right-left+1);
                sum-=nums[left];//first value ko minus krdiya window ki taaki window slide ho jae by one 
                left++;
            }}
            return (minLen==INT_MAX)? 0:minLen;
        }
};
⏱ Complexity
🕒 Time: O(n)
🧠 Space: O(1)