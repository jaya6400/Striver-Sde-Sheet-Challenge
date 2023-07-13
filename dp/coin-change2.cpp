#include <bits/stdc++.h>

long countWaysToMakeChange(int *denominations, int n, int value) 
{ // tabulation bottom-up, tc=o(n*t) sc = o(n*t)
  vector<vector<long>> dp(n, vector<long>(value + 1, 0));
  // base case
  for (int i = 0; i <= value; i++)
{
    if(i%denominations[0] == 0)
    dp[0][i] = 1;
}
for(int ind = 1; ind < n; ind++){
    for(int t = 0; t <= value; t++){
        long ntake = dp[ind-1][t];
        long take= 0;
        if(denominations[ind] <= t)
            take = dp[ind][t-denominations[ind]]; //selecting the value at ind index
            dp[ind][t] = ntake+take;
    }
}
return dp[n-1][value];
}

int main(){
 int n, value;
 cin>>n>>value;
 int *arr;
 for(int i = 0; i < n; i++)
        cin>>arr[i];
 cout<<countWaysToMakeChange(arr, n, value);
//return 0;
 }

// long recur(int *denominations, int ind, int val, vector<vector<long>> &dp){
//memorization / top-down, tc=o(n*t) sc = o(n*t) + o(n)
// if(ind == 0)
// return (val%denominations[0] == 0);

// if(dp[ind][val] != -1)
// return dp[ind][val];

// long take = 0;
// long ntake = recur(denominations, ind-1, val, dp); //not selecting the value at ind index
// if(denominations[ind] <= val)
// take = recur(denominations, ind, val-denominations[ind], dp); //selecting the value at ind index
// dp[ind][val] = ntake+take;

// return dp[ind][val];

//using recursion, tc = exponencial sc = more than o(n) or o(val)
// int take = 0;
// if(ind == 0)
// return (val%denominations[0] == 0);
// long ntake = recur(denominations, ind-1, val); //not selecting the value at ind index
// if(denominations[ind] <= val)
// take = recur(denominations, ind, val-denominations[ind]); //selecting the value at ind index
// return ntake+take;
// }
// long countWaysToMakeChange(int *denominations, int n, int value)
// {
//     vector<vector<long>> dp(n, vector<long>(value+1, -1));
// return recur(denominations, n-1, value, dp);
// }
