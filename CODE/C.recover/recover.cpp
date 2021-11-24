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
const int MAXN = 524290;
int subtask , test;
int n , cnt;
int x[MAXN] , p[MAXN] , Next[MAXN] , deg[MAXN] , topo[MAXN] , ans[MAXN];
vector<int> adj[MAXN];
pii pi[MAXN];
int low[MAXN] , id[MAXN];
stack<int> st;
bool flag = true;
void tarjan(int u) 
{
    low[u] = id[u] = ++cnt;
    st.push(u);
    for (int v : adj[u])
        if (id[v])
            low[u] = min(low[u] , id[v]);
        else 
        {
            tarjan(v);
            low[u] = min(low[u] , low[v]);
        }
    if (id[u] == low[u]) 
    {  
    	int dem = 0;
        int v;
        do 
        {
        	dem++;
            v = st.top();
            st.pop();
            id[v] = low[v] = oo;
        } while (v != u);
        if(dem >= 2)	flag = false;
    }
}
void solve()
{
	reset(deg) , reset(low) , reset(id);
	cnt = 0;
	flag = true;
	cin >> n;
	if( n > 2500)
	{
		cout << "No";
		return;
	}
	foru (i , 1 , n)
	{
		adj[i].clear();
		cin >> x[i];
		Next[i] = x[i];
	}
	foru (i , 1 , n)
	{
		if(Next[i] == n + 1)
		{
			foru (j , i + 1 , n)
			{
				adj[i].push_back(j);
				deg[j]++;
			}
		}
		else if(Next[i] != -1)
		{
			foru (j , i + 1 , Next[i] - 1)
			{
				adj[i].push_back(j);
				deg[j]++;
			}
			foru (j , i , Next[i] - 1)
			{
				adj[Next[i]].push_back(j);
				deg[j]++;
			}
		}
	}
	foru (i , 1 , n)
	{
		if(!id[i])
		{
			tarjan(i);
		}
	}
	if(!flag)
	{
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	foru (i , 1 , n)
	{
		pi[i] = {deg[i] , i};
	}
	sort(pi + 1 , pi + 1 + n , greater<pii>());
	foru (i , 1 , n)
	{
		ans[pi[i].se] = i;
	}
	foru (i , 1 , n)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("recover.inp" , "r" , stdin);
    freopen("recover.out" , "w" , stdout);
    cin >> subtask >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}
