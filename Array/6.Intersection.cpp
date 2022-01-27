#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    if(count(nums3.begin(), nums3.end(), nums1[i])){
                        
                    }else{
                        nums3.push_back(nums1[i]);    
                    }
            
                }
        
            }
        }
        return nums3;
    }
}; //space = 10mb   time = 36ms

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        for(int i=0;i<nums1.size();i++){
            if(count(nums2.begin(), nums2.end(), nums1[i])){
                if(find(nums3.begin(), nums3.end(), nums1[i])== nums3.end())
                    nums3.push_back(nums1[i]);
            }
        }
        return nums3;
    }
}; //space = 9.9mb  time = 11ms

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums3;
        for(int i=0;i<nums1.size();i++){
            if(count(nums2.begin(), nums2.end(), nums1[i])){
                nums3.insert(nums1[i]);
            }
        }
        vector<int> nums4(nums3.begin(), nums3.end());
        return nums4;
    }
}; //space = 10.2 mb, time = 11ms

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        for(int i=0;i<nums1.size();i++){
            if(count(nums2.begin(), nums2.end(), nums1[i])){
                if(find(nums3.begin(), nums3.end(), nums1[i])== nums3.end())
                    nums3.push_back(nums1[i]);
            }
        }
        return nums3;
    }
};//space = 10 mb, time = 4ms