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
int n;
set<pii> s;
map<long long, int> getFactor(long long x) 
{
	map<long long, int> res;
	for (int i = 2; 1LL * i * i <= x; i++) if (x % i == 0) 
	{
		while (x % i == 0) 
		{
			res[i]++;
			x /= i;
		}
		s.insert({i , res[i]});
	}
	if (x > 1)
	{
		res[x] = 1;
		s.insert({x , res[x]});
	}
	return res;
}
map<long long , int> mp;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    mp = getFactor(n);
    if(s.size() != 3)
    {
    	cout << "NO";
    	return 0;
    }
    int res = 0;
    for (auto x : s)	res += (x.se == 1);
    cout << ((res == 3) ? "YES" : "NO");	
    return 0;
}
