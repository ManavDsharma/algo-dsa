//https://leetcode.com/problems/combinations/description/
class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void solve(int index,vector<int>&temp,vector<int>&nums,int freq[])
    {
         if(temp.size()==n)
         {
             ans.push_back(temp);
             return;
         }
         for(int i=0;i<n;i++)
         {
             if(freq[i]==0)
             {
                 temp.push_back(nums[i]);
                 freq[i]=1;
                 solve(i+1,temp,nums,freq);
                 temp.pop_back();
                 freq[i]=0;
             }
         }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int>temp;
        int freq[11]={0};
        solve(0,temp,nums,freq);
        return ans;
    }
};
