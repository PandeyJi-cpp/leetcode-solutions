// 🚀 LeetCode Problem: 31 - Next Permutation
// 🔗 https://leetcode.com/problems/next-permutation/
// 📈 Level: Medium
// 🏷️ Tags: Array, Two Pointers
// 💡 Approaches: Find dip + Just greater swap + Reverse tail

class Solution {
public:
    // 🌟 Approach: Find 'dip', swap with just greater, reverse remaining
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2; // bocz nhi to i+1 kroge to array se bahar nikal jaega.

        // dip find karo
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // agar dip mili
        if (i >= 0) {
            int j = n - 1;
            // just bada dhoondo i se
            while (nums[i] >= nums[j]) {
                j--;
            }
            // mil gaya to swap krdo kyunki just bada hi i position pe daalna hai na
            swap(nums[i], nums[j]);
        }

        // bache hue ko reverse krdo kyunki swap ke baad bacha hua descending order main aa jata hai
        // to longest jump lag jaegi agli hume choti chahiye is wajah se hum ise reverse kr dete hain
        reverse(nums.begin() + i + 1, nums.end());
    }
};

// 🕒 Complexity: O(n)
// 📦 Space: O(1)
