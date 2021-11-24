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
int r , c , q;
int a[51][51] , ans[51][51];
int dx[] = {0 , 0 , - 1 , 1};
int dy[] = {-1 , 1 , 0 , 0};
bool mark[51][51];
bool Inside(int u , int v)
{
	return 1 <= u && u <= r && 1 <= v && v <= c && mark[u][v] == 0;
}
void bfs(int i , int j , int val)
{
	queue<pii> q;
	q.push({i , j});
	while(q.size())
	{
		int u = q.front().fi;
		int v = q.front().se;
		ans[u][v] = val;
		mark[u][v] = 1;
		q.pop();
		foru (k , 0 , 3)
		{
			int tdx = u + dx[k];
			int tdy = v + dy[k];
			if(Inside(tdx , tdy) && a[tdx][tdy] == 10)
			{
				q.push({tdx , tdy});
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("keyboard.inp" , "r" , stdin);
    freopen("keyboard.out" , "w" , stdout);
    cin >> r >> c >> q;
    foru (i , 1 , r)
    {
    	string s;
    	cin >> s;
    	foru (j , 0 , c - 1)
    	{
    		if(s[j] == 'X')	a[i][j+1] = -1;
    		else if(s[j] == '.')	a[i][j+1] = 10;
    		else a[i][j+1] = s[j] - '0';
    	}
    }
    foru (i , 1 , r)
    {
    	foru (j , 1 , c)
    	{
    		if(a[i][j] == -1 || a[i][j] == 10)	continue;
    		ans[i][j] = a[i][j];
    		bfs(i , j , a[i][j]);
    	}
    }
    string res = "";
    while(q--)
    {
    	int i , j;
    	cin >> i >> j;
    	if (a[i][j] != -1 && mark[i][j]) res += char(ans[i][j] + '0');
    }
    if(res.length())	cout << res;
    else cout << "Empty";
    return 0;
}
