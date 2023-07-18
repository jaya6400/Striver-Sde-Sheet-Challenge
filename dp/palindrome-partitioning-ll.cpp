#include <bits/stdc++.h> 

bool ispalin(int l, int h, string s){
while(l < h){
    if(s[l] != s[h])
        return false;
    l++; h--;
}
return true;
}

//using tabulation/top-down, tc=o(n)*n sc = o(n)
int palindromePartitioning(string str) {
    int strlen = str.size();
    vector<int> dp(strlen + 1, 0);
    //base case
    dp[strlen] = 0;
    //reverse of memoization where ind ranges from 0~n
    for(int ind = strlen-1; ind >= 0; ind--){
       int mincount = INT_MAX, count = 0;
       for (int j = ind; j < strlen; j++) {
         if (ispalin(ind, j, str))
           count = 1 + dp[j + 1];
         mincount = min(mincount, count);
       }
       dp[ind] = mincount;
    }
    return dp[0] - 1;
}

//using memoization, tc=o(n)*n sc = o(n)+o(n)
// int recur(int ind, string &str, vector<int> &dp){
//     //base case
//     int strlen = str.size();
//     if(ind == strlen) return 0; 
//     if(dp[ind] != -1)
//         return dp[ind];
//     int mincount = INT_MAX, count = 0;
//     string temp = "";
//     for(int j = ind; j < strlen; j++){
//         temp += str[j];
//         if(ispalin(0, temp.size()-1,temp))
//         count = 1 + recur(j+1, str, dp);
//         mincount = min(mincount, count);
//     }
//      return dp[ind] = mincount;
// }

//using recursion, tc=2^n
// int recur(int ind, string &str){
//     //base case
//     int strlen = str.size();
//     if(ind == strlen) return 0; //when string is empty then we end(ie no partition)
//     //try all possibilities, we need a index j to store each substring
//     //for a particular partition at index i
//     int mincount = INT_MAX, count = 0;
//     string temp = "";
//     for(int j = ind; j < strlen; j++){
//         temp += str[j];
//         if(ispalin(0, temp.size()-1,temp))
//         count = 1 + recur(j+1, str);
//         mincount = min(mincount, count);
//     }
//      return mincount;
// }

// int palindromePartitioning(string str) {
//     vector<int> dp(str.size(), -1);
//     return recur(0, str, dp) - 1;
// }
