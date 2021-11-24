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
const int MAXN = 1e4 + 1;
int n , x;
int a[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("data.inp" , "r" , stdin);
    freopen("data.out" , "w" , stdout);
    cin >> n >> x;
    foru (i , 1 , n)	cin >> a[i];
    sort(a + 1 , a + 1 + n , greater<int>());
    int res = 0;
    int j = n;
    foru (i , 1 , j)
    {
    	if(a[i] + a[j] <= x)	j--;
    	res++;
    }
    cout << res;
    return 0;
}