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
const int oo = 1e9 + 11;
const int MAXN = 2e5 + 11;
int test , n;
int a[MAXN];
int f[MAXN][21][2];
int Get(int l , int r , int x)
{
	if(r < l)	return (!x) ? oo : 0;
	int k = log2(r - l + 1);
	return (!x) ? min(f[l][k][x] , f[r-(1<<k)+1][k][x]) : max(f[l][k][x] , f[r-(1<<k)+1][k][x]);  
}
int get_left(int l , int r , int x)
{
	int ans = 0;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		int temp = Get(mid , n , 1);
		if(temp <= x)
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ((Get(ans , n , 1) == x) ? ans : 0); 
}
int get_right(int Left , int r , int x)
{
	int ans = 0 , l = Left;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		int temp = Get(Left , mid , 0);
		if(temp <= x)
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ((Get(Left , ans , 0) == x) ? ans : n + 1);
}
void solve()
{
	cin >> n;
	foru (i , 1 , n)
	{
		cin >> a[i];
		f[i][0][0] = f[i][0][1] = a[i];
	}
	foru (j , 1 , 19)
	{
		foru (i , 1 , n - (1 << j) + 1)
		{
			f[i][j][0] = min(f[i][j-1][0] , f[i+(1<<(j-1))][j-1][0]);
			f[i][j][1] = max(f[i][j-1][1] , f[i+(1<<(j-1))][j-1][1]);
		}
	}
	int Ma = 0;
	foru (i , 1 , n - 2)
	{
		Ma = max(Ma , a[i]);
		int pos1 = get_right(i + 1 , n - 1 , Ma);
		int pos2 = get_left(pos1 + 1 , n , Ma);
		int tmp = Get(i + 1 , pos2 - 1 , 0);
		if(tmp == Ma)	
		{
			cout << "YES" << endl << i << " " << pos2 - 1 - i << " " << n - pos2 + 1 << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}