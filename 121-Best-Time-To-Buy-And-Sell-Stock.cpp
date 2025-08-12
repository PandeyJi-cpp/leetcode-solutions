// 📈 LeetCode Problem: Best Time to Buy and Sell Stock
// 🔗 Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 🏷️ Level: Easy
// 🛠️ Tags: Array, Greedy
// 💡 Approach: Ek hi pass me min price track karo aur har step pe max profit update karo.

// 📄 Problem Statement:
//   Given an array prices[] where prices[i] is the price of a stock on day i,
//   find the maximum profit you can achieve from a single buy and a single sell.

// 🧠 Idea:
//   1. Har din ka price dekhte hue, ab tak ka sabse chhota price store karo.
//   2. Current price - min price = profit nikal ke max profit update karo.
//   3. Ye sab ek hi loop me ho jaata hai → O(n) time, O(1) space.

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;  // 🏷️ Minimum price so far
    int maxProfit = 0;       // 💰 Maximum profit so far

    // 🔄 Traverse through all prices
    for (int i = 0; i < prices.size(); i++) {
        // 🔍 Update the minimum price
        minPrice = min(minPrice, prices[i]);

        // 💵 Update the maximum profit
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;  // 📤 Return the best possible profit
}

int main() {
    // 📊 Example Input
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    // 🖨️ Output the result
    cout << "Max Profit: " << maxProfit(prices) << endl; // ✅ Expected: 5
    return 0;
}

// ⏳ Complexity: O(n)
// 📦 Space: O(1)
