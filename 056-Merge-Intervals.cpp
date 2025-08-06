// 🔹 LeetCode Problem: 56 - Merge Intervals
// 🔗 https://leetcode.com/problems/merge-intervals/
// 🧠 Level: Medium
// 📝 Tags: Sorting, Greedy, Intervals
// 💡 Approaches: In-place Merge using erase() vs Optimized Interview Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔹 Approach 1: In-place Merge using erase()
    vector<vector<int>> mergeInPlace(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0;

        while (i < intervals.size() - 1) {
            // If current interval overlaps with next one
            if (intervals[i][1] >= intervals[i + 1][0]) {
                // end time ko update kr diya merge krne ke liye 
                intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
                // ab jo interval merged hua hai use hata diya
                intervals.erase(intervals.begin() + i + 1); // ⚠️ Shifts elements
                // Don't increment i, because new i+1 needs to be checked
            } else {
                i++; // No overlap, move forward
            }
        }
        return intervals;
    }
//complexities-> [Space Optimized, Time O(n^2)].

    // 🔹 Approach 2: Optimized Interview Approach 
    vector<vector<int>> mergeOptimized(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        for (auto& interval : intervals) {
            // If result is empty or no overlap with last interval
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval); // No overlap
            } else {
                // Merge by updating end time
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};
//Complexities->[Time O(n log n), Space O(n)]