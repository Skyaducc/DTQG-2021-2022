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
using namespace std;
const int oo = 1e9;
string s;
int n , k;
vector<int> v;
int d[] = {0 , 1 , 6 , 8};
int res[8];
void build(int i , int x)
{
	if(i == 6)	v.push_back(x);
	else
	{
		foru (j , 0 , 3)	build(i + 1 , x * 10 + d[j]);
	}
}
void solve(int i , int j)
{
	if(i == 0)
	{
		if(j == 0)
		{
			foru (i , 1 , k)	cout << res[i] << endl;
			exit(0);
		}
	}
	else
	{
		if(j == 0)
		{
			res[i] = 0;
			solve(i - 1 , j);
		}
		else
		{
			ford (x , (int)v.size() - 1 , 1)
			{
				if(v[x] <= j)
				{
					if(j / v[x] <= i)
					{
						cout << j << " " << v[x] << " " << i << endl;
						res[i] = v[x];
						solve(i - 1 , j - v[x]);
					}
				}
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("locphat.inp" , "r" , stdin);
    freopen("locphat.out" , "w" , stdout);
    cin >> s >> k;
    if((int)s.length() > 5)	return 0;
    foru (i , 0 , (int)s.length() - 1)	n = n * 10 + s[i] - '0';
    build(1 , 0);
    solve(k , n);
    return 0;
}