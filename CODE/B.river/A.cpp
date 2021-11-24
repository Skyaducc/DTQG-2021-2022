#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl; 
#define int long long
using namespace std;
const int oo = 1e9;
const int MAXN = 1e6 + 1;
int d[MAXN];
int n , M , j;
bool check(int x)
{
    int l = 1 , r = 0, cnt = 0;
    while (l < n)
    {
        int sum = 0;
        while (r + 1 < n && sum + d[r + 1] <= x) 
        { 
            r++; 
            sum += d[r];
        };
        cnt++;
        l = r + 1;
    }
    return (cnt <= j);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("river.inp" , "r" , stdin);
    freopen("river.out" , "w" , stdout);
    cin >> n >> M >> j;
    n++;
    int l = 0 , r = 0;
    foru (i , 1 , n-1)
    {
        d[i] = 1 + (i-1) * (i-1) % M;
        l = max(l , d[i]);
        r += d[i];
    }
    int ans = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}
