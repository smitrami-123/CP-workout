
///////////////////////Loading Payloads.......////////////////////////////
#include<bits/stdc++.h>
using namespace std;

// this is 50000 x 50000 matrix 
vector<vector<int>> paths(1000,vector<int>(1000));

// by calling total_paths[x][y] you can get the total number of ways to 
// reach from cell (0,0) to cell (x,y) in the grid.
// taken modulo because the number of path increases to very big number 

int total_paths(int x,int y)
{
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			if(i==0 && j==0)
				paths[i][j]=0;
			else if(i==0 || j == 0)
				paths[i][j]=1;
			else 
				paths[i][j] = (paths[i][j-1]%1000000007 + paths[i-1][j]%1000000007)%1000000007;
		}
	}

	return paths[x][y];
}
int main()
{
	cout << total_paths(999,999)<<"\n";
	
	return 0;
}