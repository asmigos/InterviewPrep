#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
static bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
     return v1[0] < v2[0];
    }

    vector< vector<int> > merge(vector< vector<int> >& intervals) {
        int start, end;
        vector< vector<int> > nums;
        vector<int> interval;
        
        sort(intervals.begin(), intervals.end(), sortcol);
        
        int i =0;
        while( i<intervals.size()){
            start = intervals[i][0];
            end = intervals[i][1];
            i++;
            while(i<intervals.size() && end>=intervals[i][0]){
                end = max(intervals[i][1], end);
                i++;
            }
            interval.push_back(start);
            interval.push_back(end);
            nums.push_back(interval);
            interval.clear();
        }
        return nums;
    }
};

int main(){
    vector< vector<int> > nums ;
    vector<int> i1;
    vector<int> i2;
    vector<int> i3;
    vector<int> i4;
    // vector<int> i1;
    // vector<int> i1;
    
    i1.push_back(1);
    i1.push_back(4);
    nums.push_back(i1);
    i2.push_back(0);
    i2.push_back(4);
    nums.push_back(i2);
    // i3.push_back(8);
    // i3.push_back(10);
    // nums.push_back(i3);
    // i4.push_back(12);
    // i4.push_back(15);
    // nums.push_back(i4);

    for(int i =0;i<nums.size();i++){
        for(int j =0;j<2;j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
    
    vector< vector<int> > ans;
    Solution s;
    ans = s.merge(nums);

    cout<<"New Interval"<<endl;
    for(int i =0;i<ans.size();i++){
        for(int j =0;j<2;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}