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
#define int long long
using namespace std;
const int oo = 1e9;
int test , n , k;
int a[10];
void solve()
{
	cin >> n >> k;
	string s = to_string(n);
	while(true)
	{
		set<char> se;
		foru (i , 0 , s.length() - 1)	se.insert(s[i]);
		if(se.size() <= k)	
		{
			cout << s << endl;
			return;
		}
		se.clear();
		int i = 0;
		while(true)
		{
			se.insert(s[i]);
			if (se.size() > k)
			{
				while (s[i] == '9')	i--;	
				s[i]++;
				foru(j , i + 1 , s.length() - 1)	s[j] = '0';
				break;
			}
			i++;
		}
	}
}
main()
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
