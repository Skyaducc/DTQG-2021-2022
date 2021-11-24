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
const int MAXN = 3e5 + 1;
int n , m;
pii a[MAXN];
int group[MAXN];
vector<int> ve[4];
set<int> edge[MAXN];
int numedge = 0;
bool check(int x , int y)
{
	for (int u : ve[x])
	{
		for (int v : ve[y])
		{
			if(edge[u].find(v) == edge[u].end() || edge[v].find(u) == edge[v].end())
			{
				return false;
			}
			numedge++;
		}
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
    cin >> n >> m;
    foru (i , 1 , m)
    {
    	cin >> a[i].fi >> a[i].se;
    	if(a[i].fi > a[i].se)	swap(a[i].fi , a[i].se);
    	edge[a[i].fi].insert(a[i].se);
    	edge[a[i].se].insert(a[i].fi);
    }
    sort(a + 1 , a + 1 + m);
    memset(group , -1 , sizeof(group));
    foru (x , 1 , 3)
    {
        int i;
        for (i = 1 ; i <= n ; i++) if(group[i] == -1) break;
        if(i == n + 1)
        {
        	cout << -1;
        	return 0;
        }
        group[i] = x;
        foru (j , 1 , n)
        {
        	if(i != j && group[j] == -1  && edge[i].find(j) == edge[i].end()) 
        	{
        		group[j] = x;
        	}
        }
    }
    // foru (i , 1 , n)
    // {
    // 	cout << group[i] << " ";
    // }
    foru (i , 1 , n)
    {
    	if(group[i] > 3 || group[i] == -1)
    	{
    		cout << -1;
    		return 0;
    	}
    	ve[group[i]].push_back(i);
    }
    if(check(1 , 2) && check(2 , 3) && check(1 , 3))
    {
    	if(numedge == m)
    	{
    		foru (i , 1 , n)	cout << group[i] << " ";
    		return 0;
    	}
    	// cout << numedge << endl;
    }
    cout << -1;
    return 0;
}
