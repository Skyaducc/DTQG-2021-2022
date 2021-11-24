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
const int oo = 1e18;
const int MAXN = 4e5 + 1;
int n , q , subtask;
int sum[MAXN] , a[MAXN];
void sub12()
{
	while(q--)
	{
		int l , r , b;
		cin >> l >> r >> b;
		int res = -oo;
		int res1 , res2;
		int u = l , v = l , minsum = oo;
		while(v <= r)
		{
			if(a[v] < b)
			{
				u = v + 1;
				v++;
				minsum = oo;
				continue;
			}
			if(minsum > sum[v-1])
			{
				minsum = sum[v-1];
				u = v; 
			}
			if(res < sum[v] - minsum)
			{
				res = sum[v] - minsum;
				res1 = u;
				res2 = v;
			}
			v++;
		}
		if(res == -oo)	cout << 0 << endl;
		else cout << res1 << " " << res2 << endl;
	}
}
void sub3()
{
	
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("maxsum.inp" , "r" , stdin);
    freopen("maxsum.out" , "w" , stdout);
    cin >> subtask >> n >> q;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    	sum[i] = sum[i-1] + a[i];
    }
    if(subtask == 1 || subtask == 2)	sub12();
    if(subtask == 3)	sub4();
    return 0;
}
