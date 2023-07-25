#include <bits/stdc++.h>

//using tabulation(bottom-up), tc= o(n*w), sc= o(n*w)
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int>(w+1, 0));
	//fill the base case
	for(int i = weights[n-1]; i <= w; i++)
	    dp[n-1][i] = values[n-1];

	for(int ind = n-2; ind >= 0; ind--)
	{
		for(int we = w; we >= 0; we--){
           int nottake = 0 + dp[ind+1][we];
		   int take = INT_MIN;
		   if(weights[ind] <= we)
		   take = values[ind] + dp[ind+1][we-weights[ind]];
		   dp[ind][we] = max(take,nottake);
	}
	}
    return dp[0][w];
}


//space optimization sc = o(w)
// int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
// {
// 	vector<int> curr(w+1, 0);
// 	//fill the base case
// 	for(int i = weights[n-1]; i <= w; i++)
// 	   curr[i] = values[n-1];

// 	for(int ind = n-2; ind >= 0; ind--)
// 	{
// 		for(int we = w; we >= 0; we--){
//            int nottake = 0 + curr[we];
// 		   int take = INT_MIN;
// 		   if(weights[ind] <= we)
// 		   take = values[ind] + curr[we-weights[ind]];
// 		   curr[we] = max(take,nottake);
// 	}
// 	}
//     return curr[w];
// }

//using memoziation, tc= o(n*w), sc = o(n*w) + o(n)
// int recur(int ind, vector<int> &values, vector<int> &weights, int n, int w, 
//                         vector<vector<int>> &dp){
//   if (ind == n-1) {
//     if (weights[n-1] <= w)
//       return values[n-1];
// 	else
//       return 0;
//   }
// 	if(dp[ind][w] != -1)
// 	return dp[ind][w];

// 	int nottake = 0 + recur(ind+1, values, weights, n, w, dp);
// 	int take = INT_MIN;
// 	if(weights[ind] <= w){
// 		take = values[ind] + recur(ind+1, values, weights, n, w-weights[ind], dp);
// 	}
// 	return dp[ind][w] = max(take, nottake);
// }

//using recursion (tle)
// int recur(int ind, vector<int> &values, vector<int> &weights, int n, int w){
  
//   if (ind == n-1) {
//     if (weights[n-1] <= w)
//       return values[n-1];
// 	else
//       return 0;
//   }

// int nottake = 0 + recur(ind+1, values, weights, n, w);
// int take = INT_MIN;
// if(weights[ind] <= w){
// 	take = values[ind] + recur(ind+1, values, weights, n, w-weights[ind]);
// }

// return max(take, nottake);
// }

// int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
// {
// 	   vector<vector<int>> dp(n, vector<int>(w+1, -1));
//     return recur(0, values, weights, n, w, dp);
// }
