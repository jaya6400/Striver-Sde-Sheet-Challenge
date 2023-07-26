#include <bits/stdc++.h> 

bool comp(pair<int, int> a, pair<int, int> b){
double c1 = (double)a.second/(double)a.first;
double c2 = (double)b.second/(double)b.first;

return c1>c2; //whose val/weight will be more in the all pairs, items array will be sorted in that order
}
//tc = o(nlogn + n) , o(nlogn) for sorting, o(n) for looping 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
  double maxval = 0.0;
  int currWeight = 0;
  //sorting the weight-values in decreasing order
  sort(items.begin(), items.end(), comp);
  for(int i = 0; i < n; i++){
    if(currWeight+items[i].first <= w)
        {
            currWeight += items[i].first;
            maxval += items[i].second;
        }else{
            //if the remaining weight is less than w
            //take only the fraction of the left indexes
            maxval += (items[i].second/(double)items[i].first)*(w-currWeight);
            break;
        }
  }
  return maxval;
}
