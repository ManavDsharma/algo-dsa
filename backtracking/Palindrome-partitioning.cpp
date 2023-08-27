//https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string>>ans;
    int n;
    //a b b a 
    //a b c b a
    bool ispalindrome(string x)
    {
        int low =0 , high =x.size()-1;
        while(low<=high)
        {
            if(x[low]!=x[high]){return false;}
            low++;high--;
        }
        return true;
    }
    void solve(int index,string s,vector<string>&temp)
    {
       
        
        if(index>=n)
        {
            if(temp.size()){ans.push_back(temp);}
            return;
        }
       
        for(int i=1;i<=s.size();i++)
        {
              if(index+i>n){return;}
              string t = s.substr(index,i);
              if(ispalindrome(t))
              {
                  temp.push_back(t);
                  solve(index+i,s,temp);
                  temp.pop_back();
              }
        }
    }
    vector<vector<string>> partition(string s) {
        n= s.size();
        vector<string>temp;
        string t;
        solve(0,s,temp);
        return ans;
    }
};
