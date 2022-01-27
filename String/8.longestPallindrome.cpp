#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> maxLongest;
        maxLongest.push_back(0);
        maxLongest.push_back(1);

        for(int i=1;i<s.size();i++){
            vector<int> odd;
            vector<int> even;
            
            odd = getLongestPalindromeFrom(s, i-1, i+1);
            even = getLongestPalindromeFrom(s,i-1,i);
            
            int lengthOfOdd = odd[1]-odd[0]+1;
            int lengthOfEven = even[1]-even[0]+1;
            vector<int> longest;
            if(lengthOfOdd > lengthOfEven)
                longest = odd;
            else
                longest = even;
            
            int longestLength = longest[1]-longest[0];
            cout<< longest[0]<<" "<< longest[1]<<" length = "<<longestLength<<endl;
            int maxLongestLength = maxLongest[1]-maxLongest[0];
            cout<<maxLongestLength<<endl;
            if(maxLongestLength < longestLength)
                maxLongest = longest;
        }

        int length = maxLongest[1]-maxLongest[0];
        cout<< maxLongest[0]<<" "<< maxLongest[1]<<endl;
        string ans = s.substr(maxLongest[0], length);
        return ans;
    }
    
    vector<int> getLongestPalindromeFrom(string s, int leftIdx, int rightIdx){
        vector<int> ans;
        while(leftIdx>=0 && rightIdx < s.size()){
            if(s[leftIdx] != s[rightIdx])
                break;
            leftIdx--;
            rightIdx++;
        }
        ans.push_back(leftIdx+1);
        ans.push_back(rightIdx);
        
        return ans;
        
    }
    
};


int main(){
    Solution s;
    string str = "cbabad";
    string ans;
    ans = s.longestPalindrome(str);
    cout<<ans;
}