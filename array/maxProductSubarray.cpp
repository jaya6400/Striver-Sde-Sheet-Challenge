#include <bits/stdc++.h> 

//using kandane's algo, tc= o(n), sc = o(n)
int maximumProduct(vector<int> &arr, int n){   
//here we have to keep track of 
//1. max of positive elements
//2. max of negative elements
int curr, max_of_positive = arr[0], max_of_negative = arr[0], ans = arr[0];
for(int i = 1; i < n; i++){
  curr = max({arr[i], max_of_positive * arr[i], max_of_negative * arr[i]});
  // storing the negative values
  max_of_negative = min({arr[i], max_of_positive * arr[i], max_of_negative * arr[i]});
  //storing the positive values
  max_of_positive = curr;
  ans = max(ans, max_of_positive);
}
return ans;
}

//using two traversals(forward&backward), tc= o(n) sc= o(1)
// int maximumProduct(vector<int> &arr, int n){
// 	//using two traversals(forward&backward), tc= o(n) sc= o(1)
//     bool zeroPresent = false;
//     int ans = 1, maxforward = arr[0], maxbackward = arr[0];
//     for(int i = 0; i < n; i++){
//          ans*=arr[i];
//          if(arr[i] == 0) {
//              ans = 1;
//              zeroPresent = true;
//              continue;
//          }
//          maxforward = max(maxforward, ans);
//     }
//     ans = 1;
//        for(int i = n-1; i >= 0; i--){
//          ans*=arr[i];
//          if(arr[i] == 0) {
//              ans = 1;
//              zeroPresent = true;
//              continue;
//          }
//          maxbackward = max(maxbackward, ans);
//     }
//     if(zeroPresent) return max(0, max(maxbackward,maxforward));
//     return max(maxbackward,maxforward);
// }
