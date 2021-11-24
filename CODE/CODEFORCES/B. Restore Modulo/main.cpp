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
const int MAXN = 1e5 + 1;
int test , n;
int a[MAXN];
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
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> a[i];
        }
        int c = 0 , m = 0;
        bool ok = true;
        bool flag = true , flag1 = true;
        for (int i=2 ; i<=n ; i++)
        {
            if(a[i] >= a[i-1])
            {
                if(flag)
                {
                    c = a[i] - a[i-1];
                    flag = false;
                }
                if(!flag)
                {
                    if(c != a[i] - a[i-1])
                    {
                        ok = false;
                        break;
                    }
                }
            }
        }
        for (int i=2 ; i<n ; i++)
        {
            if(a[i] <= a[i-1])
            {
                if(!flag && !flag1)
                {
                    if(m != (a[i-1] - a[i] + c))
                    {
                        ok = false;
                        break;
                    }
                }
                if(!flag && flag1)
                {
                    m = a[i-1] - a[i] + c;
                    if(m < a[i] || m < a[i-1])
                    {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if(ok)
        {
            if(c == 0)
            {
                cout << 0 << endl;
            }
            else    cout << m << " " << c << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
