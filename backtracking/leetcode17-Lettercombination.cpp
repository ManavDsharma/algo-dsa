//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
class Solution {
public:
    void solve(int index,string &temp,vector<string>&ans,vector<string> &v,string &s)
    {
        if(temp.size()==s.size())
        {
            ans.push_back(temp);
            return;
        }
         string x = v[s[index]-'0'];
          for(int i=0;i<x.size();i++)
          {
              temp.push_back(x[i]);
              solve(index+1,temp,ans,v,s);
              temp.pop_back();
          }
    }
    vector<string> letterCombinations(string digits) {
          vector<string>ans;
        if(digits==""){return ans;}
        vector<string>v(10);
        v[2]="abc",v[3]="def",v[4]="ghi",v[5]="jkl",v[6]="mno",v[7]="pqrs",v[8]="tuv",v[9]="wxyz";
        string temp="";
        solve(0,temp,ans,v,digits);
        return ans;
    }
};
