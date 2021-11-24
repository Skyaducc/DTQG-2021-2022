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
const int MAXN = 500001;
int m , n , cnt;
int trie[MAXN][2];
int fns[MAXN] , dem[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> m >> n;
    for (int i=1 ; i<=m ; i++)
    {
        int tmp;
        cin >> tmp;
        int node = 0;
        for (int j=1 ; j<=tmp ; j++)
        {
            int x;
            cin >> x;
            if(trie[node][x] == 0)  trie[node][x] = ++cnt;
            node = trie[node][x];
            dem[node]++;
        }
        fns[node]++;
    }
    for (int i=1 ; i<=n ; i++)
    {
        int tmp;
        cin >> tmp;
        int node = 0 , ans = 0;
        bool ok = true;
        for (int j=1 ; j<=tmp ; j++)
        {
            int x;
            cin >> x;
            if(!ok) continue;
            if(trie[node][x])
            {
                node = trie[node][x];
                ans += fns[node];
            }
            else
            {
                ok = false;
            }
        }
        if(ok) ans += dem[node] - fns[node];
        cout << ans << endl;
    }
    return 0;
}
