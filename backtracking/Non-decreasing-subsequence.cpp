//https://leetcode.com/problems/non-decreasing-subsequences/description/
class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void solve(int index,vector<int>&nums,vector<int>&temp)
    {
        if(temp.size()>=2){ans.push_back(temp);}
          for(int i=index;i<n;i++)
          {
              if(temp.empty() or temp.back()<=nums[i])
              {
                   temp.push_back(nums[i]);
                   solve(i+1,nums,temp);
                   temp.pop_back();
              }
          }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
         n  = nums.size() ;
         vector<int>temp;
         solve(0,nums,temp);
         set<vector<int>>st;
         for(auto it:ans)
         {
             st.insert(it);
         }
         vector<vector<int>>res;
         for(auto it:st){res.push_back(it);}
         return res;
    }
};
