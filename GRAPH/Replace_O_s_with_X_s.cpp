class Solution {
public:
    int drow[4]={-1,1,0,0};
    int dcol[4]={0,0,-1,1};
    
    void DFS(vector<vector<char>>& board,vector<vector<int>>& visited,int i,int j)
    {
        int m=board.size();
        int n=board[0].size();
        visited[i][j]=true;
        
        for(int k=0;k<4;k++)
        {
            int nr=i+drow[k];
            int nc=j+dcol[k];
            if(nr>=0 && nc>=0 && nr<m && nc<n && !visited[nr][nc] && board[nr][nc]=='O')
            {
                DFS(board,visited,nr,nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        // Code here
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,false));
        for(int i=0;i<n;i++)
        {
            if(!visited[0][i] && board[0][i]=='O')
            {
                DFS(board,visited,0,i);
            }
            if(!visited[m-1][i] && board[m-1][i]=='O')
            {
                DFS(board,visited,m-1,i);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(!visited[j][0] && board[j][0]=='O')
            {
                DFS(board,visited,j,0);
            }
            if(!visited[j][n-1] && board[j][n-1]=='O')
            {
                DFS(board,visited,j,n-1);
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
        
    }
};