#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl; 
#define int long long
using namespace std;
const int oo = 1e9;
const int MAXN = 1e6 + 1;
int n;
int a[MAXN] , sum[MAXN] , minsum[MAXN] , prime[MAXN];
void eratos()
{
	prime[0] = prime[1] = 1;
	foru (i , 2 , MAXN)
	{
		if(prime[i] == 0)
		{
			for (int j=i*2 ; j<=MAXN ; j+=i)
			{
				prime[j] = 1;
			}
		}
	} 
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    eratos();
    cin >> n;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    	sum[i] = sum[i-1] + a[i];
    }
    memset(minsum , 0x3f , sizeof(minsum));
    int res = 0;
    foru (i , 1 , n)
    {
    	minsum[i] = min(minsum[i] , minsum[i-1]);
    	if(!prime[i])	res = max(res , sum[i] - minsum[i]);
    	if(!prime[i])	minsum[i] = min(minsum[i] , sum[i-1]);
    }
    if(res == 0)	cout << -1;
    else	cout << res;
    return 0;
}
