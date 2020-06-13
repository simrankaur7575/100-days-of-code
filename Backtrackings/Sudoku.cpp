
bool FindUnassignedLocation(int board[][9],int &r,int & c)
{
    for(r=0;r<9;r++)
    {
        for(c=0;c<9;c++)
        {
            if(board[r][c]==0)
            {
                return true;
            }
        }
    }
    return false;
}

bool funRow(int board[][9],int r,int n)
{
    for(int c=0;c<9;c++)
    {
        if(board[r][c]==n)
        {
            return false;
        }
    }
    return true;
}

bool funCol(int board[][9],int c,int n)
{
    for(int r=0;r<9;r++)
    {
        if(board[r][c]==n)
        {
            return false;
        }
    }
    return true;
}

bool funBox(int board[][9],int r,int c,int n)
{
   
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[r+i][c+j]==n)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int board[][9],int n,int r, int c)
{
    return funRow(board,r,n) && funCol(board,c,n) && funBox(board,r-r%3,c-c%3,n) ;
}

/*
  void printGrid(int board[][9])  
{  
    for (int row = 0; row < 9; row++)  
    {  
    for (int col = 0; col < 9; col++)  
            cout << board[row][col] << " ";  
        cout << endl; 
    }  
}  
*/


bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    
 

    int r,c;
    if(!FindUnassignedLocation(board,r,c))
    {
        //printGrid(board);
        return true;
    }
    
    for(int n=1;n<=9;n++)
    {
        if(isSafe(board,n,r,c))
        {
            board[r][c]=n;
            
            if(sudokuSolver(board))
            {
                return true;
            }
            
            board[r][c]=0;
            
        }
    }
    
    
return false;
    
}
