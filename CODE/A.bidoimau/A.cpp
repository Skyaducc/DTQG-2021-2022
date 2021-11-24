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
using namespace std;
const int oo = 1e9;
const int MAXN = 501;
int n , m , p;
int a[MAXN][MAXN] , sum[MAXN][MAXN][2];
int f[MAXN][MAXN]; // f(i , j) : hv p * p có số bi đỏ trừ số bi xanh min từ (1 , 1) -> (i , j)
int g[MAXN][MAXN]; // g(i , j) : hv p * p có số bi đỏ trừ số bi xanh min từ (n , m) -> (i , j)
int Get(int i , int j , int u , int v , int x)
{
	return sum[u][v][x] - sum[u][j-1][x] - sum[i-1][v][x] + sum[i-1][j-1][x];
}
struct Data
{
	int i , j , u , v;
};
Data get_hcngiao(int i , int j , int u , int v)
{
	int ii = i + p - 1 , jj = j + p - 1;
	int uu = u + p - 1 , vv = v + p - 1;
	return {max(i , u) , max(j , v) , min(ii , uu) , min(jj , vv)};
}
int case1(int i , int j , int u , int v)
{
	Data tmp = get_hcngiao(i , j , u , v);
	int res = sum[n][m][0];
	int x1 = Get(i , j , i + p - 1 , j + p - 1 , 1); 
	int y1 = Get(i , j , i + p - 1 , j + p - 1 , 0);
	int x2 = Get(u , v , u + p - 1 , v + p - 1 , 1);	
	int y2 = Get(u , v , u + p - 1 , v + p - 1 , 0);
	int x3 = Get(tmp.i , tmp.j , tmp.u , tmp.v , 1);
	int y3 = Get(tmp.i , tmp.j , tmp.u , tmp.v , 0);
	// cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	res += x1 - y1 + x2 - y2;
	if (tmp.u - tmp.i >= 0 && tmp.v - tmp.j >= 0) 	res -= 2 * (x3 - y3);
	return res;
}
int case2(int i , int j)
{
	int x = i + p - 1;
	int y = j + p - 1;
	return min({f[i-1][m] , f[n][j-1] , g[1][y+1] , g[x+1][1]});
}
void input()
{
	cin >> n >> m >> p;
	foru (i , 1 , n)
    {
    	string s;
    	cin >> s;
    	foru (j , 0 , m - 1)
    	{
    		if(s[j] == 'r')	a[i][j+1] = 1;
    		if(s[j] == '.')	a[i][j+1] = 2;
    	}
    	foru (j , 1 , m)
    	{
    		foru (x , 0 , 1)
    		{
    			sum[i][j][x] = sum[i-1][j][x] + sum[i][j-1][x] - sum[i-1][j-1][x] + (a[i][j] == x);
    		}
    		f[i][j] = g[i][j] = oo;
    	}
    }
    foru (i , 1 , max(n , m))	
    {
    	f[i][0] = f[0][i] = oo;
    	g[i][0] = g[0][i] = oo;
    }
}
void prepare()
{
	foru (i , p , n)
	{
		foru (j , p , m)
		{
			int x = i - p + 1;
			int y = j - p + 1;
			int cost = Get(x , y , i , j , 1) - Get(x , y , i , j , 0);
			f[i][j] = min({f[i-1][j] , f[i][j-1] , cost});
		}
	}
	ford (i , n - p + 1 , 1)
	{
		ford (j , m - p + 1 , 1)
		{
			int x = i + p - 1;
			int y = j + p - 1;
			int cost = Get(i , j , x , y , 1) - Get(i , j , x , y , 0);
			g[i][j] = min({g[i+1][j] , g[i][j+1] , cost});
		}
	}
}
void solve()
{
	foru (i , 1 , n - p + 1)
	{
		foru (j , 1 , m - p + 1)
		{
			int res = oo;
			foru (u , max(1 , i - p + 1) , min(n - p + 1 , i + p - 1))
			{
				foru (v , max(1 , j - p + 1) , min(m - p + 1 , j + p - 1))
				{
					// cout << i << " " << j << " " << u << " " << v << " " << case1(i , j , u , v) << endl;
					res = min(res , case1(i , j , u , v));
				}
			}
			int x = i + p - 1;
			int y = j + p - 1;
			int tmp = Get(i , j , x , y , 1) - Get(i , j , x , y , 0);
			res = min(res , sum[n][m][0] + tmp + case2(i , j));
			cout << res << " ";
		}
		cout << endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("bidoimau.inp" , "r" , stdin);
    freopen("bidoimau.out" , "w" , stdout);
    input();
    prepare();
    solve();
    return 0;
}