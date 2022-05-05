class Solution {
public:
    
    void dfs(int m, int n, vector<vector<int>>& vis, vector<vector<char>>& grid, int row, int col){
        if(row < 0 || row >= m || col<0 || col >= n || vis[row][col] || grid[row][col] == '0') return;
        
        vis[row][col] = 1;
        
        dfs(m,n,vis,grid,row, col-1);
        dfs(m,n,vis,grid,row, col+1);
        dfs(m,n,vis,grid,row-1, col);
        dfs(m,n,vis,grid,row+1, col);
        
        //-----for diagonal also-----
        // dfs(m,n,vis,grid,row+1, col+1); 
        // dfs(m,n,vis,grid,row-1, col+1);
        // dfs(m,n,vis,grid,row+1, col-1);
        // dfs(m,n,vis,grid,row-1, col-1);
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        int count=0;
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    dfs(m,n,vis, grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};