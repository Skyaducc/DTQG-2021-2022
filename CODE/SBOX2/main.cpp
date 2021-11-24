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
int n , m;
int bit[MAXN];
void update(int x , int d)
{
    while(x > 0)
    {
        bit[x] += d;
        x -= x & (-x);
    }
}
int get(int x)
{
    int ans = 0;
    while(x <= 2 * n)
    {
        ans += bit[x];
        x += x & (-x);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    while (m--)
    {
        int type , l , r , d;
        cin >> type;
        if(type == 1)
        {
            cin >> l >> r >> d;
            update(r , d);
            update(l-1 , -d);
        }
        else
        {
            cin >> d;
            cout << get(d) << endl;
        }
    }
    return 0;
}
