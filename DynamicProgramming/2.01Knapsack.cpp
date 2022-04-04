class Solution{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1000][1000];
    int solve(int W, int wt[], int val[], int n){
        //Best Case : No element and no weight
        if(n==-1 || W==0){
            return 0;
        }
        //element having weight > total weight
        if (wt[n] > W)
            return solve(W, wt, val, n-1);
        
        //creating memorization int a tabular form
        if(dp[W][n] != -1) return dp[W][n];
        
                //element included                     //element not included    
        return dp[W][n] = max((val[n] + solve(W-wt[n],wt,val,n-1)), solve(W,wt,val,n-1));
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       dp[W+1][n];
       for(int i=0;i<=W;i++){
           for(int j=0;j<n;j++){
               dp[i][j] = -1;
           }
       }
       return solve(W,wt,val,n-1);
    }
}