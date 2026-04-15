🚀 Minimum Swaps to Group All 1's Together II (Circular)
📌 Problem

👉 Minimum Swaps to Group All 1's Together II

Given a circular binary array, find the minimum swaps required to group all 1’s together.

💡 Approach (Sliding Window + Circular ⚔️)
🧠 Key Idea:
Count total number of 1’s → this will be our window size
Use a sliding window of size = ones
Count number of 0’s (bad elements) in each window
Minimum 0’s = minimum swaps required
🔄 Circular Trick

👉 Since array is circular:

Traverse till n + ones
Use i % n to wrap around
💻 Code (C++)
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();

        // Step 1: Count total 1's
        int ones = 0;
        for (int x : nums) {
            if (x == 1) ones++;
        }

        // Edge case: no 1's
        if (ones == 0) return 0;

        // Step 2: First window
        int currZero = 0;
        for (int i = 0; i < ones; i++) {
            if (nums[i] == 0) currZero++;
        }

        int ans = currZero;

        // Step 3: Sliding window (circular)
        for (int i = ones; i < n + ones; i++) {

            // Remove left element
            if (nums[i - ones] == 0) currZero--;

            // Add new element (circular index)
            if (nums[i % n] == 0) currZero++;

            ans = min(ans, currZero);
        }

        return ans;
    }
};

/*
How to slide window.                                                                                                     ---   
decrease size from strting and increase size in ending.                                                                    |---->THESE ARE SOME KEY CONCEPTS OF SLIDING WINDOW TRICK.
=>remove element in left if(nums[i-window_size]==bad element) bad_element_count--;                                         |
=>add element in right if(nums[i]==bad element)bad_element_count++; || if array is circular then here index would be i%n.---
*/
⏱️ Time Complexity

👉 O(n) ⚡

Single pass sliding window
💾 Space Complexity

👉 O(1) 🧠

No extra space used
🔥 Key Insight

“Best window wo hai jisme sabse kam 0’s ho — wahi minimum swaps hai”
