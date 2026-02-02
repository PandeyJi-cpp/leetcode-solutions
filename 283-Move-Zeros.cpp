🚀 Approach (Three Pointer Technique)

We maintain three pointers:

low → position for next 0

mid → current element

high → position for next 2

🧠 Logic

0 → swap with low, move low & mid

1 → just move mid

2 → swap with high, move high

✅ C++ Implementation
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

⏱️ Complexity Analysis

Time Complexity: O(n) ⚡

Space Complexity: O(1) 🧠 (In-place)