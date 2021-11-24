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
const int oo = 1e9;
const int MAXN = 2e5 + 1;
int n , m;
int a[MAXN];
struct Data
{
	int min1 , min2 , cnt;
} tree[10][4 * MAXN];
int digit(int x , int i)
{
	string tmp = to_string(x);
	if((int)tmp.length() < i)	return 0;
	int res = tmp[tmp.length() - i] - '0';
	return ((res > 0) ? 1 : 0);
}
void build(int id , int l , int r)
{
	if(l == r)
	{
		foru (i , 1 , 9)
		{
			int tmp = digit(a[l] , i);
			int temp = (tmp) ? a[l] : oo;
			tree[i][id] = {temp , oo , tmp};
		}
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2 , l , mid);
	build(id * 2 + 1 , mid + 1 , r);
	foru (i , 1 , 9)
	{
		int tmp1 = ((tree[i][id*2].cnt) ? tree[i][id*2].min1 : oo);
		int tmp2 = ((tree[i][id*2+1].cnt) ? tree[i][id*2+1].min1 : oo);
		tree[i][id].min1 = min(tmp1 , tmp2);
		tree[i][id].min2 = (tmp1 > tmp2) ? tmp1 : tmp2;
		tree[i][id].min2 = min({tree[i][id].min2 , tree[i][id*2].min2 , tree[i][id*2+1].min2});
		tree[i][id].cnt = tree[i][id*2].cnt + tree[i][id*2+1].cnt;
	}
}
void update(int id , int l , int r , int u , int v , int x)
{
	if(r < u || v < l)	return;
	if(u <= l && r <= v)
	{
		foru (i , 1 , 9)
		{
			int tmp = digit(x , i);
			int temp = (tmp) ? x : oo;
			tree[i][id] = {temp , oo , tmp};
		}
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , v , x);
	update(id * 2 + 1 , mid + 1 , r , u , v , x);
	foru (i , 1 , 9)
	{
		int tmp1 = (tree[i][id*2].cnt) ? tree[i][id*2].min1 : oo;
		int tmp2 = (tree[i][id*2+1].cnt) ? tree[i][id*2+1].min1 : oo;
		tree[i][id].min1 = min(tmp1 , tmp2);
		tree[i][id].min2 = (tmp1 > tmp2) ? tmp1 : tmp2;
		tree[i][id].min2 = min({tree[i][id].min2 , tree[i][id*2].min2 , tree[i][id*2+1].min2});
		tree[i][id].cnt = tree[i][id*2].cnt + tree[i][id*2+1].cnt;
	}
}
pii Get1(int id , int l , int r , int u , int v , int i , int &res2)
{
	if(r < u || v < l)	return {oo , oo};
	if(u <= l && r <= v)
	{
        ll tmp1 = (tree[i][id].min1 == oo) ? oo : tree[i][id].min1;
        ll tmp2 = (tree[i][id].min2 == oo) ? oo : tree[i][id].min2;
        return {tmp1 , tmp2};
	}
	int mid = (l + r) / 2;
	pii trai = Get1(id * 2 , l , mid , u , v , i , res2);
	pii phai = Get1(id * 2 + 1 , mid + 1 , r , u , v , i , res2);
	res2 = min(res2 , max(trai.fi , phai.fi));
	return {min(trai.fi , phai.fi) , min(trai.se , phai.se)};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , n)	cin >> a[i];
    foru (i , 1 , 4 * n)
    	foru (j , 1 , 9)
    		tree[j][i] = {oo , oo , 0};
    build(1 , 1 , n);
    while(m--)
    {
    	int type , l , r;
    	cin >> type >> l >> r;
    	if(type == 1)	update(1 , 1 , n , l , l , r);
    	else
    	{
    		int ans = 2e9;
    		foru (i , 1 , 9)
    		{
    			int res2 = oo;
    			pii ans1 = (Get1(1 , 1 , n , l , r , i , res2));
    			if(ans1.fi != oo && ans1.se != oo)
                {
                    ans = min(ans , ans1.fi + ans1.se);
                }
                if(ans1.fi != oo && res2 != oo)
                {
                    ans = min(ans , ans1.fi + res2);
                }
    		}
    		if(ans == 2e9)	cout << -1 << endl;
    		else	cout << ans << endl;
    	}
    }
    return 0;
}