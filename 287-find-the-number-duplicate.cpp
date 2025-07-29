// 🔹 LeetCode Problem: 287 - Find the Duplicate Number
// 🔗 https://leetcode.com/problems/find-the-duplicate-number/
// 🧠 Approach: Modify array using sign marking
// 📝 Tags: Array, Cycle Detection, In-place, Duplicate
// 📌 Note: This approach modifies the input array

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            // Absolute value ye isliye li hai kyunki hum ise as a index use krenge aur index negative nhi ho skta.
            int num = abs(nums[i]);

            // agar value already negative hai iska matlab hai value already visited hai aur ye uska duplicate hai.
            if (nums[num] < 0) {
                return num;
            } else {
                // Otherwise, mark this index as visited uski value ko negative krke
                nums[num] = -nums[num];
            }
        }

        // If no duplicate is found (ideally should not happen as per problem guarantee)
        return -1;
    }
};

// ✅ Time Complexity: O(n)
// ✅ Space Complexity: O(1)
// ⚠️ Note: This approach modifies the input array