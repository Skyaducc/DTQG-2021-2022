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
const int MAXN = 301;
int n , m;
string s1 , s2;
vector<pii> adj[MAXN];
int fns[MAXN];
struct data
{
    int u , c , k; // ki tu hien tai ,
                   // so buoc di chuyen ,
                   // da di duoc bao nhieu o can den
};
struct cmp
{
    bool operator() (const data& _x , const data& _y)
    {
        return _x.c > _y.c;
    }
};
void dijkstra()
{
    priority_queue<data , vector<data> , cmp> pq;
    pq.push({fns[0] , 0 , 1});
    while(pq.size())
    {
        int u = pq.top().u;
        int c = pq.top().c;
        int k = pq.top().k;
        cout << char(u + 'a') << " " << c << " " << k << endl;
        pq.pop();
        for (pii h : adj[u])
        {
            int v = h.fi;
            int uv = h.se;
            if(k == m)
            {
                cout << c + 1;
                return;
            }
            if(v == fns[k])
            {
                pq.push({v , c + uv , k + 1});
            }
            else    pq.push({v , c + uv , k});
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
    cin >> n >> m >> s1 >> s2;
    for (int i=0 ; i<m ; i++)
    {
        bool ok = false;
        for (int j=0 ; j<n ; j++)
        {
            if(s2[i] == s1[j])
            {
                ok = true;
            }
        }
        if(ok == false)
        {
            cout << -1;
            return 0;
        }
    }
    for (int i=0 ; i<n ; i++)
    {
        int tmp = s1[i] - 'a';
        if(i >= 1)
        {
            int tmp1 = s1[i-1] - 'a';
            adj[tmp].push_back({tmp1 , 1});
            adj[tmp1].push_back({tmp , 1});
        }
        if(i < n - 1)
        {
            int tmp2 = s1[i+1] - 'a';
            adj[tmp].push_back({tmp2 , 1});
            adj[tmp2].push_back({tmp , 1});
        }
        for (int j=0 ; j<n ; j++)
        {
            int t = s1[j] - 'a';
            if(i != j && s1[i] == s1[j])
            {
                adj[tmp].push_back({t , abs(j - i)});
                adj[t].push_back({tmp , abs(j - i)});
            }
        }
    }
    for (int i=0 ; i<m ; i++)
    {
        int tmp = s2[i] - 'a';
        fns[i] = tmp;
    }
    dijkstra();
    return 0;
}
