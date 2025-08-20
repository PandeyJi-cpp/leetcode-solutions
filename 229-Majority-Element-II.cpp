/*
🌟 Problem: Majority Element II (Elements appearing > n/3 times)
📌 Platform: LeetCode 229
💻 Language: C++
🚀 Approach:
   1. Count frequency of each element using nested loops
   2. Add element to answer if frequency > n/3
   3. Avoid duplicates using find()
👨‍💻 Done by: Devansh Pandey
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
                // Avoid duplicates
                if (find(ans.begin(), ans.end(), nums[i]) == ans.end()) {
                    ans.push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};
/*⚠️ Time Complexity: O(n^2)
⚠️ Space Complexity: O(1)*/

/*
🌟 Problem: Majority Element II (Elements appearing > n/3 times)
📌 Platform: LeetCode 229
💻 Language: C++
🚀 Approach:
   1. Use Boyer-Moore Voting Algorithm for 2 candidates
   2. First pass: find potential candidates
   3. Second pass: verify candidates
👨‍💻 Done by: Devansh Pandey
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = -1, cand2 = -1, cnt1 = 0, cnt2 = 0;

        // 1️⃣ Find potential candidates
        for (int num : nums) {
            if (num == cand1) cnt1++;
            else if (num == cand2) cnt2++;
            else if (cnt1 == 0) { cand1 = num; cnt1 = 1; }
            else if (cnt2 == 0) { cand2 = num; cnt2 = 1; }
            else { cnt1--; cnt2--; }
        }

        // 2️⃣ Verify candidates
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == cand1) cnt1++;
            else if (num == cand2) cnt2++;
        }

        vector<int> ans;
        if (cnt1 > nums.size() / 3) ans.push_back(cand1);
        if (cnt2 > nums.size() / 3) ans.push_back(cand2);

        return ans;
    }
};

/*✅ Time Complexity: O(n)
✅ Space Complexity: O(1)*/