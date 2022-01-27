#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
    vector<int> ans;
    int i=0;int j=0;
    int a=0, k=0;
    while(k<(r*c)){
        while(i<c-a){
            ans.push_back(matrix[j][i]);
            i++;
            k++;
        }
        i--;
        k--;
        j++;
        while(j<r-a){
            ans.push_back(matrix[j][i]);
            j++;
            k++;
        }
        j--;
        k--;
        i--;
        while(i>-1+a){
            ans.push_back(matrix[j][i]);
            i--;
            k++;
        }
        i++;
        k--;
        a++;
        j--;
        while(j>-1+a){
            ans.push_back(matrix[j][i]);
            j--;
            k++;
        }
        j++;
        k--;
        i++;
    }
    return ans;
    }
};

int main(){
    int r=3, c =4;
    int matrix[r][c] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}};

    
}