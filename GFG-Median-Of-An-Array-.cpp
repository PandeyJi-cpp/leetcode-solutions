bool isPalindrome(arr){
    string s=to_string(arr);
int j=0;
int k=s.size()-1;
while(j<k){
    if(s[j]!=s[k]){
        return false;
    }
}return true;
}

bool PalindromicArray(vector<int>&arr){
int n=arr.size();
for(int i=0;i<n;i++){
    if(!isPalindrome(arr[i])){
        return false;
    }
}return true;
}🚀 Palindromic Array
📌 Platform
🟢 GFG (GeeksforGeeks)
🧠 Problem Statement

Given an array arr[], check whether all elements of the array are palindrome numbers or not.
Return true if all are palindrome, otherwise false.

💡 Approach
✅ Key Idea:
Har element ko string me convert karo
Do pointers (left, right) use karke check karo palindrome hai ya nahi
Agar koi bhi element palindrome nahi hai → return false
⚙️ Steps:
Traverse the array
Har element ke liye:
Convert to string using to_string()
Check palindrome using two pointers
Agar sab palindrome hain → return true
🧮 Time & Space Complexity
⏱️ Time Complexity: O(n × d)
(n = elements, d = digits in number)
🧠 Space Complexity: O(d) (string conversion)
💻 Code (C++)
bool isPalindrome(int num) {
    string s = to_string(num);
    
    int j = 0;
    int k = s.size() - 1;

    while (j < k) {
        if (s[j] != s[k]) {
            return false;
        }
        j++;
        k--; // ❗ important (warna infinite loop ho jaega)
    }
    return true;
}

bool PalindromicArray(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (!isPalindrome(arr[i])) {
            return false;
        }
    }
    return true;
}
⚠️ Common Mistakes
❌ to_string(arr) → galat (array/vector pe nahi lagta)
❌ j++ ya k-- bhool jana → infinite loop 💀
🎯 Intuition in One Line

👉 “Har element ko individually palindrome check karo; ek bhi fail hua to answer false.”