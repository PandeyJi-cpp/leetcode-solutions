/*
🌟 Problem: Maximum Product Subarray
📝 Platform: LeetCode 152
💻 Language: C++
🚀 Approach: Kadane's Algorithm variation for product
   - Track both maxProduct 🔝 and minProduct 🔽 at each step
   - Swap them 🔄 if current number is negative
   - Update answer 🏆 with current maxProduct
🧪 Test Cases Checked: [2,3,-2,4], [-2,3,-4], [0,2], [-2,0,-1]
👤 Done by: Devansh Pandey
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];  // 🔝 max product ending at current index
        int minProduct = nums[0];  // 🔽 min product ending at current index
        int ans = nums[0];         // 🏆 global maximum product

        for(int i = 1; i < nums.size(); i++){  // ⚡ start from index 1
            if(nums[i] < 0){
                swap(minProduct, maxProduct);  // 🔄 swap max & min if negative
            }
            maxProduct = max(nums[i], nums[i]*maxProduct); // 🔝 update max
            minProduct = min(nums[i], nums[i]*minProduct); // 🔽 update min

            ans = max(ans, maxProduct);  // 🏆 update global max
        }

        return ans; // 🎯 final answer
    }
};
/*📊 Complexity:
   - Time: O(n)
   - Space: O(1)*/