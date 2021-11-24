#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
using namespace std;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int BASE = 256;
int n , cnt;
long long res;
pair<int , string> pi[MAXN];
int trie[MAXN][27][2];
long long Isend[MAXN];
bool cmp(pair<int,string> x , pair<int,string> y)
{
	return x.fi > y.fi;
}
bool check(string x , string y)
{
	int Hash1 = 0 , Hash2 = 0;
	for (int i=0 ; i<(int)x.length() ; i++)
	{
		Hash1 = (Hash1 * BASE + x[i]) % MOD;
	}
	for (int i=0 ; i<(int)y.length() ; i++)
	{
		Hash2 = (Hash2 * BASE + y[i]) % MOD;
	}
	return (Hash1 == Hash2);
}
void add1(string s)
{
	
}
void add2(string s)
{

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
    	cin >> pi[i].fi >> pi[i].se;
    }
    sort(pi + 1 , pi + 1 + n , cmp);
    for (int i=1 ; i<=n ; i++)
    {
    	cout << pi[i].fi << " " << pi[i].se << endl;
    }
    for (int i=1 ; i<=n ; i++)
    {
    	// add(pi[i].se);
    	string RevS = pi[i].se;
    	string s = RevS;
    	reverse(s.begin() , s.end());
    	if(check(s , RevS))	res++;
		// cout << res << endl;
    }
    cout << res;
    return 0;
}
