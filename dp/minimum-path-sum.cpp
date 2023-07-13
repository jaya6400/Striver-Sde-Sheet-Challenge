#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
   //tabulation/bottom-up, tc = o(n*m), sc = o(n*m) for external array
       int n = grid.size();
       int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
       int up, left;
       for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
            if(i == 0 && j == 0)
            dp[i][j] = grid[i][j];
            else{
                up = grid[i][j];
                if(i > 0)
                up += dp[i-1][j];
                else
                up += 1e9;
                left = grid[i][j];
                if(j > 0)
                left += dp[i][j-1];
                else
                left += 1e9;
                dp[i][j] =min(up, left);
            }
          }
       }
       return dp[n-1][m-1];

       //for space optimization to 1D,tc = o(n*m), sc = o(m)
       //we need a prev to store dp[i-1][j] and a curr to store dp[i][j-1]
      // int n = grid.size();
      // int m = grid[0].size();
      // vector<int> p(m,0);
       //vector<int> c(m,0);
      // int up,left;
      //  for(int i = 0; i < n; i++){
    //        for (int j = 0; j < m; j++) {
    //          if (i == 0 && j == 0)
    //            c[j] = grid[i][j];
    //            else{
    //                up = grid[i][j];
    //                if(i > 0)
    //                up += p[j];
    //                else
    //                up += 1e9;

    //                left = grid[i][j];
    //                if(j > 0)
    //                left += c[j-1];
    //                else
    //                left += 1e9;

    //                c[j] = min(up,left);
    //            }
    //        }
    //        p = c;
    //    }
    //    return p[m-1];
}
 int main(){
 int n, m;
 cin>>n>>m;
 vector<vector<int>> arr(n, vector<int> (m, 0);
 for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        cin>>arr[i][j];
 cout<<minSumPath(arr);
//return 0;
 }
