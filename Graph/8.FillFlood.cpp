class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor , int oldClr,int m, int n, vector<vector<int> >& vis){
        if(i>=m or i<0 or j>=n or j<0) return;
        
        if(vis[i][j] or image[i][j] != oldClr) return;
        
        vis[i][j] = 1;
        image[i][j] = newColor;
        
        //all 4 directions to be updated
        dfs(image, i+1, j, newColor, oldClr, m, n, vis);
        dfs(image, i-1, j, newColor, oldClr, m, n, vis);
        dfs(image, i, j+1, newColor, oldClr, m, n, vis);
        dfs(image, i, j-1, newColor, oldClr, m, n, vis);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int oldClr = image[sr][sc];
        vector<vector<int> > vis(m, vector<int>(n,0));
        
        
        //dfs applied since color has to updated depth wise
        dfs(image, sr, sc, newColor, oldClr,m,n, vis);
        
        return image;
    }
};