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
const int MAXN = 300111;
const int MOD = 1e9 + 9;
string s;
int n;
int f[MAXN];
int cnt[MAXN][26] , pos[MAXN][26] , bit[MAXN][26];
void update(int id , int x , int val)
{
	while(x <= n)
	{
		bit[x][id] = (bit[x][id] + val) % MOD;
		x += x & -x;
	}
}
int Get(int id , int x)
{
	int res = 0;
	while(x > 0)
	{
		res = (res + bit[x][id]) % MOD;
		x -= x & -x;
	}
	return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("tourguide.inp" , "r" , stdin);
    freopen("tourguide.out" , "w" , stdout);
    cin >> s;
    n = s.length();
    s = " " + s;
    foru (i , 0 , n)
    {
    	int x = s[i] - 'a';
    	foru (j , 0 , 25)
    	{
    		if(x == j)	cnt[i][j] = cnt[i-1][j] + 1;
    		else cnt[i][j] = cnt[i-1][j];
    	}
    }
    foru (j , 0 , 25)
    {
    	vector<int> v;
    	foru (i , 0 , n)
    	{
    		pos[i][j] = cnt[i][j] * 2 - i;
    		v.push_back(pos[i][j]);
    	}
    	sort(v.begin() , v.end());
		v.resize(unique(v.begin() , v.end()) - v.begin());
    	foru (i , 0 , n)
    	{
    		pos[i][j] = lower_bound(v.begin() , v.end() , pos[i][j]) - v.begin() + 1;
    		// cout << pos[i][j] << endl;
    	}
    }
    f[0] = 1;
    int res = f[0];
    foru (i , 0 , 25)	update(i , pos[0][i] , f[0]);
    foru (i , 1 , n)
    {
    	f[i] = res;
    	// cout << f[i] << " ";
    	foru (j , 0 , 25)	f[i] = (f[i] - Get(j , pos[i][j] - 1) + MOD) % MOD;
    	// cout << f[i] << endl;
    	foru (j , 0 , 25)	update(j , pos[i][j] , f[i]);
    	res = (res + f[i]) % MOD;
    }
    cout << f[n] << endl;
    return 0;
}
