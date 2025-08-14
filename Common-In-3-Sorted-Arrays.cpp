//brute force using three for loop.
for (int i = 0; i < n1; i++)
    for (int j = 0; j < n2; j++)
        for (int k = 0; k < n3; k++)
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
                cout << arr1[i] << " ";
//tc->0(n^3).
//sc->o(1).
//optimized approach three pointers
void commonInThreeSortedArrays(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3) {
   int i=0; int j=0; int k=0;
   while(i<n1&&j<n2&&k<n3){
    if(arr1[i]==arr2[j]==arr3[k]){
        cout<<arr[i]<<endl;
        i++;j++;k++;
    }
   else if(arr1[i]<arr2[j])i++;
    else if(arr2[j]<arr3[k])j++;
    else k++;
   }
}
//tc->o(n1+n2+n3).
//sc->o(1).