#define SVR "CreatedBySmitRami"

///////////////////////Loading Payloads.......////////////////////////////
#include<bits/stdc++.h>
#define f(i,a,b) for(int i = a; i < b; i++)
#define fd(i,a,b) for(int i = a; i > b;i--)
#define ll long long
#define fl(i,a,b) for(ll i = a; i < b; i++)
#define VI vector<int>
#define VP vector<pair<int,int>>
#define VS vector<string>
#define VL vector<long long>
#define VC vector<char>
#define VF vector<float>
#define PB push_back
#define debug2(x,y) cout<<"This side ----> "<<#x<<" -> "<<x<<" | "<<#y<<" -> "<<y<<endl;
#define debug(x) cout<<"This side    ----> "<<#x<<" -> "<<x<<endl
#define F first
#define S second
#define fa(i,skill) for(auto i : skill)
#define fr(i,skill) for(VI :: reverse_iterator i = skill.rbegin(); i != skill.rend(); i++)
#define PI pair<int,int>
#define mi map<int,int>
#define mci map<char,int>
#define all(x) x.begin(),x.end()
#define MAX 1000000007
using namespace std;

///////////////////////Engine Check.......////////////////////////////
void edit(VI &skill,int n)
{
    f(i,0,n)
        {
            int x;
            cin >> x;
            skill.PB(x);
        }
}

void editl(VL &skill,ll n)
{
    fl(i,0,n)
        {
            ll x;
            cin >> x;
            skill.PB(x);
        }
}


ll block[1001];

ll build_sqrt_block(VL &arr)
{
    ll n = arr.size();
    ll N = ceil(sqrt(n));

    //for_sum_query
    /*f(i,0,N)
    {
        block[i]=0;
    }

    f(i,0,n)
    {
        block[i/N]+=arr[i];
    }*/


    //for_max_query
    /*f(i,0,N)
    {
        block[i]=-MAX;
    }

    f(i,0,n)
    {
        if(block[i/N] < arr[i])block[i/N]=arr[i];
    }*/

    //for_min_query
    f(i,0,N)
    {
        block[i]= MAX;
    }

    f(i,0,n)
    {
        if(block[i/N] > arr[i])block[i/N]=arr[i];
    }

    return N;
}

ll qmin_sqrt(ll l, ll r , ll N , VL &arr)
{
    l--;
    r--;
    ll LB = l/N, RB = r/N;
    ll mn = MAX;
    if(LB==RB)
    {
        fl(i,l,r+1)
        {
            if(arr[i]<mn) mn = arr[i];
        }
        return mn;
    }

    if(l%N==0) 
        {if(block[LB] < mn) mn = block[LB];}
    else
    {
        while(l%N)
        {
            if(arr[l] < mn)mn = arr[l];
            l++;
        }
    }

    fl(i,LB+1,RB)
        if(mn > block[i]) mn = block[i];


    if((r+1)%N==0)
        {if(block[RB] < mn)mn=block[RB];}
    else
    {
        while(r%N != N-1)
        {
            if(arr[r] < mn)mn = arr[r];
            r--;
        }

    }

    return mn;
}

ll qsum_sqrt(ll l, ll r , ll N , VL &arr)
{
    l--;
    r--;
    ll LB = l/N, RB = r/N;
    ll sm = 0;
    if(LB==RB)
    {
        fl(i,l,r+1)
        {
            sm += arr[i];
        }
        return sm;
    }

    if(l%N==0) 
        {sm += block[LB];}
    else
    {
        while(l%N)
        {
            sm += arr[l];l++;
        }
    }

    fl(i,LB+1,RB)
        sm += arr[i];


    if((r+1)%N==0)
        {sm += block[RB];}
    else
    {
        while(r%N != N-1)
        {
            sm += arr[r];
            r--;
        }

    }

    return sm;
}

ll qmax_sqrt(ll l, ll r , ll N , VL &arr)
{
    l--;
    r--;
    ll LB = l/N, RB = r/N;
    ll mx = -MAX;
    if(LB==RB)
    {
        fl(i,l,r+1)
        {
            if(arr[i]>mx) mx = arr[i];
        }
        return mx;
    }

    if(l%N==0) 
        {if(block[LB] > mx) mx = block[LB];}
    else
    {
        while(l%N)
        {
            if(arr[l] > mx)mx = arr[l];
            l++;
        }
    }

    fl(i,LB+1,RB)
        if(mx < block[i]) mx = block[i];


    if((r+1)%N==0)
        {if(block[RB] > mx)mx=block[RB];}
    else
    {
        while(r%N != N-1)a
        {
            if(arr[r] > mx)mx = arr[r];
            r--;
        }

    }

    return mx;
}

void achilles()
{
        ll n;cin >> n;
        VL arr;editl(arr,n);
        ll N = build_sqrt_block(arr);
        ll q;cin >> q;
        fl(i,0,q)
        {
            ll l,r;cin >> l >> r;
            cout <<i+1 << " : "<< qmin_sqrt(l,r,N,arr) << "\n";

        }
        
}

///////////////////////3....2....1...Ignition////////////////////////////

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("out.txt","w",stdin);
    
    ll t;cin >>t ;
    while(t--)
    {achilles();}
    return 0;
}