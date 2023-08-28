//https://leetcode.com/problems/n-queens/description/

class Solution {
public:
    vector<vector<string>>ans;
    bool ispossible(int row,int col,vector<string>&v,int n)
    {
         int r = row,c=col;

         while(col>=0)
         {
             if(v[row][col]=='Q')return false;
             col--;
         }
         col=c;
         while(row>=0 and col>=0)
         {
             if(v[row][col]=='Q')return false;
             row--;col--;
         }
         row=r;col=c;
         while(row<n and col>=0)
         {
             if(v[row][col]=='Q')return false;
             row++; col--;
         }
         return true;
    }
    void solve(int col,vector<string>&v,int n)
    {
        if(col>=n)
        {
            ans.push_back(v);
            return;
        }
         for(int i=0;i<n;i++)
         {
             if(ispossible(i,col,v,n))
             {
                 v[i][col]='Q';
                 solve(col+1,v,n);
                 v[i][col]='.';
             }
         }
    }
    vector<vector<string>> solveNQueens(int n) {
          vector<string>v(n);
          string s(n,'.');
          for(int i=0;i<n;i++)
          {
              v[i]=s;
          }
          solve(0,v,n);
          return ans;
    }
};
