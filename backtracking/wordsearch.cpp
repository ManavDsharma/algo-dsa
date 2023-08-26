/*https://leetcode.com/problems/word-search/description/ */


class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    int n,m;
    bool solve(int i, int j,vector<vector<char>>&board,int idx,string word)
    {
         if(idx==word.size()){return true;}
         if(i<0 or i>=n or j<0 or j>=m or board[i][j]=='.' ){return false;}
         if(board[i][j]!=word[idx]){return false;}
        char c = board[i][j];
        board[i][j]='.';
         for(int x=0;x<4;x++)
         {
              int nr = dr[x]+i;
              int nc = dc[x]+j;

              if(solve(nr,nc,board,idx+1,word)==true){return true;}
         }
         board[i][j]=c;
         return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
          n = board.size();
          m = board[0].size();

         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                  if(word[0]==board[i][j] and solve(i,j,board,0,word)){return true;}
             }
         }
         return false;
    }
};
