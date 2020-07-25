/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

bool isSafe(vector<vector<string> > &testboard, int row, int col,int n) 
{ 
    /* Check this col on upper side */
    for (int i = 0; i < row; i++) 
        if (testboard[i][col]=="Q") 
            return false; 

    /* Check upper diagonal on left side */
    int x=row,y=col;
    while(x>=0 && y>=0)
    {
        if (testboard[x][y]=="Q") 
            return false; 
        x--;y--;
    }

    /* Check lower diagonal on left side */
    x=row,y=col;
    while(x>=0 && y<n)
    {
        if (testboard[x][y]=="Q") 
            return false; 
        x--;y++;
    }

    return true; 
} 

bool putQueens(vector<vector<string> >&board, int row,vector<vector<string> > &testboard, int n) 
{ 
//    cout<<" Call for"<<row<<"  n: "<<n<<endl;
    if (row == n)
    {
    //    cout<<" On board "<<endl;
        vector<string>emptyRow;
        board.emplace_back(emptyRow);
        int size = board.size();
        for(int i=0;i<n;i++)
        {
            string cur_row="";
            for(int j=0;j<n;j++)
            {
                cur_row+=testboard[i][j];
        //    if(testboard[i][j]=="Q")    cout<<testboard[i][j]<<" ";
            }
        //    cout<<endl;
            board[size-1].emplace_back(cur_row);
        }
        
        return false;
    }

    for (int j = 0; j < n; j++)
    { 
        if (isSafe(testboard,row, j,n))
        { 
            testboard[row][j] ="Q";
        //    cout<<testboard[row][j]<<" "<<endl;
        //    cout<<" j: "<<j<<" row: "<<row<<endl;
            bool nextQueenStable = putQueens(board,row+1,testboard,n);
        //    cout<<" next Q: "<<nextQueenStable<<endl;
            if (nextQueenStable) 
                return true; 
            else
                testboard[row][j] = "."; // BACKTRACK 
        } 
    } 
    return false; 
} 

vector<vector<string> > Solution::solveNQueens(int n) 
{
    vector<vector<string> > testboard;
    
    if (n==2 || n==3)
        return testboard;
    
    vector<string> row(n, ".");
    
    for (int i = 0; i<n; ++i)
        testboard.emplace_back(row);
    
    vector<vector<string> > board;
    putQueens(board, 0, testboard, n);
    return board;
}
