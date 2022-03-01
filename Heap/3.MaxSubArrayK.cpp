class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        
        //SOLUTION 1
        //TC = O(N*(K-1)) = Worst
       vector <int> ans;
        for(int i=0;i<=n-k;i++){
            int max=arr[i];
            for(int j=i+1;j<k+i;j++){
                  if(arr[j]> max)
                    max = arr[j];
            }
            ans.push_back(max);
        }
        return ans;
        //-------------------------------------//
        //O(n)
        if(k==1){
            ans.push_back(arr[0]);
        }
        deque<int> dq;
        dq.push_back(0);
        
        for(int i=1;i<n;i++){
            if(arr[dq.back()]>arr[i] || dq.empty())
                dq.push_back(i);
            else{
                while(!dq.empty() && arr[dq.back()]<arr[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            if(i>k-2){
                ans.push_back(arr[dq.front()]);
                if(dq.front()<(i-k-1))
                    dq.pop_front();
            }
        }
        
        return ans;

        
        return ans;
    }
};