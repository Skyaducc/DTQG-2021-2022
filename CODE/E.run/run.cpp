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
using namespace std;
const int oo = 1e9;
const int MAXN = 1e6 + 1;
int n , k;
int a[MAXN] , f[MAXN] , ans[MAXN];
int get(int l , int r)
{
	return f[r] - f[l-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("run.inp" , "r" , stdin);
    freopen("run.out" , "w" , stdout);
    cin >> n >> k;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    }
    foru (i , 2 , n)
    {
    	f[i] = f[i-1];
    	if(a[i] < a[i-1])	f[i]++;
    }
    int res = 0;
    foru (i , 1 , n)
    {
    	int j = i + n - 1;
    	if(j <= n)
    	{
    		if(get(i , i + n - 1) <= k)	ans[++res] = i;
    	}
    	else
    	{
    		if(get(i + 1 , n) + get(1 , i - 1) + (a[n] > a[1]) <= k) ans[++res] = i;
    	}
    }
    cout << res << endl;
    foru (i , 1 , res)	cout << ans[i] << " ";
    return 0;
}
