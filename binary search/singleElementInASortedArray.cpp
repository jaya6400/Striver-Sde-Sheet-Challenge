#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& arr)
        int ans = 0;
        if(nums.size() == 1)
            return nums[0];
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] != nums[i+1] && nums[i+1] != nums[i+2]){
                ans = nums[i+1];
                break;
        }else{
                ans = nums[0];
            }
        }
        return ans;
 }
 
 int main{
 int n;
 cin>>n;
 int arr[n];
 for(int i = 0; i < n; i++)
 cin>>arr[i];
 singleNonDuplicate(arr);
 return 0;
 }
