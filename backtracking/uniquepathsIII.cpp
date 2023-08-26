/* PROBLEM LINK : ->   https://leetcode.com/problems/unique-paths-iii/description/*/

class Solution {
public:
    int n,m;
    int no =0,ans=0;
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,-1,1};
    void solve(int i , int j, vector<vector<int>>&grid,int ct)
    {
        if(grid[i][j]==2){if(ct==no){ans++;}return;}
        grid[i][j]=-1;
        for(int x=0;x<4;x++)
        {
             int nr = dr[x]+i;
             int nc = dc[x]+j;
             
             if(nr>=0 and nr<n and nc>=0 and nc<m  and grid[nr][nc]!=-1)
             {
                  if(grid[nr][nc]==2){solve(nr,nc,grid,ct);} 
                  else{solve(nr,nc,grid,ct+1); }
             }
        }
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        int x,y;
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                  if(grid[i][j]==0){no++;}
                  if(grid[i][j]==1){x=i;y=j;}
             }
         }
        
         solve(x,y,grid,0);
         return ans;
    }
};
