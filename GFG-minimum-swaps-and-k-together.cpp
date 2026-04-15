🚀 Minimum Swaps to Bring K Together
📌 Platform
🟢 GFG (GeeksforGeeks)
🧠 Problem Statement

Given an array arr[] and an integer k, find the minimum number of swaps required to bring all elements less than or equal to k together.

💡 Approach (Sliding Window 🔥)
✅ Key Idea:
Jo elements <= k hain → good elements
Jo elements > k hain → bad elements

👉 Goal:
Ek aisi window find karo jisme saare good elements ek saath ho aur minimum bad elements ho

⚙️ Steps:
Count total good elements (<= k) → this will be our window size
First window me count karo kitne bad elements (> k) hain
Sliding window apply karo:
Left element remove karo (agar bad hai to bad--)
Right element add karo (agar bad hai to bad++)
Minimum bad elements = minimum swaps required
🧮 Time & Space Complexity
⏱️ Time Complexity: O(n)
🧠 Space Complexity: O(1)
💻 Code (C++)
int minSwaps(vector<int>& arr, int k) {
    int n = arr.size();

    // Step 1: Count good elements
    int good = 0;
    for (int x : arr) {
        if (x <= k) good++;
    }

    // Step 2: Count bad elements in first window
    int bad = 0;
    for (int i = 0; i < good; i++) {
        if (arr[i] > k) bad++;
    }

    int ans = bad;

    // Step 3: Sliding window
    for (int i = good; i < n; i++) {

        // Remove left element
        if (arr[i - good] > k) bad--;

        // Add right element
        if (arr[i] > k) bad++;

        // Update answer
        ans = min(ans, bad);
    }

    return ans;
}
🎯 Intuition in One Line

👉 “Fix window size = number of good elements, and minimize bad elements inside it.”