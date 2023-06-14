#include<bits/stdc++.h>
using namespace std;

bool allocate(vector<int> time, long long mid, int n){
	long long sumChap = 0, cnt = 0;
	for(int i = 0; i < time.size(); i++){
	if(sumChap+time[i] > mid)
	{
          cnt++;
          sumChap = time[i];
          if (sumChap > mid)
            return false;
        }else{
			sumChap += time[i];
		}
}
        if(cnt < n)
	      return true;
	return false;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long lo = time[0], hi = 0, mid = 0;
	for(int i = 0; i < m; i++){
		lo = min(time[i], (int)lo);
		hi = hi + time[i];
	}
    while(lo <= hi){
       mid = (lo+hi) >> 1;
	   if(allocate(time, mid, n))
	   hi = mid - 1;
	   else
	   lo = mid + 1;
	}
	return lo;
}
int main(){
 int n, m;
 cin>>n>>m;
 
 vector<int> time(m);
 for(int i = 0; i < n; i++)
 cin>>time[i];
 cout<<ayushGivesNinjatest(n, m, time);
//return 0;
 }
