//https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/
class Solution {
public:
    int mini = INT_MIN;
    int m ;
    void solve(int index, vector<vector<int>>&requests,vector<int>&house,int count)
    {
            if(index>=m)
            {
                if(*max_element(house.begin(),house.end())==0)
                {
                    mini = max(mini,count);
                }
                return;
            }
            int x = requests[index][0],y=requests[index][1];
            house[x]--; house[y]++;
            count++;
            
            solve(index+1,requests,house,count);
            house[x]++; house[y]--;count--;
            solve(index+1,requests,house,count);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m =requests.size();
        vector<int>houses(n,0);
        solve(0,requests,houses,0);
        return mini;
    }
};
