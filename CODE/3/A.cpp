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
const int MAXN = 2e6 + 11;
const int MAX = 1e3;
int n , m , k;
vector<int> s[MAXN];
vector<int> mark[MAXN];
vector<int> mp[MAXN];
vector<int> visited[MAXN];
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
int get(int u , int v , int x , int y)
{
	if(u <= 0 || v <= 0)	return 0;
	return mark[x][y] - mark[x][v-1] - mark[u-1][y] + mark[u-1][v-1];
}
bool Inside(int x , int y , int d)
{
	if(x + d - 1 > n || y + d - 1 > m)	return false;
	int tmp = get(x , y , x + d - 1 , y + d - 1);
	return 1 <= x && x <= n && 1 <= y && y <= m && visited[x][y] == 0 && tmp == 0;
}
void bfs(int i , int j , int d)
{
	queue<pii> qu;
	qu.push({i , j});
	visited[i][j] = 1;
	while(qu.size())
	{
		int x = qu.front().fi;
		int y = qu.front().se;
		s[x][y]++;
		s[x+d][y]--;
		s[x][y+d]--;
		s[x+d][y+d]++;		
		qu.pop();
		foru (k , 0 , 3)
		{
			int tdx = x + dx[k];
			int tdy = y + dy[k];
			if(Inside(tdx , tdy , d))
			{
				visited[tdx][tdy] = 1;
				qu.push({tdx , tdy});
			}
		}
	}
}
bool check(int x)
{
	foru (i , 0 , n + 1)	foru (j , 0 , m + 1)	s[i][j] = visited[i][j] = 0;
	bool ok = false;
	foru (i , 1 , n - x + 1)
	{
		foru (j , 1 , m - x + 1)
		{
			int tmp = get(i , j , i + x - 1 , j + x - 1);
			if(tmp == 0)
			{
				bfs(i , j , x);
				ok = true;
				break;
			}
		}
		if(ok)	break;
	}
	foru (i , 1 , n)
	{
		foru (j , 1 , m)
		{
			s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
		}
	}
	foru (i , 1 , n)
	{
		foru (j , 1 , m)
		{
			if(mp[i][j] == 0 && s[i][j] == 0)	
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> k;
    foru (i , 0 , n + 2)
    {
    	foru (j , 0 , m + 2)
    	{
    		s[i].push_back(0);
    		mp[i].push_back(0);
    		mark[i].push_back(0);
    		visited[i].push_back(0);
    	}
    }
    foru (i , 1 , k)
    {
    	int x , y;
    	cin >> x >> y;
    	mark[x][y] = mp[x][y] = 1;
    }
    foru (i , 1 , n)	foru (j , 1 , m)	mark[i][j] += mark[i-1][j] + mark[i][j-1] - mark[i-1][j-1];
    int l = 1 , r = 5e3;
    int ans = -1;
    while(l <= r)
    {
    	int mid = (l + r) / 2;
    	if(check(mid))
    	{
    		ans = mid;
    		l = mid + 1;
    	}
    	else r = mid - 1;
    }
    cout << ans;
    return 0;
}