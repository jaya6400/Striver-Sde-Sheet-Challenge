#include <bits/stdc++.h> 

int recur(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
    //using dp
    // int minians = INT_MAX;
    // if(i == j) return 0;

    // if(dp[i][j] != -1)
    // return dp[i][j];

    // for(int k = i; k < j; k++){
    //     int ans = recur(arr, i, k, dp) + recur(arr, k+1, j, dp) 
    //                 + arr[i-1]*arr[k]*arr[j];
    //     minians = min(minians, ans);
    // }

    // return minians;
    
    //using recursion
    // int minians = INT_MAX;
    // if(i == j) return 0;
    // for(int k = i; k < j; k++){
    //     //calculate the ans for each step
    //     int ans = recur(arr, i, k) + recur(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
    //     minians = min(ans, minians);
    // }
    // return minians;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int> (N));
    //using bottum up(tabulation)
    for(int i = 1; i < N; i++)
    dp[i][i] = 0;
    for(int i = N-1; i >= 1; i--)
    for(int j = i+1; j < N; j++){
        int minians = INT_MAX;
      for (int k = i; k < j; k++) {
        int ans = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
        minians = min(ans, minians);
      }
      dp[i][j] = minians;
    }
    return dp[1][N-1];
}
