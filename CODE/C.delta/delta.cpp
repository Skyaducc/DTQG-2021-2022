#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int , int>
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
const int oo = 2e9;
const int MAXN = 5e5 + 1;
const int MOD = 998244353;
int subtask , n , d;
int a[MAXN];
int f[MAXN];
int Pow(int a , int b)
{
	if(b == 0)	return 1;
	if(b == 1)	return a;
	int tmp = Pow(a , b / 2);
	if(b % 2 == 0)	return tmp * tmp % MOD;
	else return tmp * tmp % MOD * a % MOD;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("delta.inp" , "r" , stdin);
    freopen("delta.out" , "w" , stdout);
    cin >> subtask >> n >> d;
    foru (i , 1 , n)	
    {
    	cin >> a[i];
    }
    deque<int> dq;
    a[n+1] = oo;
    int res = 0 , res1 = 0;
    foru (i , 1 , n)
    {
    	while(dq.size() && abs(a[dq.front()] - a[i]) > d)	dq.pop_front();
    	if(!dq.size())	res++;
    	else res += i - dq.front() + 1;
    	if(res >= MOD) res -= MOD;
    	dq.push_back(i);
    }
    sort(a + 1 , a + 1 + n);
    foru (i , 1 , n)
    {
    	int pos = lower_bound(a + 1 , a + 1 + n , a[i] + d + 1) - a;
    	res1 = (res1 + Pow(2 , pos - i - 1) % MOD) % MOD;
    }
    cout << res << " " << res1;
    return 0;
}