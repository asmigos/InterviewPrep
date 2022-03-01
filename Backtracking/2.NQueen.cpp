class Solution{
    private:
        void generateBoard(vector<vector<int>> &board, int n){
            vector<int> row;
            for(int i=0;i<n;i++){
                row.push_back(0);
            }
            for(int i=0;i<n;i++){
                board.push_back(row);
            }
        }
        
        bool isSafe(vector<vector<int>> &board , int x, int y, int n){
            //for each row
            for(int row=0;row<x;row++){
                if(board[row][y]==1)
                    return false;
            }
            //for upper col
            for(int col=0;col<y;col++){
                if(board[x][col]==1)
                    return false;
            }
            //for left dig in upper
            int row=x;
            int col=y;
            while(row>=0 && col>=0){
                if(board[row][col]==1)
                    return false;
                row--;
                col--;
            }
            //for left dig in lower
            row=x;
            col=y;
            while(row<n && col>=0){
                if(board[row][col]==1)
                    return false;
                row++;
                col--;
            }
            return true;
        }
        
        bool solveNQueen(vector<vector<int>> &board, int col, int n , vector<vector<int>> &ans){
            //base case
            if(col >= n){ //if all rows complete and all queens placed
                vector<int> r;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(board[i][j] ==1){
                            r.push_back(j+1);
                        }
                    }
                }
                ans.push_back(r);
                return true;
            }
            bool res = false;
            for(int row=0;row<n;row++){
                if(isSafe(board, row, col, n)){
                    board[row][col]= 1;
                
                    //is rest of the palcement possible
                    res = solveNQueen(board, col+1, n, ans) || res; 
                     
                       
                    //if rest placement not possible
                    board[row][col] = 0; //backtrack and remove this queen 
                }
            }
            return res;
        }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        //col based sol -> keep each queen in 1 col and then find correct pos
        
        vector<vector<int>> board;
        generateBoard(board, n);
        vector<vector<int>> ans;
        
        ans.clear();
        solveNQueen(board, 0, n, ans);
        sort(ans.begin(), ans.end()); 
        
        return ans;
        
    }
};