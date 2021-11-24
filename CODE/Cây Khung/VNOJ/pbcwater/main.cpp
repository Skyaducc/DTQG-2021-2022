#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
using namespace std;
const int MAXN = 101;
int n , m;
int a[MAXN][MAXN] , f[MAXN][MAXN];
int dx[]={-1 , 1 , 0 , 0};
int dy[]={0 , 0 , -1 , 1};
struct Data
{
    int i , j , c;
    bool operator < (const Data &_x) const
    {
        return c > _x.c;
    }
};
void dijkstra()
{
    priority_queue<Data> pq;
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            f[i][j] = 1e8;
        }
    }
    for (int i=1 ; i<=n ; i++)
    {
        f[i][1] = a[i][1];
        f[i][m] = a[i][m];
        pq.push({i , 1 , f[i][1]});
        pq.push({i , m , f[i][m]});
    }
    for (int i=1 ; i<=m ; i++)
    {
        f[1][i] = a[1][i];
        f[n][i] = a[n][i];
        pq.push({1 , i , f[1][i]});
        pq.push({n , i , f[n][i]});
    }
    while(pq.size())
    {
        int i = pq.top().i;
        int j = pq.top().j;
        int c = pq.top().c;
        pq.pop();
        if(c > f[i][j])    continue;
        for (int k=0 ; k<=3 ; k++)
        {
            int di = dx[k] + i;
            int dj = dy[k] + j;
            if(di <= 1 || di >= n || dj <= 1 || dj >= m)    continue;
            c = max(f[i][j] , a[di][dj]);
            if(f[di][dj] > c)
            {
                f[di][dj] = c;
                pq.push({di , dj , f[di][dj]});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            cin >> a[i][j];
        }
    }
    dijkstra();
    int ans = 0;
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            ans += f[i][j] - a[i][j];
        }
    }
    cout << ans;
    return 0;
}
