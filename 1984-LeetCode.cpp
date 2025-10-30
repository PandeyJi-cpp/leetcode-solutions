/*
🚀 Platform: GFG
📝 Question: Chocolate Distribution Problem.
🔢 Question No: --
✅ Done by: Devansh Pandey
*/
class Solution {
public:
 int findMinDiff(vector<int>arr,int n){
    int n=arr.size();
    if(n==0 || m==0)return 0;
    if(m>n)return -1;
    //sorting array.
    sort(arr.begin(),arr.end());
int min_diff=INT_MAX;
for(int i=0;i+m-1<n;i++){
    int diff=arr[i+m-1]-arr[i];
    min_diff=min(diff,min_diff);
} return min_diff;
}
};
/*💻 Time Complexity: O(n log n)
🧠 Space Complexity: O(1)*/