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
const int MAXN = 1011;
int n , m , k;
bool ok;
char s[MAXN][MAXN];
int visited[MAXN][MAXN];
int cnt = 0 , num = 0 , sum = 0;
pair<int , pii> area[MAXN * MAXN];
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
void loang(int u, int v) 
{
    // cout << u << " " << v << endl;
    foru (i , 0 , 3) 
    {
        int tdu = u + dx[i];
        int tdv = v + dy[i];
        if(tdu <= n && tdv <= m && s[tdu][tdv] == '.') 
        {
            s[tdu][tdv] = '#';
            loang(tdu, tdv);
        }
    }
    return;
}
void dfs(int u, int v) 
{
    // cout << u << " " << v << endl;
    cnt++;
    visited[u][v] = true;
    foru (i , 0 , 3) 
    {
        int tdu = u + dx[i];
        int tdv = v + dy[i];
        if(tdu <= n && tdv <= m && s[tdu][tdv] == '.' && visited[tdu][tdv] == false)
        {
            dfs(tdu , tdv);
        }
        if(tdu > n || tdv > m || tdu == 0 || tdv == 0)
        {
            ok = false;
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> k;
    foru (i , 1 , n)
    {
    	foru (j , 1 , m)
    	{
    		cin >> s[i][j];
    	}
    }
    foru (i , 1 , n)
    {
    	foru (j , 1 , m)
    	{
    		if(s[i][j] == '.' && visited[i][j] == false) 
    		{
    			ok = true;
    			dfs(i , j);
    			if(ok == true)
                    area[++num] = {cnt , {i , j}};
                cnt = 0;
    		}
    	}
    }
    // cout << num << endl;
    sort(area + 1 , area + 1 + num);
    // foru (i , 1 , num)
    // {
    //     cout << area[i].fi << " " << area[i].se.fi << " " << area[i].se.se << endl;
    // }
    foru (i , 1 , num - k)
    {
        int u = area[i].se.fi;
        int v = area[i].se.se;
        sum += area[i].fi;
        s[u][v] = '#';
        loang(u , v);
    }
    cout << sum << endl;
    foru (i , 1 , n)
    {
        foru (j , 1 , m)
        {
            cout << s[i][j]; 
        }
        cout << endl;
    }
    return 0;
}
