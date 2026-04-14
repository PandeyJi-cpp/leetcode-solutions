🚀 Three Way Partitioning (Range Based)
📌 Problem

Given an array and two values a and b,
rearrange the array such that:

Elements less than a come first
Elements in range [a, b] come next
Elements greater than b come last

👉 Order inside groups matter nahi karta, bas grouping sahi honi chahiye.

💡 Approach (Vector / Bucket Method)
3 vectors use kiye:
v1 → elements < a
v2 → elements [a, b]
v3 → elements > b
Pehle array traverse karke elements ko correct bucket me daal diya
Phir sabko merge karke original array me daal diya
💻 Code (C++)
class Solution {
public:
    void threeWayPartition(vector<int>& arr, int a, int b) {
        
        vector<int> v1, v2, v3;

        // Step 1: Divide into 3 groups
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < a) {
                v1.push_back(arr[i]);
            }
            else if (arr[i] >= a && arr[i] <= b) {
                v2.push_back(arr[i]);
            }
            else {
                v3.push_back(arr[i]);
            }
        }

        // Step 2: Merge back into original array
        int i = 0;

        for (int x : v1) {
            arr[i++] = x;
        }
        for (int x : v2) {
            arr[i++] = x;
        }
        for (int x : v3) {
            arr[i++] = x;
        }
    }
};
⏱️ Time Complexity
Traversing array: O(n)
Merging back: O(n)

👉 Total TC = O(n) ⚡

💾 Space Complexity
Extra vectors used (v1, v2, v3)

👉 SC = O(n) 🧠

🔥 Key Insight

“Divide elements into 3 buckets based on condition and then merge them back.”

//Second Approach (In Place - DNF Algorithm)

🚀 Three Way Partitioning (Dutch National Flag - In Place)
📌 Problem

Given an array and two values a and b, rearrange the array such that:

Elements < a come first
Elements in range [a, b] come next
Elements > b come last

👉 In-place karna hai (no extra space)

💡 Approach (DNF Algorithm ⚔️)

We use 3 pointers:

left → boundary of < a
mid → current element
right → boundary of > b
🎯 Idea:
< a → left side push
> b → right side push
[a, b] → beech me rehne do
💻 Code (C++)
class Solution {
public:
    void threeWayPartition(vector<int>& arr, int a, int b) {
        
        int left = 0;
        int mid = 0;
        int right = arr.size() - 1;

        while (mid <= right) {

            // Case 1: Element < a → left side
            if (arr[mid] < a) {
                swap(arr[left], arr[mid]);
                left++;
                mid++;
            }

            // Case 2: Element in range [a, b] → middle
            else if (arr[mid] >= a && arr[mid] <= b) {
                mid++;
            }

            // Case 3: Element > b → right side
            else {
                swap(arr[mid], arr[right]);
                right--;
                // mid stays here
            }
        }
    }
};
⏱️ Time Complexity

👉 O(n) ⚡

Single pass through array
💾 Space Complexity

👉 O(1) 🧠

No extra space used (in-place)
🔥 Key Insight

“Push elements into their correct zone using 3 pointers in one pass.”