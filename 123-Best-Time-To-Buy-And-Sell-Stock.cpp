/*
🔢 Problem: Majority Element II
📌 Platform: LeetCode 229
💻 Language: C++

-----------------------------------------------------
👶 Approach 1: Brute Force
-----------------------------------------------------
📝 Steps:
1️⃣ Har element ka frequency count karo (nested loop).
2️⃣ Agar freq > n/3 hai → answer me daal do.
3️⃣ Duplicate avoid karne ke liye `find()` use karo.
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) count++;
            }

            if (count > n / 3) {
                // ✅ Duplicate avoid
                if (find(ans.begin(), ans.end(), nums[i]) == ans.end()) {
                    ans.push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};
/*
⏱️ Time Complexity: O(n^2)
💾 Space Complexity: O(1)
*/


/*
-----------------------------------------------------
⚡ Approach 2: Better (Hash Map / Frequency Count)
-----------------------------------------------------
📝 Steps:
1️⃣ Har element ka frequency map me store karo.
2️⃣ Agar freq > n/3 hai → answer me daal do.
*/

class Solution2 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> freq;
        int n = nums.size();

        // 📊 Count frequencies
        for (int num : nums) freq[num]++;

        // ✅ Collect elements > n/3
        for (auto it : freq) {
            if (it.second > n / 3) ans.push_back(it.first);
        }

        return ans;
    }
};
/*
⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)
*/