#include <bits/stdc++.h>

//using tabulation/bottom-up, tc=o(n*n), sc= o(n*n)
int cutRod(vector<int> &price, int n)
{   vector<vector<int>> dp(n, vector<int> (n+1, 0));

	for(int i = 0; i <= n; i++)
	dp[0][i] = price[0]*i; //base case

	for(int ind = 1; ind <= n-1; ind++){
          for (int len = 0; len <= n; len++) {
            int notTake = 0 + dp[ind - 1][len];
            int rodlen = ind + 1;
            int take = 0;
            if (rodlen <= len)
              take = price[ind] + dp[ind][len - rodlen];

			dp[ind][len] = max(take, notTake);
          }
        }
    return dp[n-1][n];
}

int main(){
  int n;
  cin>>n;
  vector<int> price;
  for(int i = 0; i < n; i++)
    cin>>price[i];
  return cutRod(price, n);
}
//space optimization, tc= o(n*n) sc= o(n)
// int cutRod(vector<int> &price, int n)
// {   vector<int> curr(n+1, 0);

// 	for(int i = 0; i <= n; i++)
// 	curr[i] = price[0]*i; //base case

// 	for(int ind = 1; ind <= n-1; ind++){
//           for (int len = 0; len <= n; len++) {
//             int notTake = 0 + curr[len];
//             int rodlen = ind + 1;
//             int take = 0;
//             if (rodlen <= len)
//               take = price[ind] + curr[len - rodlen];

// 			curr[len] = max(take, notTake);
//           }
//         }
//     return curr[n];
// }

// //using memoization/top-down, tc=o(n*n), sc= o(n*n)+o(n)
// int recur(int ind, int n, vector<int> &price, vector<vector<int>> &dp){
// 	if(ind == 0) return price[0]*n; //base case
// 	if(dp[ind][n] != -1) return dp[ind][n];
// 	int notTake = 0+recur(ind-1, n, price, dp);
// 	int rodlen = ind+1;
// 	int take = 0;
// 	if(rodlen <= n)
// 	take = price[ind] + recur(ind, n-rodlen, price, dp);
	
// 	return dp[ind][n] = max(take, notTake);
// }

// int cutRod(vector<int> &price, int n)
//{   // like unbound knapsack
// 	//1. express into indexes
// 	//2. try all possibilities(take/notake)
// 	//3. return max of take & notake
// 	vector<vector<int>> dp(n, vector<int> (n+1, -1));
//     return recur(n-1, n, price, dp);
//}

//using recursion, tc=2^n, sc=o(n)
// int recur(int ind, int n, vector<int> &price){
// 	if(ind == 0) return price[0]*n; //base case
// 	int notTake = 0+recur(ind-1, n, price);
// 	int rodlen = ind+1;
// 	int take = 0;
// 	if(rodlen <= n)
// 	take = price[ind] + recur(ind, n-rodlen, price);
	
// 	return max(take, notTake);
// }
