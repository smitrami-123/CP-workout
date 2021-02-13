
#include<bits/stdc++.h>
using namespace std;

// Function to return LCM of two numbers using euclidean lemma
long long gcd(long long  a, long long  b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers 
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}


int main()
{
	long long a,b;cin >> a >> b;
	cout << "GCD : " << gcd(a,b) << "\nLCM : " << lcm(a,b) << "\n";
	return 0;
}