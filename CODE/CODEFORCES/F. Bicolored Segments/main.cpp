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
const int MAXN = 2e5 + 1;
int n;
int l[MAXN] , r[MAXN] , t[MAXN] , d[MAXN];
vector<int> ve;
bool check(int l , int r , int u , int v)
{
    if(r < u || v < l)  return true;
    else    return false;
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
        cin >> l[i] >> r[i] >> t[i];
        if(t[i] == t[i-1])  d[i] = d[i-1];
        else    d[i] = d[i-1] + 1;
        ve.push_back(d[i]);
    }
    int ans = 0;
    for (int i=1 ; i<=n ; i++)
    {
        int pos = i;
        while(true)
        {
            int tmp = upper_bound(ve.begin() , ve.end() , pos) - ve.begin() + 1;
            if(tmp > n) break;
            if(check(l[i] , r[i] , l[tmp] , r[tmp]))
            {
                cout << pos << " " << tmp << endl;
                ans ++;
            }
            pos = tmp;
        }
    }
    cout << ans;
    return 0;
}
