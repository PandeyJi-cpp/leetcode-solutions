
/ 🔹 LeetCode Problem: 1 - Two Sum
// 🔗 https://leetcode.com/problems/two-sum/
// 🧠 Difficulty: Easy
// 📝 Tags: Array, Hash Table
// 💡 Approach: Hash Map (One-pass)
// 👨‍💻 Solution by: Devansh

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>ans;
       for(int j=0;j<nums.size();j++){
        for(int i=j+1;i<nums.size();i++){
            if(nums[j]+nums[i]==target){
ans.push_back(j);
                ans.push_back(i);
            }
        }
       }return ans;
    }
};

/*
Time-Complexity->O(n^2);
space-complexity->O(n);
*/