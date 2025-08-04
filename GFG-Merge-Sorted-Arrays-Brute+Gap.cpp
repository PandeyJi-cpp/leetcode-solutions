// 🔹 GFG Problem: Merge Two Sorted Arrays Without Extra Space
// 🔗 https://www.geeksforgeeks.org/merge-two-sorted-arrays-without-using-extra-space/
// 🧠 Tags: Array, In-Place, Two-Pointer, Sorting, Gap Method
// 📌 Note: These approaches modify the input arrays

// ------------------------------------------------------------
// ✅ Approach 1: Brute Force
// 💡 Idea: Compare each arr2[i] with arr1[j], swap if needed
// 🔄 After every swap, re-sort arr2 to keep it sorted
// ⏱️ Time Complexity: O(n * m + m log m)
// 🧠 Space Complexity: O(1)
// ⚠️ Slower, but intuitive and helps build understanding
// ------------------------------------------------------------

#include <iostream>
#include <algorithm> // for sort
using namespace std;

void mergeBrute(int arr1[], int n, int arr2[], int m){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr2[i] < arr1[j]){
                swap(arr1[j], arr2[i]);
                break;
            }
        }
    }
    sort(arr2, arr2 + m); // maintain sorted order in arr2
}

// ------------------------------------------------------------
// ✅ Approach 2: Optimized - Gap Method (Shell Sort Inspired)
// 💡 Idea: Virtually treat both arrays as one, and compare elements with a gap
// 🔁 Shrink the gap each iteration using ceil(gap / 2)
// ⏱️ Time Complexity: O((n + m) * log(n + m))
// 🧠 Space Complexity: O(1)
// ✅ Efficient and clean solution
// ------------------------------------------------------------

int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);  // Equivalent to ceil(gap / 2.0)
}

void mergeGap(int arr1[], int arr2[], int n, int m) {
    int gap = nextGap(n + m);

    while (gap > 0) {
        int i = 0, j = gap;

        while (j < (n + m)) {
            int val1, val2;

            // Mapping i and j to correct array
            if (i < n) val1 = arr1[i];
            else val1 = arr2[i - n];

            if (j < n) val2 = arr1[j];
            else val2 = arr2[j - n];

            // Compare and swap if needed
            if (val1 > val2) {
                if (i < n && j < n) swap(arr1[i], arr1[j]);
                else if (i < n && j >= n) swap(arr1[i], arr2[j - n]);
                else swap(arr2[i - n], arr2[j - n]);
            }

            i++;
            j++;
        }

        gap = nextGap(gap);
    }
}

// ------------------------------------------------------------
// 🔸 Utility Function
// ------------------------------------------------------------
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

// ------------------------------------------------------------
// 🔸 Driver Code to Test Both Approaches
// ------------------------------------------------------------
int main() {
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    // Uncomment to test brute force version
    // mergeBrute(arr1, n, arr2, m);

    // ✅ Optimized version
    mergeGap(arr1, arr2, n, m);

    cout << "Merged arr1: ";
    printArray(arr1, n);
    cout << "Merged arr2: ";
    printArray(arr2, m);

    return 0;
}
