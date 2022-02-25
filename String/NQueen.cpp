
#include <vector>
#include <iostream>
using namespace std;

int noOfStateSpaceNodes =0;
vector<vector<int> > board1;
vector<vector<int> > board2;

bool validPos(int row, int col, int N){
    return row>=0 && row<N && col>=0 && col<N;
}

bool upperDiagonal(vector<vector<int> > board, int row, int col, int N){
    int i = row, j = col;
    while(validPos(i,j, N)){
        if (board[i][j])
            return false;
        i++;
        j++;
    }
    i=row-1;
    j=col-1;
    while(validPos(i,j, N)){
        if (board[i][j])
            return false;
        i--;
        j--;
    }
    return true;
}

bool lowerDiagonal(vector<vector<int> > board, int row, int col, int N){
    int i = row, j = col;
    while(validPos(i,j, N)){
        if (board[i][j])
            return false;
        i--;
        j++;
    }
    i=row+1;
    j=col-1;
    while(validPos(i,j, N)){
        if (board[i][j])
            return false;
        i++;
        j--;
    }
    return true;
}

vector<vector<int> > generateBoard(vector<vector<int> > board, int n){
    vector<int> row;
     for(int i=0;i<n;i++){   
        for(int j=0;j<n;j++){
                row.push_back(0);
            }
        board.push_back(row);
    }
    return board;

}


bool isSafe(vector<vector<int> > board, int row, int col, int N)
{
    int i, j;

    // Check this row 
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check this col 
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    if(!upperDiagonal(board, row, col, N)){
        return false;
    }
    
    if(!lowerDiagonal(board, row, col, N)){
        return false;
    }

    return true;
}

bool solveNQUtil(vector<vector<int> > board, int col, int N)
{
      noOfStateSpaceNodes++;
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1, N))
                return true;
            board[i][col] = 0;
        }
    }
    board1 = board;

    return false;
}

 bool isValidBoard(vector<vector<int> > board, int N){
    for(int row=0;row<N;row++){
        for (int col=0;col<N;col++){
            if (board[row][col] == 1){
                board[row][col] = 0;
                if (!isSafe(board,  row, col, N)){
                    board[row][col] = 1;
                    return false;
                }
                board[row][col] = 1;
                
            }
        }
    }
    return true;
 }

 void printSolution(vector<vector<int> > board, int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool solveNQExhaustive(vector<vector<int> > board, int row, int N){
      noOfStateSpaceNodes++;
    if (row >= N)
        return isValidBoard(board, N);

    for (int i = 0; i < N; i++) {
        board[row][i] = 1;
        if (solveNQExhaustive(board, row + 1, N))
            return true;
        board[row][i] = 0; 
        
    }
    board2 = board;
    return false;
}



bool solveNQ( int N )
{
    board1 = generateBoard(board1, N);
    if (solveNQUtil(board1, 0, N) == false) {
        cout<<"Solution does not exist Backtracking";
        return false;
    }
    printSolution(board1, N);
    cout<<"Space State Nodes Backtracking: " << noOfStateSpaceNodes;

    cout<<endl;
    cout<<endl;


    noOfStateSpaceNodes = 0;
    board2 = generateBoard(board2, N);
    if (solveNQExhaustive(board2, 0, N) == false) {
        cout<<"Solution does not exist Exhaustive";
        return false;
    }
    printSolution(board2, N);
    cout<<"Space State Nodes Exhaustive: " << noOfStateSpaceNodes;
    cout<<endl;
    return true;
}


bool compareBacktrackVsExhaustive(int N){
    cout<<N;
    cout<<"\t\t\t";

    board1.clear();
    noOfStateSpaceNodes = 0;
    board1 = generateBoard(board1, N);
    solveNQUtil(board1, 0, N);
    cout<<noOfStateSpaceNodes;

    cout<<"\t\t\t";

    board2.clear();
    noOfStateSpaceNodes = 0;
    board2 = generateBoard(board2, N);
    solveNQExhaustive(board2, 0, N);
    cout<<noOfStateSpaceNodes;
    return true;
}


int main()
{
    cout<<endl;
    int noOfQueen = 6;
    solveNQ(noOfQueen);

    
    cout<<endl;
    cout<<"No Of Queen\tSSN Backtracking\tSSN Exhaustive"<<endl;
    for(int i=1;i<=noOfQueen;i++){
        noOfStateSpaceNodes = 0;
        compareBacktrackVsExhaustive(i);
        cout<<endl;
    }
    
    return 0;
}