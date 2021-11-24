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
#define int unsigned long long
using namespace std;
const int oo = 1e9;
long long MOD(string num , long long a)
{
    long long res = 0;
    foru (i , 0 , (int)num.length() - 1)	res = (res * 10 + (int)num[i] - '0') % a;
    return res;
}
string a;
long long b;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("remainder.inp" , "r" , stdin);
    freopen("remainder.out" , "w" , stdout);
    cin >> a >> b;
    if(b < 0)	b *= -1;
    bool ok = true;
    if(a[0] == '-')
    {
    	a.erase(0 , 1);
    	ok = false;
    }
    long long tmp = MOD(a , b);
    if(ok)	cout << tmp;
    else cout << (b - tmp) % b;
    return 0;
}