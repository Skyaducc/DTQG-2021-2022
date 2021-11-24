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
#define int long long
using namespace std;
const int MAXN = 17001;
int test;
int n , k;
int a[MAXN];
void solve()
{
    cin >> n >> k;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i];
    }
    deque<int> d;
    d.clear();
    for(int i=1 ; i<=k-1 ; i++)
    {
        while(d.size() && a[i] < d.back()) d.pop_back();
        d.push_back(a[i]);
    }
    for(int i=k ; i<=n ; i++)
    {
        while(d.size() && a[i] < d.back()) d.pop_back();
        d.push_back(a[i]);
        cout << d.front() << " ";
        if(a[i-k+1] == d.front())   d.pop_front();
    }
    cout << endl;
}
main()
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
    return 0;
}
