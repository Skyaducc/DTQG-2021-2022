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
using namespace std;
#define int long long
const int oo = 1e9;
int a1 , a2 , b1 , b2;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> a1 >> a2 >> b1 >> b2;
    if(a2 < a1)	swap(a1 , a2);
    if(b2 < b1)	swap(b1 , b2);
    if(a2 < b1 || b2 < a1)
    {
    	cout << a2 - a1 + b2 - b1;
    	return 0;
    }
    int mi = min({a1 , a2 , b1 , b2});
    int ma = max({a1 , a2 , b1 , b2});
    cout << ma - mi;
    return 0;
}
