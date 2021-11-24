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
const int MAXN = 500001;
int n , m , subtask;
int root[MAXN];
struct Data
{
    int u , v , w , id;
    bool operator < (const Data &tmp)   const
    {
        return w < tmp.w;
    }
} a[MAXN];
int Get_root(int u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}
void Kruskal()
{
    sort(a + 1 , a + m + 1);
    foru (i , 1 , m)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p != q)
        {
            root[p] = q;
            cout << a[i].id << " ";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("mst.inp" , "r" , stdin);
    freopen("mst.out" , "w" , stdout);
    cin >> subtask >> n >> m;
    foru (i , 1 , m)
    {
    	int u , v , c;
    	cin >> u >> v >> c;
    	a[i] = {u , v , c , i};
    }
    Kruskal();
    return 0;
}
