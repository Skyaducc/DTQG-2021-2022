// n ngày với nhiệt độ t(i) và có m đồ bảo hộ với nhiệt độ chống chịu là l(i) -> r(i)
// tìm cách mua ít đồ bảo hộ nhất để ko có ngày nào ko có bộ đồ mặc
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
const int MAXN = 1e5 + 1;
int numday , numitem;
struct Data
{
	int l , r , id;
	bool operator < (const Data &tmp)	const
	{
		return l < tmp.l;
	}
} item[MAXN];
int day[MAXN] , mark[MAXN] , dd[MAXN];
int far[MAXN] , MAX[MAXN] , ans[MAXN];
int get_pos(int l , int r , int x)
{
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if(item[mid].l <= x)
		{
			ans = mid;
			l = mid + 1;
		} 
		else r = mid - 1;
	}
	return ans;
}
pii tree[4 * MAXN];
void build(int id , int l , int r)
{
	if(l == r)
	{
		tree[id] = {item[l].r , l};
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2 , l , mid);
	build(id * 2 + 1 , mid + 1 , r);
	tree[id].fi = max(tree[id * 2].fi , tree[id * 2 + 1].fi);
	tree[id].se = (tree[id * 2].fi > tree[id * 2 + 1].fi) ? tree[id * 2].se : tree[id * 2 + 1].se;
}
int getmax(int id , int l , int r , int u , int v)
{
	if(r < u || v < l)	return 0;	
	if(u <= l && r <= v)
	{
		return tree[id].se;
	}
	int mid = (l + r) / 2;
	int trai = getmax(id * 2 , l , mid , u , v);
	int phai = getmax(id * 2 + 1 , mid + 1 , r , u , v);
	return (item[trai].r > item[phai].r) ? trai : phai;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> numitem;
    foru (i , 1 , numitem)
    {
    	int l , r;
    	cin >> l >> r;
    	item[i] = {l , r , i};
    }
    cin >> numday;
    foru (i , 1 , numday)	cin >> day[i];
    sort(item + 1 , item + numitem + 1);
    sort(day + 1 , day + 1 + numday);
    foru (i , 1 , numitem)
    {
    	// cout << item[i].l << " " << item[i].r << endl;
    	int pos = get_pos(i + 1 , numitem , item[i].r);
    	MAX[i] = pos;
    }
    build(1 , 1 , numitem);
    foru (i , 1 , numitem)
    {
    	if(!MAX[i])	continue;
    	far[i] = getmax(1 , 1 , numitem , i + 1 , MAX[i]);
    }
    int mi = day[1];
 	foru (i , 1 , numitem)
 	{
 		if(item[i].l > mi || mark[i])	continue;
 		int cnt = 1 , jump = far[i];
 		bool ok = true;
 		while(true)
 		{
 			if(jump == 0)	break;
 			if(item[jump].r == 1e5)	
 			{
 				ok = false;
 				break;
 			}
 			jump = far[jump];
 			cnt++;
 		}
 		ans[i] = cnt + (!ok);
 	}
 	int res = oo;
 	foru (i , 1 , numitem)
 	{
 		if(ans[i] == 1 && numday == 1 && item[i].l <= mi && item[i].r == 1e5)	res = min(res , ans[i]);
 		if(ans[i] > 1)	res = min(res , ans[i]);
 	}
 	if(res == oo)	cout << -1;
 	else	cout << res;
    return 0;
}
