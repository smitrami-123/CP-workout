#include<bits/stdc++.h>
using namespace std;

long long kadane(vector<long long> &arr)
{
	long long best = 0,sum=0;
	long long n = arr.size();
	for(long long k=0;k<n;k++)
	{
		sum = max(arr[k],sum+arr[k]);
		best = max(best,sum);
	}
	return best;
}

int main()
{
	long long n;cin >> n;
	vector<long long> arr(n);
	for(long long i=0;i<n;i++)  cin >> arr[i];
	cout << kadane(arr) << "\n";
	return 0;
}