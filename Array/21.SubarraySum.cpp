#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool subarraySum(vector<int>& nums, int k) {
            //for Number of subarray with Sum = K
        // int i=nums.size()-1;
        // cout<<i;
        // int origin = k;
        // int count =0;
        // while(i>-1){
        //     if(nums[i]>origin){
        //         i--;
        //         continue;
        //     }
        //     if(k>0){
        //         k -= nums[i];
        //     }
        //     if(k==0){
        //         count++;
        //         k = origin;
        //     }else if(k<0){
        //         k = origin;
        //     }
        //     i--;
        // }
        int i=0; bool isPresent = false; int origin = k;
        while(i<nums.size()){
                k = k-nums[i];
                if(k==0){
                    isPresent = true;
                    break;
                }
                else if(k>0){
                    i++;
                }else if(k<0){
                    k = origin;
                }
        }
        return isPresent;
    }
};

int main(){
    Solution s;
    vector<int> array ;
    int arr[] = {1,4,7};
    for(int i=0;i<3;i++){
        array.push_back(arr[i]);
    }
    for(int i=0;i<3;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    bool cnt =s.subarraySum(array, 5);
    string a = cnt > 0 ? "true" : "false";
    cout<<endl<<"isPresent  = " << a;
}