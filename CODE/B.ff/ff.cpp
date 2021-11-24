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
const int oo = 1e9;
int n , k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ff.inp" , "r" , stdin);
    freopen("ff.out" , "w" , stdout);
    cin >> n >> k;
    if(n <= k)
    {
        cout<<2;
        return 0;
    }
    if((2 * n) % k == 0)
    {
        cout << (2 * n) / k;
    }
    else	cout << (2 * n) / k + 1;
    return 0;
}
