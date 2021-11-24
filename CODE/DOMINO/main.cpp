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
const int MAXN = 501;
int n , m ,ans;
int a[MAXN][MAXN] , mark[MAXN][MAXN];
int type[MAXN][MAXN];
int dx[]={0 , 0 , -2 , 2};
int dy[]={-2 , 2 , 0 , 0};
struct domino
{
    int x , y , x1 , y1;
} d[250001];
struct data
{
    int u , v , c;
};
bool Inside(int x , int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m && mark[x][y] == 0);
}
void calc(int i , int j)
{
    queue<data> qu;
    qu.push({i , j , 0});
    mark[i][j] = 1;
    while(qu.size())
    {
        int u = qu.front().u;
        int v = qu.front().v;
        int c = qu.front().c;
//        cout << u << " " << v << " " << ans << endl;
        qu.pop();
        for (int i=0 ; i<4 ; i++)
        {
            int tdu = dx[i] + u;
            int tdv = dy[i] + v;
            if(Inside(tdu , tdv))
            {
                if(dx[i] == 0 && type[tdu][tdv] == 1)
                {
                    qu.push({tdu , tdv , c + 1});
                    mark[tdu][tdv] = 1;
                    ans++;
                }
                if(dy[i] == 0 && type[tdu][tdv] == 2)
                {
                    qu.push({tdu , tdv , c + 1});
                    mark[tdu][tdv] = 1;
                    ans++;
                }
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
    for (int i=1 ; i<=n*m ; i++)
    {
        cin >> d[i].x >> d[i].y >> d[i].x1 >> d[i].y1;
        a[d[i].x][d[i].y] = 1;
        a[d[i].x1][d[i].y1] = 1;
        if(d[i].x == d[i].x1)
        {
            type[d[i].x][d[i].y] = 1;
            type[d[i].x1][d[i].y1] = 1;
        }
        else if(d[i].y == d[i].y1)
        {
            type[d[i].x][d[i].y] = 2;
            type[d[i].x1][d[i].y1] = 2;
        }
    }
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            if(a[i][j] == 0)
            {
                calc(i , j);
                cout << ans;
                return 0;
            }
        }
    }
    return 0;
}
