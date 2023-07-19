#include <bits/stdc++.h> 

//using tabulation(bottum-up), tc= o(n^3), sc= o(n)
bool stringCheck(vector < string > & arr, int n, string target){
 //checking if a word is present in a string
      for(int i = 0; i < n; i++)
           if(arr[i].compare(target) == 0)
           return true;
      return false;
}

bool wordBreak(vector < string > & arr, int n, string target) {
    int size = target.size();
    vector<bool> dp(size+1, false);
     for(int i = 1; i <= size; i++){
         if(dp[i] == false && stringCheck(arr, n, target.substr(0, i)))
            dp[i] = true;
         if(dp[i] == true){
             if(i == size) return true;
             for(int j = i+1; j <= size; j++){
                if(dp[j] == false && stringCheck(arr, n, target.substr(i, j-i)))
                    dp[j] = true;
             }
         }
     }
     return false;
}

//recursive solution with TLE, tc= 2^n sc = o(n)+o(n)[stack space]
// bool stringCheck(vector < string > & arr, int n, string target){
//  //checking if a word is present in a string
//       for(int i = 0; i < n; i++)
//            if(arr[i].compare(target) == 0)
//            return true;
//       return false;
// }

// bool wordBreakHelper(vector < string > & arr, int n, string target) {
//      int size = target.size();
//      if(size == 0) return true;
//      for(int i = 1; i <= size; i++){
//          if(stringCheck(arr, n, target.substr(0, i))
//          && wordBreakHelper(arr, n, target.substr(i, size-i)))
//          return true;
//      }
//      return false;
// }
// bool wordBreak(vector < string > & arr, int n, string & target) {
//    return wordBreakHelper(arr, n, target);
// }
