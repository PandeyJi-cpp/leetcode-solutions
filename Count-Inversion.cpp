// 🔥 LeetCode/GFG Problem: Count Inversions in an Array
// 🌐 GFG Link: https://practice.geeksforgeeks.org/problems/inversion-of-array
// 🎯 Level: Easy-Medium
// 🏷 Tags: Array, Brute Force
// 💡 Approach: Har element ke liye uske baad wale sab se compare karo, agar bada hai to inversion++

// 📌 Problem Statement:
//   Given an array, count the number of inversions.
//   Inversion: Pair (i, j) such that i < j and arr[i] > arr[j]

#include <bits/stdc++.h>
using namespace std;

int main() {
    // 📝 Example for dry run.
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();
    int count = 0;

    // 🔄 Brute force: Har i ke liye baaki sab j check karo
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // ✅ Agar inversion condition match ho gayi
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }

    // 📤 Output
    cout << "Number of inversions: " << count << endl;

    return 0;
}

// ⏳ Complexity: O(n^2)
// 📦 Space: O(1)
