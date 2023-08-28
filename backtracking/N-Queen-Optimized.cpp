//https://leetcode.com/problems/n-queens/description/
//optimizing the ispossible function which was O(n) now instead of that we would use hashing 
class Solution {
public:
    vector<vector<string>>ans;
    void solve(int col,vector<string>&v,int n,vector<int>&left,vector<int>&lower,vector<int>&upper)
    {
        if(col>=n)
        {
            ans.push_back(v);
            return;
        }
         for(int i=0;i<n;i++)
         {
             if(left[i]==0 and lower[i+col]==0 and upper[n-1+(col-i)]==0)
             {
                 left[i]=1;lower[i+col]=1;upper[n-1+col-i]=1;
                 v[i][col]='Q';
                 solve(col+1,v,n,left,lower,upper);
                 v[i][col]='.';
                 left[i]=0;lower[i+col]=0;upper[n-1+col-i]=0;
             }
         }
    }
    vector<vector<string>> solveNQueens(int n) {
          vector<string>v(n);
          string s(n,'.');
          vector<int>left(n,0);
          vector<int>upper(2*n-1,0),lower(2*n-1,0);
          for(int i=0;i<n;i++)
          {
              v[i]=s;
          }
          solve(0,v,n,left,lower,upper);
          return ans;
    }
};
