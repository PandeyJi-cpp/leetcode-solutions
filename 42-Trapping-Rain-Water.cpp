// 🌟 LeetCode 3Sum
// 📌 Problem No: 15
// 🖥 Platform: LeetCode
// 🔹 Question: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
//   such that i != j != k and nums[i] + nums[j] + nums[k] == 0.
// 🔹 Constraints: nums.length <= 3000, -10^5 <= nums[i] <= 10^5
// 💡 Approach: Sort + Two Pointers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end()); // 🔹 Step 1: Sort array

        for(int i = 0; i < n-2; i++) { // 🔹 i < n-2 for triplet
            if(i > 0 && nums[i] == nums[i-1]) continue; // 🔹 Skip duplicate 'i'

            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});

                    // 🔹 Skip duplicates for left and right
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                }
                else if(sum < 0) left++;  // 🔹 Need bigger sum
                else right--;              // 🔹 Need smaller sum
            }
        }
        return res;
    }
};

/* 
⏱ Time Complexity: O(n^2)
📐 Space Complexity: O(1) extra (excluding result)
*/