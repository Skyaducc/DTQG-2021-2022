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
int test , n;
int b[MAXN];
bool check(int x)
{
    set<int> s;
    vector<int> ve;
    for (int i=1 ; i<=n ; i++)
    {
        s.insert(b[i]);
    }
    for (int i=1 ; i<=2*n ; i++)
    {
        if(s.find(i) != s.end())    continue;
        ve.push_back(i);
    }
    for (int i=1 ; i<=x ; i++)
    {
        if(ve[i-1] >= b[n - x + i])
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> b[i];
    }
    int l = 0;
    int r = 2e5;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << r << endl;
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
        solve();
    }
}
