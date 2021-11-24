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
#define ll long long
#define int long long
using namespace std;
const int oo = 1e18;
const int MAXN = 2e5 + 1;
int n , m , k;
int a[MAXN];
ll dp[MAXN][2];
void sub2()
{
	foru (x , 1 , k)
	{
		foru (i , 1 , n)
		{
			bool cur = x & 1;
			bool pre = !cur;
			ll ma = 0;
			ford (j , i - 1 , max(1LL , i - m))
			{
				ma = max(ma , dp[j][pre]);
			}
			dp[i][cur] = ma + 1LL * a[i] * x;
		}
	}
	ll ans = 0;
	foru (i , 1 , n)	ans = max(ans , dp[i][k & 1]);
	cout << ans;
}
void subfull()
{
	foru (x , 1 , k)
	{
		bool cur = x & 1;
		bool pre = !cur;
		deque<int> dq;
		foru (i , 1 , n)
		{
			while(dq.size() && dq.front() < i - m)	dq.pop_front();
			ll ma = (dq.empty()) ? -oo : dp[dq.front()][pre];
			dp[i][cur] = ma + 1LL * a[i] * x;
			while(dq.size() && dp[dq.back()][pre] <= dp[i][pre])	dq.pop_back();
			dq.push_back(i);
		}
	}
	ll ans = 0;
	foru (i , 1 , n)	ans = max(ans , dp[i][k & 1]);
	cout << ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> k;
    foru (i , 1 , n)	cin >> a[i];
    // if(n <= 2000)	sub2();
    // else subfull();
    subfull();
    return 0;
}
