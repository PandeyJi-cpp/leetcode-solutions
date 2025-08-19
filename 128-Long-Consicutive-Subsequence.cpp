/*
🌟 Problem: Longest Consecutive Subsequence
📝 Platform: LeetCode 128
💻 Language: C++
🚀 Approach: 
   - Sort the array first 🔹
   - Traverse the array linearly
   - Count consecutive numbers ✅
   - Skip duplicates ⚡
   -Update longest streak 🏆
🧪 Test Cases Checked: [100,4,200,1,3,2], [1,2,2,3,4], [0], []
👤 Done by: Devansh Pandey
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
              if(nums.empty()) return 0;

    sort(nums.begin(), nums.end()); // sort array
    int longest = 1;
    int count = 1;

    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i+1] == nums[i]) continue;        // skip duplicates
        else if(nums[i+1] == nums[i] + 1) count++; // consecutive
        else count = 1;                           // reset streak

        longest = max(longest, count);
    }

    return longest;
    }
};
/*📊 Complexity:
   - Time: O(n log n)  (sorting)
   - Space: O(1)*/