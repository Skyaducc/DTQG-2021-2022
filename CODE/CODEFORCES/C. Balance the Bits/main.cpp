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
int test , n;
string t , a , b;
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
        cin >> n >> t;
        int cnt = 0;
        a = "" , b = "";
        for (int i = 0; i < n; i++)
        {
            cnt += (t[i] == '1');
        }
        if(cnt % 2 == 1 || t[0] == '0' || t.back() == '0')
        {
            cout << "NO" << endl;
            continue;
        }
        int k = 0;
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if(t[i] == '1')
            {
                a += (2 * k < cnt) ? '(' : ')';
                b += a.back();
                k++;
            }
            else
            {
                a += (ok) ? '(' : ')';
                b += (ok) ? ')' : '(';
                ok = !ok;
            }
        }
        cout << "YES" << endl;
        cout << a << endl << b << endl;
    }
    return 0;
}
