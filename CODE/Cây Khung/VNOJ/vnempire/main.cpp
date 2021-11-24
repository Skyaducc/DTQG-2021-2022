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
const int MAXN = 100001;
int root[MAXN];
int n , m;
struct edge
{
    int u , v , c;
} s[3 * MAXN];
struct Data
{
    int x , y , z , id;
} a[MAXN];
bool cmp1(Data l , Data r)
{
    return l.x < r.x;
}
bool cmp2(Data l , Data r)
{
    return l.y < r.y;
}
bool cmp3(Data l ,Data r)
{
    return l.z < r.z;
}
bool cmp(edge l , edge r)
{
    return l.c < r.c;
}
int calc(Data l , Data r)
{
    return min({abs(r.x - l.x) , abs(r.y - l.y) , abs(r.z - l.z)});
}
void update()
{
    for (int i=1 ; i<n ; i++)
    {
        s[++m] = {a[i].id , a[i+1].id , calc(a[i+1] , a[i])};
    }
}
int get_root(int u)
{
    if(root[u] == 0)    return u;
    else
    {
        return root[u] = get_root(root[u]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].id = i;
    }
    sort(a + 1 , a + 1 + n , cmp1);
    update();
    sort(a + 1 , a + 1 + n , cmp2);
    update();
    sort(a + 1 , a + 1 + n , cmp3);
    update();
    sort(s + 1 , s + 1 + m , cmp);
    int ans = 0;
    for (int i=1 ; i<=m ; i++)
    {
        int u = get_root(s[i].u);
        int v = get_root(s[i].v);
        if(u != v)
        {
            root[u] = v;
            ans += s[i].c;
        }
    }
    cout << ans;
    return 0;
}
