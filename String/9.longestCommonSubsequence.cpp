#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int LongestRepeatingSubsequence(string str){
                // Code here
                int size = str.size();
                string str1 = str;
                int c[size+1][size+1];
                for(int i=1;i<=size;i++){
                    c[i][0] = 0;
                }
                for(int i=1;i<=size;i++){
                    c[0][i] = 0;
                }
                for(int i=1;i<=size;i++){
                    for(int j=1;j<= size;j++){
                        if(str[i-1] == str1[j-1] && i != j){
                            c[i][j] = c[i-1][j-1]+1;
                        }else{
                            c[i][j] = max(c[i-1][j], c[i][j-1]);
                        }
                    }
                }
                return c[size][size];
                
            }
};


int main(){
    Solution s;
    string str = "agcsorvauz";
    int ans;
    ans = s.LongestRepeatingSubsequence(str);
    cout<<ans;
}