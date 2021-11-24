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
int test , n;
void solve()
{
    cin >> n;
    string s = to_string(n);
    int m = s.length();
    bool ok = true;
    while(true)
    {
        int tmp = 1;
        for (int i=1 ; i<m ; i++)
        {
            tmp = tmp * 10 + 1;
        }
        if(tmp < 11)
        {
            break;
        }
        if(n % tmp == 0)
        {
//            cout << n << " " << tmp << endl;
            cout << "YES" << endl;
            ok = false;
            break;
        }
        else
        {
            n -= tmp;
            s = to_string(n);
            int tmp1 = s.length();
            if(n < 0)
            {
//                cout << "NO" << endl;
                break;
            }
            else m = tmp1;
        }
    }
    if(ok)  cout << "NO" << endl;
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
