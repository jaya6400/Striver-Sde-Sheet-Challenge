#include <bits/stdc++.h>
using namespace std;

int findSingleElement(vector < int > & nums){
//using binary search
int lo = 0, hi = arr.size()-1;
while(lo <= hi){
    int mid = (lo+(hi-lo)/2);
    if (mid % 2 == 0) {
      if (arr[mid] != arr[mid + 1])
        hi = mid - 1;
      else
        lo = mid + 1;
    } else {
      if (arr[mid] == arr[mid + 1])
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    }
return arr[lo];
}
//using xor
// 	
//             int res = 0;
//             for (int i = 0; i < arr.size(); i++) {
//                 res = res ^ arr[i];
//             }
//             return res;
        
//using naive
//         int ans = 0;
//         if(nums.size() == 1)
//             return nums[0];
//         for(int i = 0; i < nums.size()-1; i++){
//             if(nums[i] != nums[i+1] && nums[i+1] != nums[i+2]){
//                 ans = nums[i+1];
//                 break;
//         }else{
//                 ans = nums[0];
//             }
//         }
//         return ans; 
        
 int main(){
 int n;
 cin>>n;
 int arr[n];
 for(int i = 0; i < n; i++)
 cin>>arr[i];
 cout<<singleNonDuplicate(arr);
 return 0;
 }
