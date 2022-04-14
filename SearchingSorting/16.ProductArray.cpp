//With Division
class Solution1{
    public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        long long int prod = 1;
        long long int temp;
        vector<long long int> prodArray;
        int zeros = 0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
                prod *= nums[i];
            else
                zeros++;
        }
        for(int i=0;i<n;i++){
            if(zeros == 1){
                if(nums[i]!=0)temp = 0;
                else temp = prod;
            }else if(zeros >1){
                temp = 0;
            }
            else{
                temp = prod/nums[i];
            }
            prodArray.push_back(temp);
        }
        
        return prodArray;
    }
};

//Without division
class Solution2{
    public:
    // each element is the prod of its left side element * right side elements leaving that
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        vector<long long int> left(n);
        vector<long long int> right(n);
        
        left[0] = 1;
        right[n-1] = 1;
        
        for(int i=1;i<n;i++){
            left[i] = left[i-1]* nums[i-1];
        }
        
        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1]*nums[i+1];
        }
        
        for(int i=0;i<n;i++){
            left[i] *= right[i];
        }
        
        return left;
    }
};