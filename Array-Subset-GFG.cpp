#include <bits/stdc++.h>
using namespace std;

/*
📝 Problem: Check if array b is a subset of array a

💡 Approaches:
1️⃣ Brute Force
2️⃣ Sorting + Two Pointers
3️⃣ String + Find Operator

*/

//==============================
// 1️⃣ Brute Force Approach
//==============================
bool isSubset_BruteForce(vector<int>& a, vector<int>& b) {
    // ⏱️ Time Complexity: O(m * n)
    // 💾 Space Complexity: O(1)
    for(int x : b){                 // 🔄 For each element in b
        bool found = false;         // 🔍 Element found flag
        for(int y : a){             // 🔄 Check in array a
            if(x == y){             // ✅ Match found
                found = true;
                break;              // ⏩ Go to next element of b
            }
        }
        if(!found) return false;    // ❌ Element missing
    }
    return true;                    // ✅ All elements present
}
/*
| Case         | Time Complexity | Space Complexity |
| ------------ | --------------- | ---------------- |
| Average Case | O(m \* n)       | O(1)             |
| Worst Case   | O(m \* n)       | O(1)             |
*/
//==============================
// 2️⃣ Sorting + Two Pointers
//==============================
bool isSubset_SortPointers(vector<int>& a, vector<int>& b) {
    // ⏱️ Time Complexity: O(m log m + n log n)
    // 💾 Space Complexity: O(1)
    sort(a.begin(), a.end());       // 🔄 Sort array a
    sort(b.begin(), b.end());       // 🔄 Sort array b

    int i = 0, j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]) i++;       // ⏩ Move in a
        else if(a[i] == b[j]) {    // ✅ Match found
            i++; j++;
        } else {                    // ❌ b[j] not found
            return false;
        }
    }
    return (j == b.size());         // ✅ All b elements matched
}
/*
| Case         | Time Complexity               | Space Complexity |
| ------------ | ----------------------------- | ---------------- |
| Average Case | O(m log m + n log n) + O(m+n) | O(1)             |
| Worst Case   | O(m log m + n log n) + O(m+n) | O(1)             |
*/
//==============================
// 3️⃣ String + Find Operator
//==============================
bool isSubset_String(vector<int>& a, vector<int>& b) {
    // ⏱️ Time Complexity: O(m * n) (string find)
    // 💾 Space Complexity: O(m)
    string str = ",";               // ➕ Delimiter to avoid confusion (1 vs 11)
    for(int x : a){
        str += to_string(x) + ",";
    }

    for(int y : b){
        string token = "," + to_string(y) + ",";
        if(str.find(token) == string::npos){ // ❌ Element missing
            return false;
        }
    }
    return true;                    // ✅ All elements present
}
/*
| Case         | Time Complexity | Space Complexity |
| ------------ | --------------- | ---------------- |
| Average Case | O(m \* n)       | O(m)             |
| Worst Case   | O(m \* n)       | O(m)             |
*/
//==============================
// Main Function
//==============================
int main() {
    vector<int> a = {11, 1, 13, 21, 3, 7};
    vector<int> b = {11, 3, 7, 1};

    cout << "Brute Force: " 
         << (isSubset_BruteForce(a, b) ? "Yes ✅" : "No ❌") << endl;

    cout << "Sort + Pointers: " 
         << (isSubset_SortPointers(a, b) ? "Yes ✅" : "No ❌") << endl;

    cout << "String + Find: " 
         << (isSubset_String(a, b) ? "Yes ✅" : "No ❌") << endl;
}
