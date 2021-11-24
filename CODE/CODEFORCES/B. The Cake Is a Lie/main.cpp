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
const int MAXN = 101;
int test;
int n , m , k;
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
        cin >> n >> m >> k;
        if(k == 0)
        {
            if (n == 1 && m == 1)   cout << "YES" << endl;
            else    cout << "NO" << endl;
            continue;
        }
        if(n == 1 || m == 1)
        {
            if(abs(n - m) == k)
            {
                cout << "YES" << endl;
            }
            else    cout << "NO" << endl;
            continue;
        }
        int ans = 0;
        if(n <= m)
        {
            ans += 1 + n;
            for (int i=2 ; i<n ; i++)
            {
                ans += i * 2;
            }
            ans += (m - n) * n;
            if(ans == k)    cout << "YES" << endl;
            else    cout << "NO" << endl;
        }
        if(n > m)
        {
            ans += 1 + m;
            for (int i=2 ; i<m ; i++)
            {
                ans += i * 2;
            }
            ans += (n - m) * m;
            if(ans == k)    cout << "YES" << endl;
            else    cout << "NO" << endl;
        }
    }
    return 0;
}
