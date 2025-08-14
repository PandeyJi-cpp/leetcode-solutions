//GFG:Two pair sum with 0.
#include <bits/stdc++.h>
using namespace std;

// Brute-force: Check all pairs
vector<vector<int>> zeroSumPairsBruteForce(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> pairs;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] == abs(-arr[j])) {
                // Store pair
                pairs.push_back({arr[i], arr[j]});
            }
        }
    }

    return pairs;
}

int main() {
    vector<int> arr = {2, -2, 3, -3, 4};
    
    vector<vector<int>> res = zeroSumPairsBruteForce(arr);
    cout << "Brute-force pairs:\n";
    for(auto p : res) {
        cout << "[" << p[0] << ", " << p[1] << "] ";
    }
    cout << endl;

    return 0;
}

//tc->o(n^2).
//sc->o(n).


//optimized approach
#include <bits/stdc++.h>
using namespace std;

// Optimized: Sort + two-pointer, skip duplicates
vector<vector<int>> zeroSumPairsOptimized(vector<int>& arr) {
    vector<vector<int>> pairs;
    int n = arr.size();
    
    sort(arr.begin(), arr.end()); // Sorting
    int left = 0, right = n - 1;

    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == 0) {
            pairs.push_back({arr[left], arr[right]});
            
            int l_val = arr[left], r_val = arr[right];
            while(left < right && arr[left] == l_val) left++;    // skip duplicates
            while(left < right && arr[right] == r_val) right--;  // skip duplicates
        }
        else if(sum < 0) left++;
        else right--;
    }

    return pairs;
}

int main() {
    vector<int> arr = {2, -2, 3, -3, 4};
    
    vector<vector<int>> res = zeroSumPairsOptimized(arr);
    cout << "Optimized pairs:\n";
    for(auto p : res) {
        cout << "[" << p[0] << ", " << p[1] << "] ";
    }
    cout << endl;

    return 0;
}

//tc->o(nlogn).
//sc->o(n).