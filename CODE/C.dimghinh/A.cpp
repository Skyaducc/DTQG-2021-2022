#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , a , b) for (int i=a ; i>=b ; i--) 
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define int long long
using namespace std;
const int oo = 1e9;
int a1 = oo , a2 = -oo , b1 = oo , b2 = -oo;
int n , x , y;
int odd(int l , int r)
{
    if (l % 2 == 0) l++;
    if (r % 2 == 0) r--;
    if (l > r) return 0;
    int ssh = (r - l) / 2 + 1;
    return ssh;
}
int even(int l , int r)
{
    if (l % 2) l++;
    if (r % 2) r--;
    if (l > r) return 0;
    int ssh = (r - l) / 2 + 1;
    return ssh;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dimghinh.inp" , "r" , stdin);
    freopen("dimghinh.out" , "w" , stdout);
    cin >> n;
    while (n--)
    {
        int A1 = -oo , A2 = oo , B1 = -oo , B2 = oo;
        foru (i , 1 , 4)
        {
            cin >> x >> y;
            A1 = max(A1 , x + y);
            A2 = min(A2 , x + y);
            B1 = max(B1 , x - y);
            B2 = min(B2 , x - y);
        }
        a1 = min(a1 , A1);
        a2 = max(a2 , A2);
        b1 = min(b1 , B1);
        b2 = max(b2 , B2);
        if (a1 <= a2 || b1 <= b2)
        {
            cout << 0;
            return 0;
        }
    }
    a1--;
    a2++;
    b1--;
    b2++;
    cout << odd(a2 , a1) * odd(b2 , b1) + even(a2 , a1) * even(b2 , b1);
    return 0;
}