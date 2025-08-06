// ✅ LeetCode 53: Maximum Subarray
// 🔗 https://leetcode.com/problems/maximum-subarray/
// 📌 Kadane's Algorithm (Dynamic Programming)
// 👨‍💻 Solved by: [Devansh Pandey]

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
// 💡 Time: O(n), Space: O(1)