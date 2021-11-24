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
string x , y;
map<char , int> mp1 , mp2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("adn.inp" , "r" , stdin);
    // freopen("adn.out" , "w" , stdout);
    cin >> x >> y;
    int n = x.length() , m = y . length();
    int ans = 0;
    x = " " + x;
    y = " " + y;
    ans += abs(n - m);
    if(ans > 2)
    {
    	cout << "No";
    	return 0;
    }
    foru (i , 1 , n)	mp1[x[i]]++;
    foru (i , 1 , m)	mp2[y[i]]++;
    foru (i , 1 , n)
    {
    	if(abs(mp2[x[i]] - mp1[x[i]]) > 2)
    	{
    		cout << "No";
    		return 0;
    	}
    }
   	foru (i , 1 , m)
   	{
   		if(abs(mp1[y[i]] - mp2[y[i]]) > 2)
   		{
   			cout << "No";
   			return 0;
   		}
   	}
   	cout << "Yes";
    return 0;
}
