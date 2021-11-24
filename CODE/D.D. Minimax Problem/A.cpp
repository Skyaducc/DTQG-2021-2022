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
const int MAXN = 3e5 + 1;
const int MAXM = 9;
int n , m;
int a[MAXN][MAXM] , b[MAXN][MAXM];
vector<int> v;
pii res;
bool check(int x)
{
	foru (i , 1 , n)	foru (j , 1 , m)	b[i][j] = (a[i][j] >= x) ? 1 : 0;
	int id[(1 << m)];
	set<int> s;
	foru (i , 1 , n)
	{
		int mask = 0;
		foru (j , 1 , m)	if(b[i][j])	mask = SET_ON(mask , j - 1);
		s.insert(mask);
		id[mask] = i;
	}
	set<int>::iterator i , j;
	for (i = s.begin() ; i != s.end() ; i++)
	{
		for (j = s.begin() ; j != s.end() ; j++)
		{
			int tmp1 = *i;
			int tmp2 = *j;
			if((tmp1 | tmp2) == (1 << m) - 1)
			{
				res = {id[tmp1] , id[tmp2]};
				return true;
			}
		}
	}
	return false;
}
int main()	
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , n)
    {
    	foru (j , 1 , m)
    	{
    		cin >> a[i][j];
    	}
    }
    int l = 0 , r = 1e9;
    while(l <= r)
    {
    	int mid = (l + r) / 2;
    	if(check(mid))
    	{
    		l = mid + 1;
    	}
    	else r = mid - 1;
    }
    cout << res.fi << " " << res.se;
    return 0;
}
