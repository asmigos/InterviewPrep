#include<iostream>
#include<vector>

using namespace std;

class Solution{
    private:
    bool isSafe(int x, int y, vector<vector<int>> visited, vector<vector<int>> &m, int n){
        if((x>-1 && x<n) && (y>-1 && y<n) && visited[x][y] ==0  && m[x][y] == 1){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, 
                vector<vector<int>> visited, string s){
        
        //base case
        if(x==n-1 && y == n-1){
            ans.push_back(s);
            return;
        }  
        
        visited[x][y] = 1;
        
        //down
        int newX = x+1;
        int newY = y;
        if(isSafe(newX, newY, visited, m, n)){
            s.push_back('D');
            solve(m, n, ans, newX, newY, visited, s);
            s.pop_back();
        }
        
        //left
        newX = x;
        newY = y-1;
        if(isSafe(newX, newY, visited, m, n)){
            s.push_back('L');
            solve(m, n, ans, newX, newY, visited, s);
            s.pop_back();
        }
        
        //right
        newX = x;
        newY = y+1;
        if(isSafe(newX, newY, visited, m, n)){
            s.push_back('R');
            solve(m, n, ans, newX, newY, visited, s);
            s.pop_back();
        }
        
        //up
        newX = x-1;
        newY = y;
        if(isSafe(newX, newY, visited, m, n)){
            s.push_back('U');
            solve(m, n, ans, newX, newY, visited, s);
            s.pop_back();
        }
        visited[x][y] = 0;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string s = "";
        if(m[0][0] == 0){
            return ans;
        }
        
        int x = 0;
        int y = 0;
        
        vector<vector<int>> visited = m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        
        solve(m,n,ans,x,y,visited, s);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
    
};
