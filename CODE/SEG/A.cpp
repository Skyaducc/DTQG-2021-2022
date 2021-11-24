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
string s;
vector<pair<char , int>> v;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> s;
    int n = s.length();
    s = " " + s;
    if(s[1] != '<')	v.push_back({'<' , 0});
    v.push_back({s[1] , 1});
    foru (i , 2 , n)
    {
    	if(s[i] != v.back().fi)
    	{
    		v.push_back({s[i] , 1});
    	}
    	else v.back().se++;
    }
    if(s[n] != '>')	v.push_back({'>' , 0});
    int res = 0;
    for (int i=0 ; i<(int)v.size()-1 ; i+=2)
    {
    	res += (v[i].se * (v[i].se - 1)) / 2;
    	res += (v[i+1].se * (v[i+1].se - 1)) / 2;
    	res += max(v[i].se , v[i+1].se);
    }
    cout << res;
    return 0;
}
