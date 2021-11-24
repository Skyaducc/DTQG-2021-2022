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
const int MAXN = 1e6 + 11;
int m , n , k;
int a[MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> m >> n >> k;
    foru (i , 1 , m)	cin >> a[i];
    sort(a + 1 , a + 1 + m);
    int sum = 0;
    foru (i , 1 , n)	sum += a[i];
    int res = -2;
    foru (i , 1 , m - n + 1)
    {
    	int j = i + n - 1;
    	if(a[j] - a[i] <= k)
    	{
    		res = max(res , sum);
    	}
    	sum -= a[i];
    	sum += a[j+1];
    	// cout << sum << endl;
    }
    cout << res;
    return 0;
}
