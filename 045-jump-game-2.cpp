// 🔹 LeetCode Problem: 45 - Jump Game II
// 🔗 https://leetcode.com/problems/jump-game-ii/
// 🧠 Difficulty: Medium
// 📝 Tags: Array, Greedy
// 💡 Approach: Greedy with Lookahead (Max Forward Reach)
// 👨‍💻 Solution by: Devansh

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        // If array has 0 or 1 elements, no jump needed
        if (n <= 1) return 0;

        int count = 0; // Number of jumps taken
        int i = 0;     // Current index

        while (i < n - 1) {
            // If we can reach the end directly from here
            if (i + nums[i] >= n - 1)
                return count + 1;

            int maxReach = -1;  // Best reach from current jump options
            int index = i;      // Index to jump to next

            // Explore all positions reachable from current position
            for (int j = 1; j <= nums[i]; j++) {
                int pos = i + j;

                // Pick the one which gives the farthest reach in future
                if (pos < n && pos + nums[pos] > maxReach) {
                    maxReach = pos + nums[pos];
                    index = pos;
                }
            }

            // If no forward move is possible, return -1 (though not needed here)
            if (index == i) return -1;

            i = index;   // Jump to chosen position
            count++;     // Increase jump count
        }

        return count;
    }
};

/*
🕒 Time-Complexity: O(n^2) in worst-case (if nums[i] = 1 for all)
💾 Space-Complexity: O(1) (No extra space used)
📌 Status: ✅ Accepted on LeetCode — 0ms Runtime, 99.98% Memory
*/
