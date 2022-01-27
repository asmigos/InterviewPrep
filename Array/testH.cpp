#include <iostream>
using namespace std;
class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int end = n-1;
        int start = 0;
        int count1 =0;
        int count2 =0;
        while(start<end){
            if((arr[end]) > k && arr[start]<=k){
                swap(arr[start], arr[end]);
                cout<<arr[start]<<" "<<arr[end]<<" k = "<<k<<endl;
                count2++;
                start++;
                end--;
            }else if(arr[start]<=k){
                end--;
            }else if(arr[end]>k) {
                start++;
            }
            else{
                start++;
                end--;
            }
        }

        end = n-1;
        start = 0;
        while(start<end){
            if(arr[start]>k && arr[end] <= k){
                swap(arr[start], arr[end]);
                count1++;
                start++;
                end--;
            }else if(arr[start]>k){
                end--;
            }else if(arr[end]<=k) {
                start++;
            }
            else{
                start++;
                end--;
            }
        }
        
        // end = n-1;
        // start = 0;
        // int count2 =0;
        // while(start<end){
        //     if((arr[end]) > k && arr[start]<=k){
        //         swap(arr[start], arr[end]);
        //         cout<<arr[start]<<" "<<arr[end]<<" k = "<<k<<endl;
        //         count2++;
        //         start++;
        //         end--;
        //     }else if(arr[start]<=k){
        //         end--;
        //     }else if(arr[end]>k) {
        //         start++;
        //     }
        //     else{
        //         start++;
        //         end--;
        //     }
        // }
        cout<<count1;
        int minCount = min(count1, count2);
        return minCount;
    }
};

int main(){
    int i,t,n,k;
    n = 5;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    k=3;
    Solution s;
    int a = s.minSwap(arr, n, k);
    cout<< a;

}