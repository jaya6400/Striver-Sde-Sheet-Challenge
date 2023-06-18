//TC = o(i*j) array + **O(i+j) stack space**
//memorization
 int helper(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(word1[i] == word2[j])
            return dp[i][j] = 0+helper(word1, word2, i-1, j-1, dp);
        else
            return dp[i][j] = 1+min(helper(word1, word2, i-1, j-1, dp), min(helper(word1, word2, i, j-1, dp), helper(word1, word2, i-1, j, dp)));
    }
// tc - O(N*M) sc - O(M)
// int helper(string &word1, string &word2){
//     int n = word1.size();
//     int m = word2.size();
    
//     vector<int> prv(m+1,0);
//     vector<int> cur(m+1,0);
    
//     for(int j=0;j<=m;j++){
//         prv[j] = j;
//     }
    
//     for(int i=1;i<n+1;i++){
//         cur[0]=i;
//         for(int j=1;j<m+1;j++){
//             if(word1[i-1]==word2[j-1])
//                 cur[j] = 0+prv[j-1];
            
//             else cur[j] = 1+min(prv[j-1],min(prv[j],cur[j-1]));
//         }
//         prv = cur;
//     }
    
//     return prv[m];
//     }
    int minDistance(string word1, string word2) {
       int i = word1.size(), j = word2.size();
       vector<vector<int>> dp(i+1, vector<int> (j+1, -1));
       return helper(word1, word2, i, j, dp);
    }
int main(){
 string word1, word2;
 cin>>word1>>word2;
 cout<<minDistance(word1, word2);
 return 0;
 }


