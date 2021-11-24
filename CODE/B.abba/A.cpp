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
map<string , int> mp;
bool bfs(string s , string t)
{
	queue<string> qu;
    qu.push(s);
    while(qu.size())
    {
        string tmp = qu.front();
        qu.pop();
        if(tmp == t)    return true;
        if(mp.find(tmp) != mp.end())    continue;
        mp[tmp] = 0;
        if(tmp[0] == 'B')
        {
            string newtmp = tmp.substr(1 , tmp.size() - 1);
            reverse(newtmp.begin() , newtmp.end());
            qu.push(newtmp);
        }
        if(tmp[(int)tmp.size() - 1] == 'A') 
        {
            string newtmp = tmp.substr(0 , tmp.size() - 1);
            qu.push(newtmp);
        }
    }
	return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("abba.inp" , "r" , stdin);
    freopen("abba.out" , "w" , stdout);
    foru (i , 1 , 3)
    {
    	string x , y;
    	cin >> x >> y;
    	if(bfs(y , x))
    	{
    		cout << "Yes" << endl;
    	}
    	else cout << "No" << endl;
        mp.clear();
    }
    return 0;
}
