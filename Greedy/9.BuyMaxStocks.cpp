#include <vector>
#include <iostream>
using namespace std;


//TC: O(nlogn) SC: O(n)
class Solution{
    public:
        int buyMaxStock(int n, int k, int price[]){
            vector<pair<int, int> > v;
            for(int i=0;i<n;i++){
                v.push_back(make_pair(price[i], i+1));
            }
            sort(v.begin(), v.end());
            int ans =0;
            for(int i=0;i<n;i++){
                ans += min(v[i].second, k/v[i].first);
                k -= v[i].first * min(v[i].second, k/v[i].first);
            }
            return ans;
        }
};