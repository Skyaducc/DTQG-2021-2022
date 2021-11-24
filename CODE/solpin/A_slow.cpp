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
const int MAXN = 501;
int n , m , q;
int a[MAXN][MAXN] , b[MAXN][MAXN] , c[MAXN][MAXN];
int arr[2001][2001] , sum[2001][2001];
void sub2()
{
	cin >> q;
    while(q--)
    {
    	int type;
    	cin >> type;
    	if(type == 0)
    	{
    		int x , y;
    		cin >> x >> y;
    		foru (i , 1 , n)
    		{
    			foru (j , 1 , m)
    			{
    				int tmp = ((j + x) % m == 0) ? m : (j + x) % m;
    				b[i][j] = a[i][tmp];
    			}
    		}
    		foru (i , 1 , n)
    		{
    			foru (j , 1 , m)
    			{
    				int tmp = ((i + y) % n == 0) ? n : (i + y) % n;
    				c[i][j] = b[tmp][j];
    			}
    		}
    		foru (i , 1 , n)
    		{
    			foru (j , 1 , m)
    			{
    				a[i][j] = c[i][j];
    			}
    		}
    	}
    	else
    	{
    		int u , v , x , y;
    		cin >> u >> v >> x >> y;
    		int ans = 0;
    		if(u > x)	swap(u , x);
    		if(v > y)	swap(v , y);
    		foru (i , u , x)
    		{
    			foru (j , v , y)
    			{
    				ans += a[i][j];
    			}
    		}
    		cout << ans << endl;
    	}
    }
}
void subfull()
{
	foru (i , 1 , n)	foru (j , 1 , m)	arr[i][j] = a[i][j];
	int i = 1;
	while(i <= 2000)
	{
		foru (j , 1 , m)
		{
			int tmp = (i % n == 0) ? n : i % n;
			arr[i][j] = arr[tmp][j];
		}
		int j = m + 1;
		while(j <= 2000)
		{
			int tmp = (j % m == 0) ? m : j % m;
			arr[i][j] = arr[i][tmp];
			j++;
		}
		i++;
	}
	foru (i , 1 , 2000)
	{
		foru (j , 1 , 2000)
		{
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
		}
	}
	cin >> q;
	i = 1;
	int j = 1;
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 0)
		{
			int x , y;
			cin >> x >> y;
			j += x;
			i += y;
		}
		else
		{
			int u , v , x , y;
			cin >> u >> v >> x >> y;
			if(u > x) swap(u , x);
			if(v > y) swap(v , y);
			int newu = u - 1 + i;
			int newv = v - 1 + j;
			int newx = x - 1 + i;
			int newy = y - 1 + j;
			cout << sum[newx][newy] - sum[newx][newv-1] 
			- sum[newu-1][newy] + sum[newu-1][newv-1] << endl;
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.ANS" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , n)
    {
    	foru (j , 1 , m)
    	{
    		cin >> a[i][j];
    	}
    }
    // if(m <= 100 && n <= 100)
    // {
    // 	sub2();
    // }
    // else subfull();
    sub2();
    // subfull();
    return 0;
}
