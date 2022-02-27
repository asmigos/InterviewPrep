class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int> > ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int left = j+1;
                int right = n-1;
                long sum = arr[i]+arr[j];
                
                while(left<right){
                    vector<int> row;
                    if(sum+arr[left]+arr[right]<k){
                        left++;
                    }else if(sum+arr[left]+arr[right]>k){
                        right--;
                    }else if(sum+arr[left]+arr[right] == k){
                        row.push_back(arr[i]);
                        row.push_back(arr[j]);
                        row.push_back(arr[left]);
                        row.push_back(arr[right]);
                         while(left<right && arr[left]==row[2])
                            left++;
                        while(left<right && arr[right]==row[3])
                            right--;
                    }
                    vector<vector<int> > :: iterator it;
                    it = find(ans.begin(), ans.end(), row);
                    if(row.size()>0 && (it == ans.end()))
                        ans.push_back(row);
                }
                
            }
            
        }
        return ans;
    }
};