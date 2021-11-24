#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int , int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl;
using namespace std;
const int oo = 1e9;
int test;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    int res = 0;
    foru (i , 1 , n)
    {
        int x = s[i] - '0';
        if(x)   res += x + 1;
        if(x && i == n) res--;
    }
    cout << res << endl;
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
    return 0;
}