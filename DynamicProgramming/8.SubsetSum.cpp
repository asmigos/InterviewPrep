//TC = SC: O(N x Sum/2) ->loop will run in solve
class Solution{
    public:
    int dp[1001][1001];
    int solve(int n, int arr[], int sum){
        if(n== -1){
            if(sum==0)
                return 1;
            return 0;
        }
        
        if(sum < 0)
            return 0;
        if(sum == 0)
            return 1;
        if(dp[n][sum] != -1) return dp[n][sum];
        
        return dp[n][sum] = solve(n-1, arr, sum-arr[n]) || solve(n-1, arr, sum);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum =0;
       for(int i=0;i<N;i++){
           sum = sum+arr[i];
       }
       if(sum & 1) return 0; //for odd sum
       
       sum = sum/2;
       
       dp[N][sum];
       memset(dp, -1, sizeof(dp));
       return solve(N-1, arr, sum);
       
       
    }
};