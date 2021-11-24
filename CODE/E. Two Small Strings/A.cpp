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
int n;
string s , t;
char c[4] = {'a' , 'b' , 'c'};
bool check(string x)
{
	foru (i , 1 , (int)x.length() - 1)
	{
		if((x[i] == s[1] && x[i-1] == s[0])
			|| (x[i] == t[1] && x[i-1] == t[0]))	return false;
	}
	return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> s >> t;
    string tmp = "";
	tmp += c[0];
	tmp += c[1];
	tmp += c[2];
	string ans = "";
	foru (i , 1 , n)	ans += tmp;
	if(check(ans))
	{
		cout << "YES" << endl << ans;
		return 0;
	}
	ans = "";
	foru (i , 1 , n)	ans += c[0];
	foru (i , 1 , n)	ans += c[1];
	foru (i , 1 , n)	ans += c[2];
	if(check(ans))
	{
		cout << "YES" << endl << ans;
		return 0;
	}
    while(next_permutation(c , c + 3))
    {
    	string tmp = "";
    	tmp += c[0];
    	tmp += c[1];
    	tmp += c[2];
    	string ans = "";
    	foru (i , 1 , n)	ans += tmp;
    	if(check(ans))
    	{
    		cout << "YES" << endl << ans;
    		return 0;
    	}
    	ans = "";
    	foru (i , 1 , n)	ans += c[0];
    	foru (i , 1 , n)	ans += c[1];
    	foru (i , 1 , n)	ans += c[2];
    	if(check(ans))
    	{
    		cout << "YES" << endl << ans;
    		return 0;
    	}
    }
    return 0;
}
