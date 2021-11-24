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
const int MAXN = 4e5 + 1;
int subtask , n , num;
int a[MAXN];
pii b[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> subtask >> n;
    foru (i , 1 , n)
    {
    	b[i] = {0 , i};
    }
    foru (i , 1 , n)
    {
    	cin >> a[i];
    	b[a[i]] = {1 , a[i]};
    }
    sort(b + 1 , b + 1 + n);
    int tmp = 0;
    foru (i , 1 , n)
    {
    	if(a[i] == -1)	cout << b[++tmp].se << " ";
    	else cout << a[i] << " ";
    }
    return 0;
}
