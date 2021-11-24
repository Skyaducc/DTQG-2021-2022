 // abba
// để tính k-pd : tính số lượng xâu (k-1)-pd giống nhau và có khoảng cách là 0 || 1
// tính k-pd của một xâu (l , r)
#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
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
const int MAXN = 5011;
const int BASE = 131;
const int MOD = 1e9 + 7;
const long long MM = 1LL * MOD * MOD;
string s;
int res[MAXN];
long long Hash[MAXN] , Hash1[MAXN] , POW[MAXN];
int n;
void init()
{
	POW[0] = 1;
	foru (i , 1 , n)
  {
        POW[i] = POW[i-1] * BASE % MOD;
        Hash[i] = (Hash[i-1] * BASE + s[i]) % MOD;
  }
	ford (i , n , 1)	Hash1[i] = (Hash1[i+1] * BASE + s[i]) % MOD;
}
int get_hash(int l , int r)
{
	return (Hash[r] - Hash[l-1] * POW[r-l+1] + MM) % MOD;
}
int get_hash1(int l , int r)
{
	return (Hash1[l] - Hash1[r+1] * POW[r-l+1] + MM) % MOD;
}
bool check(int l , int r , int u , int v)
{
	return (get_hash(l , r) == get_hash(u , v));
}
bool check_palindrome(int l , int r)
{
	return (get_hash(l , r) == get_hash1(l , r));
}
int dp[MAXN][MAXN];
int Calc(int l , int r)
{
		if(dp[l][r] != -1) return dp[l][r];
		if(l == r)	return 1;
		int mid = (l + r ) / 2;
		int p = (((r - l + 1) % 2) ? 1 : 0);
		if(!check_palindrome(l , r)) return 0;
		if(!check(l , mid - p , mid + 1 , r)) return 1;
		return dp[l][r] = min(Calc(l , mid - p) , Calc(mid + 1 , r)) + 1;
}
main()
{
	    ios_base::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
	    freopen("A.INP" , "r" , stdin);
	    freopen("A.OUT" , "w" , stdout);
	    cin >> s;
	    n = s.length();
	    s = " " + s;
	    memset(dp , -1 , sizeof(dp));
	    init();
	    foru (i , 1 , n)
	    {
		    	foru (j , i , n)
		    	{
		    			int tmp = Calc(i , j);
		    			// cout << i << " " << j << " " << tmp << endl;
		    			res[tmp]++;
		    	}
		  }
		  ford (i , n , 1)	res[i] += res[i+1];
	    foru (i , 1 , n)	cout << res[i] << " "; 
	    return 0;
}