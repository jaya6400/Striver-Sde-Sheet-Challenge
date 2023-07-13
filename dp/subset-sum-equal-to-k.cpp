#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    //using tabulation(bottum-up) tc = o(n*val) sc = o(n*val)
    vector<vector<bool>> dp(n+1, vector<bool> (k+1, false));
    for(int i = 0; i < n; i++)
        dp[i][0] = true; //for k==0 return true

        if(arr[0] <= k)
        dp[0][arr[0]] = true; // ind == 0 return arr[0]==k

    for(int i = 1; i <= n; i++)
       for(int j = 1; j <= k; j++){
           bool notTake = dp[i-1][j];
           bool take = false;
           
           if(arr[i] <= j)
           take = dp[i-1][j-arr[i]];

           dp[i][j] = take||notTake;
       }
    return dp[n-1][k];
}
 int main(){
 int n, k;
 cin>>n>>k;
 vector<int> arr(n);
 for(int i = 0; i < n; i++)
        cin>>arr[i];
 cout<<subsetSumToK(n, k, arr);
//return 0;
 }

//space optimization tc = o(n*val) sc = o(k)
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<bool> prevRow(k+1, false);
//    vector<bool> currRow(k+1, false);
//     prevRow[0] = true; //for k==0 return true

//         if(arr[0] <= k)
//            prevRow[arr[0]] = true; // ind == 0 return arr[0]==k

//     for(int i = 1; i <= n; i++){
//         currRow[0] = true;
//         for (int j = 1; j <= k; j++) {
//           bool notTake = prevRow[j]; //dp[i-1][j] denotes prevRow
//           bool take = false;

//           if (arr[i] <= j)
//             take = prevRow[j - arr[i]];

//           currRow[j] = take || notTake; //dp[i][j] denotes currRow
//         }
//         prevRow = currRow;
//     }
//     return prevRow[k];
// }

   //using memoization(top-down) tc= o(n*val) sc= o(n*val) + o(n)
// bool recur(int ind, int val, vector<int> &arr, vector<vector<int>> &dp){
    // if(val == 0) return true;
    // if(ind == 0) return arr[0] == val;

    // if(dp[ind][val] != -1) return dp[ind][val];

    // bool notTake = recur(ind-1, val, arr, dp);
    // bool take = false;

    // if(arr[ind] <= val)
    //    take = recur(ind-1, val-arr[ind], arr, dp);

    // dp[ind][val] = notTake || take;

    // return dp[ind][val];
    
    // recursion tc= o(2^n) sc = o(n)
    //base case
    //  if(val == 0)
    // return true;

    // if(ind == 0)
    // return arr[0] == val;
   
    // bool notTake = recur(ind-1, val, arr);
    // bool take = false;
    // if(arr[ind] <= val)
    // {
    //     take = recur(ind-1, val-arr[ind], arr);
    // }
    // return notTake || take;
//}

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
//     return recur(n-1, k, arr, dp);
// }
