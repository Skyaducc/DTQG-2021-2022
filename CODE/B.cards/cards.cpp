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
const int MAXN = 101;
int n , m;
string s[MAXN];
map<char , int> mp;
struct Data
{
	int s1 , s2;
	char color , num;	
} a[MAXN];
bool cmp(Data x , Data y)
{
	if(x.s1 == y.s1)	return x.s2 > y.s2;
	else return x.s1 > y.s1;
}
set<string> se;
bool check()
{
	int cnt = 0;
	cout <<"----------" << endl;
	foru (i , 1 , m)
	{
		cout << a[i].s1 << " " << a[i].color << " " << a[i].s2 << " " << a[i].num << endl;
		if(a[i].s1 >= 1 && a[i].s2 >= 1)
		{
			cnt++;
		}	
	}
	return cnt <= 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("cards.inp" , "r" , stdin);
    freopen("cards.out" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
    	cin >> s[i];
    	se.insert(s[i]);
    }
    for (string x : se)
    {
    	mp[x[0]]++;
    	mp[x[1]]++;
    }
    for (string x : se)
    {
    	a[++m] = {mp[x[0]] , mp[x[1]] , x[0] , x[1]};
    }
    sort (a + 1 , a + 1 + m , cmp);
    int ans = 0;
    while(true)
    {
    	char x = a[1].color;
    	queue<char> qu;
    	foru (i , 1 , m)
    	{
    		if(x == a[i].color)	a[i].s1--;
    	}
    	ans++;
    	if(check())	break;
    	cout << ans << endl;
    	sort(a + 1 , a + 1 + m , cmp);
    	char y = a[1].num;
    	foru (i , 1 , m)
    	{
    		if(y == a[i].num)	a[i].s2--;
    	}
    	ans++;
    	if(check())	break;
    	cout << ans << endl;
    	foru (i , 1 , m)
    	{
    		if((a[i].s1 < 1 && a[i].s2 >= 1))	qu.push(a[i].num);
    		if(a[i].s2 < 1 && a[i].s1 >= 1)	qu.push(a[i].color);
    	}
    	while(qu.size())
    	{
    		char x = qu.front();
    		qu.pop();
    		foru (i , 1 , m)
    		{
    			if(x == a[i].color)
    			{
    				a[i].s1--;
    				if(a[i].s1 < 1 && a[i].s2 >= 1)
    				{
    					qu.push(a[i].num);
    				}
    			}
    			if(x == a[i].num)
    			{
    				a[i].s2--;
    				if(a[i].s2 < 1 && a[i].s1 >= 1)
    				{
    					qu.push(a[i].color);
    				}
    			}
    		}
    	}
    	sort (a + 1 , a + 1 + m , cmp);
    	if(check())	break;
    	cout << ans << endl;
    }
    cout << ans;
    return 0;
}
