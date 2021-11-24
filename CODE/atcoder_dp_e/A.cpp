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
const int MAXN = 1e5 + 1;
int n , W;
int w[101] , v[101];
int dp[101][MAXN];
int solve(int idx , int sum)
{
	if(idx == n + 1)	return sum == 0 ? 0 : oo;
	if(dp[idx][sum] != -1)	return dp[idx][sum];
	int ret = solve(idx + 1 , sum);
	if(v[idx] <= sum)	ret = min(ret , w[idx] + solve(idx + 1 , sum - v[idx]));
	return dp[idx][sum] = ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> W;
    int sum = 0;
    foru (i , 1 , n)
    {
    	cin >> w[i] >> v[i];
    	sum += v[i];
    }
    memset(dp , -1 , sizeof(dp));
    ford (i , sum , 0)
    {
    	if(solve(1 , i) <= W)
    	{
    		cout << i << endl;
    		return 0;
    	}
    }
    return 0;
}