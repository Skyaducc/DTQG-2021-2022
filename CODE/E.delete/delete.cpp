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
#define ll long long
using namespace std;
/*const int MAXN = 21;
int a[21] , dp[(1 << MAXN) + 3];
void sub1()
{
	foru (i , 0 , n - 1)	cin >> a[i];
    memset(dp , -1 , sizeof(dp));
    int last = (1 << n) - 1;
    dp[last] = 0;
    pair<int, int> values[MAXN];
    ford (mask , last , 0)
    {
    	if(dp[mask] < 0)	continue;
    	int indexCount = 0;
		for (int i=0 ; i<n ; i++)
		{
			if (BIT(mask, i)) 
			{
				values[++indexCount] = make_pair(a[i], i);
				values[0].first = values[indexCount + 1].first = 0;
			}
		}
		for (int j=0 ; j<=indexCount ; j++)
		{
			int x = SET_OFF(mask , values[j].second);
			dp[x] = max(dp[x] , dp[mask] + min(values[j - 1].first, values[j + 1].first));
		}

    }
    cout << dp[0];
}*/
const ll oo = 1e9;
const int MAXN = 5 * 1e5 + 1;
const int MAX = 4 * MAXN;
int n;
ll res , lazy;
int a[MAXN];
int tree_mi[MAX] , tree_ma[MAX] , tree_cnt[MAX] , tree_val[MAX] , tree_x[MAX];
void update(int id)
{
	tree_val[id] = min(tree_val[id * 2] , tree_val[id * 2 + 1]);
	tree_mi[id] = min(tree_mi[id * 2] , tree_mi[id * 2 + 1]);
	tree_ma[id] = max(tree_ma[id * 2] , tree_ma[id * 2 + 1]);
	tree_cnt[id] = tree_cnt[id * 2] + tree_cnt[id * 2 + 1];
 	tree_x[id] = (tree_val[id * 2] < tree_val[id * 2 + 1]) ? tree_x[id * 2] : tree_x[id * 2 + 1];
}
void build(int id , int l , int r)
{
	if(l == r)
	{
		tree_mi[id] = tree_ma[id] = tree_x[id] = l;
		tree_cnt[id] = 1 , tree_val[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2 , l , mid);
	build(id * 2 + 1 , mid + 1 , r);
	update(id);
}
void Erase(int id , int l , int r , int pos)
{
	if (pos < l || r < pos) return;
	if(l == r)
	{
		tree_mi[id] = tree_val[id] = oo;
		tree_cnt[id] = tree_ma[id] = 0;
		return;
	}
	int mid = (l + r) / 2;
	Erase(id * 2 , l , mid , pos);
	Erase(id * 2 + 1 , mid + 1 , r , pos);
	update(id);
}
int get_pos(int id , int l , int r , int u , int v , bool ok)
{
	if(r < u || v < l)
	{
		if(ok)	return oo;
		else	return 0;
	}
	if(u <= l && r <= v)
	{
		if(tree_cnt[id])
		{
			if(ok)	return tree_mi[id];
			else	return tree_ma[id];
		}
		if(ok)	return oo;
		else	return 0;
	}
	int mid = (l + r) / 2;
	int trai = get_pos(id * 2 , l , mid , u , v , ok);
	int phai = get_pos(id * 2 + 1 , mid + 1 , r , u , v , ok);
	if(ok)	return min(trai , phai);
	else	return max(trai , phai);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("delete.inp" , "r" , stdin);
    freopen("delete.out" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    }
    build(1 , 1 , n);
    while(tree_cnt[1] > 2)
    {
    	int tmp1 = tree_val[1];
    	int tmp2 = tree_x[1];
    	int temp = tmp1 - lazy;
    	lazy += temp;
    	res += 1LL * (tree_cnt[1] - 2) * temp;
    	Erase(1 , 1 , n , tmp2);
    	int pos1 = get_pos(1 , 1 , n , 1 , tmp2 - 1 , 0);
    	int pos2 = get_pos(1 , 1 , n , tmp2 + 1 , n , 1);
    	if(pos1 == oo)	pos1 = 0;
    	if(pos2 == oo)  pos2 = 0;
    	res += max(0LL , min(a[pos1] , a[pos2]) - lazy);
    }
    cout << res;
    return 0;
}