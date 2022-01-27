#include<iostream>
#include<vector>
#include<algorithm>
//Solution 1 :
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int max = nums[nums.size()-1]-k;
        for(int i =nums.size()-2;i>=0;i--){
            if(nums[i]+k <= max)
            {
                nums[i] += k;
            }else{
                int j = 0;
                while(nums[i]+(k-j) > max && k-j>= -k){
                    j++;
                }
                nums[i] += (k-j);
            }
        }
        int sum = max - nums[0];
        return sum;
    }
};

//Solution 2 :
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int max = nums[nums.size()-1]-k;
        int j = 0;
        while(nums[0]+(k-j) > max && k-j>= -k){
            j++;
        }
        nums[0] += (k-j);
        int sum = max - nums[0];
        return sum;
    }
};

//Solution 3 :
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
       int max = *max_element(nums.begin(), nums.end());
       int min = *min_element(nums.begin(), nums.end());
        if(min+k > max-k){
            return 0;
        }
        return ((max-k)-(min+k));
    }
};