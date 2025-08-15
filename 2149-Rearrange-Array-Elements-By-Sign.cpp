// LeetCode Q #2149: Rearrange Array Elements by Sign
// Done by Devansh Pandey

// Approach 2️⃣: Using separate positive and negative arrays
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(int i : nums){
            if(i < 0) neg.push_back(i);
            else pos.push_back(i);
        }

        vector<int> ans;
        for(int i = 0; i < pos.size(); i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};
// ✅ TC: O(n)  → two passes: one for separation, one for merging
// ✅ SC: O(n)  → extra space for pos and neg arrays

// LeetCode Q #2149: Rearrange Array Elements by Sign
// Done by Devansh Pandey

// Approach 1️⃣: In-place placement using indices
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int posIndex = 0; // Positive numbers at even indices
        int negIndex = 1; // Negative numbers at odd indices
        for(int i : nums){
            if(i < 0){
                ans[negIndex] = i;
                negIndex += 2;
            } else {
                ans[posIndex] = i;
                posIndex += 2;
            }
        }
        return ans;
    }
};
// ✅ TC: O(n)  → single pass through nums
// ✅ SC: O(n)  → new array of same size
