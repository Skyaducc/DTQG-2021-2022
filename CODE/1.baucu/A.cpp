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
const int MAXN = 1e5 + 11;
int n;
vector<int> adj[MAXN];
int deg[MAXN];
deque<int> dq;
void dfs(int u , int par , int type) // type : dinh cha nam ben 1 : phai ; -1 : trai
{
	// if(deg[u] == 1)	return;
	if(deg[u] % 2 == 0)
	{
		vector<int> ve;
		for (int v : adj[u])    if(v != par)    ve.push_back(v);
		int tmp;
		if(type == -1)
        {
            tmp = ((int)ve.size() - 1) / 2;
        }
        else
        {
            tmp = ((int)ve.size() + 1) / 2;
        }
        foru (i , 0 , tmp - 1)
        {
            dq.push_front(ve[i]);
            dfs(ve[i] , u , 1);
        }
        foru (i , tmp , ve.size() - 1)
        {
            dq.push_back(ve[i]);
            dfs(ve[i] , u , -1);
        }
	}
	else
	{
		for (int v : adj[u])
		{
			if(v != par)
			{
				dq.push_front(v);
				dfs(v , u , 1);
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n - 1)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    	deg[u]++;
    	deg[v]++;
    }
    int root = 0;
    foru (i , 0 , n - 1)
    {
    	if(deg[i] % 2 == 0)
    	{
    		root = i;
    		break;
    	}
    }
    dq.push_back(root);
    dfs(root , -1 , 0);
    if(dq.size() == 1)
    {
    	foru (i , 0 , n - 1)	cout << i << " ";
    	cout << endl;
    }
    while(dq.size())
    {
    	cout << dq.front() << " ";
    	dq.pop_front();
    }
    return 0;
}
