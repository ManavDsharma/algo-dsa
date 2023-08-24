#include<bits/stdc++.h>
using namespace std;
int main()
{
	// enter the matrix
	int n,m;
	cin>>n>>m;
	int matrix[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>matrix[i][j];
		}
	}
 
 // lets precompute the prefix sum of the 2d array

	int prefix[n+1][m+1];
	memset(prefix,0,sizeof(prefix));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
            prefix[i][j]= matrix[i-1][j-1]+prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1];
		}
	}

 // printing the 2d prefix sum array 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<prefix[i][j]<<" ";
		}
		cout<<endl;
	}


	// now let suppose we got q queries and we have to calculate sum of the rectangel (a,b)=>starting ending=>(c,d)
    int q;cin>>q;
	while(q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;

		cout<<prefix[c][d]-prefix[a-1][d]-prefix[c][b-1]+prefix[a-1][b-1]<<endl;
	}

}