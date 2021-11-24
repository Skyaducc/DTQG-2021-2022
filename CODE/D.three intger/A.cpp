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
const int MAXN = 1e5 + 1;
int test;
int a , b , c;
void solve()
{
	cin >> a >> b >> c;
	int tmp = oo;
	int res1 , res2 , res3;
	foru (i , 1 , MAXN)
	{
		if(a == 1 && i == 2)	break;
		for (int j=i ; j<=MAXN ; j+=i)
		{
			for (int k=j ; k<=MAXN ; k+=j)
			{
				int temp = abs(i - a) + abs(j - b) + abs(k - c);
				if(tmp > temp)
				{
					tmp = temp;
					res1 = i;
					res2 = j;
					res3 = k;
				}
			}
		}
	}
	cout << tmp << endl;
	cout << res1 << " " << res2 << " " << res3 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}
