#include <bits/stdc++.h>
using namespace std;

int power(int mid, int n){
  int res = 1;
  for(int i = 1; i <= n; i++)
  res = res * mid;
  return res;
}
int NthRoot(int n, int m) {
  int lo = 1, hi = m;
  long double ep = 1e-16;
  while((hi - lo) > ep){
    int mid = (lo + hi)/2;
    if(power(mid, n) < m)
    lo = mid;
    else
    hi = mid;
  }
  return lo;
}

int main(){
  int n, m;
  cin>>n>>m;
  NthRoot(n,m);
  return 0;
}

