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
int a[MAXN] , b[MAXN];
pii pi[MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru(i , 1 , n)
    {
    	cin >> a[i];
    	b[i] = a[i] - i;
    	pi[i] = {b[i] , i};
    }
    sort(pi + 1 , pi + 1 + n);
    int tmp = 0 , ans = 0;
    foru(i , 1 , n)
    {
    	if(pi[i].fi != pi[i-1].fi)
    	{
    	    tmp = 0;
    	    tmp += a[pi[i].se];
    	}
    	else
    	{
    		tmp += a[pi[i].se];
    	}
    	ans = max(ans , tmp);
    }
    cout << ans;
    return 0;
}
