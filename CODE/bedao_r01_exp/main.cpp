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
#define int long long
using namespace std;
const int oo = 1e9;
int q;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> q;
    while(q--)
    {
        int a1 , b1 , a2 , b2;
        cin >> a1 >> b1 >> a2 >> b2;
        if(a1 == 0)
        {
            cout << ((a2 == 0) ? "X = Y" : "X < Y") << endl;
            continue;
        }
        if(a2 == 0)
        {
            cout << ((a1 == 0) ? "X = Y" : "X > Y") << endl;
            continue;
        }
        if(b1 == b2)
        {
            if(a1 == a2)    cout << "X = Y" << endl;
            if(a1 < a2) cout << "X < Y" << endl;
            if(a1 > a2) cout << "X > Y" << endl;
        }
        else
        {
            cout << ((b1 < b2) ? "X < Y" : "X > Y") << endl;
        }
    }
    return 0;
}
