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
const int MAXN = 1e5 + 1;
int test , n , m , k;
int cnt[MAXN] , ans[MAXN] , cnt1[MAXN];
vector<int> ve[MAXN];
vector<pii> v[MAXN];
bool cmp(pii x , pii y)
{
    return x.se <= y.se;
}
void reset()
{
    for (int i=1 ; i<=m ; i++)
    {
        ve[i].clear();
        v[i].clear();
    }
    for (int i=1 ; i<=n ; i++)
    {
        cnt[i] = 0;
        cnt1[i] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
        cin >> n >> m;
        reset();
        vector<int> c[MAXN];
        for (int i=1 ; i<=m ; i++)
        {
            cin >> k;
            c[i].push_back(k);
            for (int j=1 ; j<=k ; j++)
            {
                int tmp;
                cin >> tmp;
                ve[i].push_back(tmp);
                cnt[tmp]++;
            }
        }
        for (int i=1 ; i<=m ; i++)
        {
            for (int k : c[i])
            {
                for (int j=0 ; j<k ; j++)
                {
                    v[i].push_back({ve[i][j] , cnt[ve[i][j]]});
                }
                sort(v[i].begin() , v[i].end() , cmp);
                ans[i] = v[i][0].fi;
                cnt[v[i][0].fi]++;
            }
        }
        bool ok = true;
        int mid = (m % 2 == 0)  ? m / 2 : m / 2 + 1;
        for (int i=1 ; i<=m ; i++)
        {
            cnt1[ans[i]]++;
            if(cnt1[ans[i]] > mid)
            {
                ok = false;
                break;
            }
        }
        if(!ok)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i=1 ; i<=m ; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
