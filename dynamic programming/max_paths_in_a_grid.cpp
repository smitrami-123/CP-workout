
///////////////////////Loading Payloads.......////////////////////////////
#include<bits/stdc++.h>
#define dt int
using namespace std;

dt max_path(vector<vector<dt>> &arr)
{
	int n = arr.size();
	int sum[n+1][n+1];
	for(dt i=0;i<n+1;i++)
	{
		for(dt j=0;j<n+1;j++)
		{
			if(i==0 || j == 0)
				sum[i][j] = 0;
			else 
				sum[i][j] = max(sum[i-1][j],sum[i][j-1])+arr[i-1][j-1];
		}
	}

	return sum[n][n];
}

int main()
{
	int n;cin >> n;
	vector<vector<dt>> arr(n,vector<dt>(n));
	for(dt i=0;i<n;i++)
	{
		for(dt j=0;j<n;j++)

		cin >> arr[i][j];
	}

	cout << max_path(arr) << "\n";
	return 0;
}