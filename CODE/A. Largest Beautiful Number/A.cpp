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
string s;
int d[MAXN];
void solve(string s)
{
	int n = s.length();
	s = " " + s;
	string ans = "";
	if(n % 2 != 0)
	{
		foru (i , 1 , n - 1)	ans += "9";
		cout << ans << endl;
		return;
	}
	bool ok = true;
	if (s[1] - '0' > 1 || s[n] - '0' > 1)	ok = false;
	foru (i , 2 , n - 1)
	{
		if(s[i] - '0' > 0)	ok = false;
	}
	if(ok)
	{
		foru (i , 1 , n - 2)	ans += "9";
		cout << ans << endl;
		return;
	}
	foru (i , 0 , 9) d[i] = 0;
	foru (i , 1 , n) d[s[i] - '0']++;
	ford (i , n - 1 , 0)
	{
		int cs = s[i+1] - '0' , gt = n - i - 1 , cnt , dem = 1;
		d[cs]--;
		ford (j , cs - 1 , 0)
		{
			d[j]++ ; cnt = 0;
			foru (k , 0 , 9) 
			{
				if (d[k] % 2 != 0) cnt++;
			}
			if (cnt % 2 == gt % 2 && gt >= cnt) 
			{
				ok = true;
				s[i+1] = char(j + '0');
				while (gt > cnt)
				{
					gt -= 2; 
					dem++ ; s[i+dem] = '9';
					dem++ ; s[i+dem] = '9';
				}
				ford (k , 9 , 0)
				{
					if (d[k] % 2 != 0)
					{
						cnt--, gt--, dem++;
						s[i+dem] = char(k+'0');
					}
				}
				break;
			}
			d[j]--;
		}
		if (ok) break;
	}
	s.erase(0 , 1);
	cout << s << endl;
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
    	cin >> s;
    	solve(s);
    }
    return 0;
}
