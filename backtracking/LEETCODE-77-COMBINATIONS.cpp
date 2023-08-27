//https://leetcode.com/problems/combinations/description/
class Solution {
public:
    void solve(int index, int k , int n , vector<int>&temp, vector<vector<int>>&ans)
    {
         if(temp.size()==k)
         {
             ans.push_back(temp);
             return;
         }
         for(int i=index;i<=n;i++)
         {
             temp.push_back(i);
             solve(i+1,k,n,temp,ans);
             temp.pop_back();
         }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(1,k,n,temp,ans);
        return ans;
    }
};
