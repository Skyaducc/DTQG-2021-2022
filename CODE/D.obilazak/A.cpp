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
const int MAXN = 1025;
int n;
int a[MAXN] , res[MAXN] , num;
void dfs(int u , int cnt)
{
	if(cnt == n)
	{
		res[u] = a[++num];
		// cout << u << " " << res[u] << endl;
		return;
	}
	else
	{
		dfs(2 * u , cnt + 1);
		res[u] = a[++num];
		// cout << u << " " << res[u] << endl;
		dfs(2 * u + 1 , cnt + 1);
	}
	return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , (1 << n) - 1)	cin >> a[i];
    dfs(1 , 1);
    int level = 0;
    int cnt = 0;
    foru (i , 1 , (1 << n) - 1) 
    {
        cout << res[i] << " ";
        cnt++;
        if(cnt == (1 << level))
        {
        	cout << endl;
        	level++;
        	cnt = 0;
        }
    }
    return 0;
}
