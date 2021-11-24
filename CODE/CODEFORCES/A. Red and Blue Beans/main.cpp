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
int t;
long long r , b , d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("A.INP" , "r" , stdin);
    //freopen("A.OUT" , "w" , stdout);
    cin >> t;
    while(t--)
    {
        cin >> r >> b >> d;
        if(d == 0 && r != b)
        {
            cout << "NO" << endl;
            continue;
        }
        if(d == 0 && r == b)
        {
            cout << "YES" << endl;
            continue;
        }
        if(r == 1 || b == 1)
        {
            if(abs(r - b) <= d)
            {
                cout << "YES" << endl;
                continue;
            }
            else
            {
                cout << "NO" << endl;
                continue;
            }
        }
        if(r <= b)
        {
            if(b > r * (d + 1))
            {
                cout << "NO" << endl;
            }
            else    cout << "YES" << endl;
        }
        if(r > b)
        {
            if(r > b * (d + 1))
            {
                cout << "NO" << endl;
            }
            else    cout << "YES" << endl;
        }
    }
    return 0;
}
