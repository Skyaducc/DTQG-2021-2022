// có 2 thao tác
// thao tác 1 : sao chép dãy độ dài k từ vị trí x của mảng a sang vị trí y của mảng b
// tháo tác 2 : lấy giá trị tại vị trí x trên mảng b
// mỗi nút trên cây it tính độ lệch so với mảng a
#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
using namespace std;
const int MAXN = 1e5 + 1;
const int oo = 1e9;
int n , m , ans;
int a[MAXN] , b[MAXN];
struct Data
{
	int val , lazy;
} tree[4 * MAXN];
void push(int id , int l , int r)
{
	if(tree[id].lazy == oo)	return;
	int t = tree[id].lazy;
	tree[id * 2].lazy = t;
	tree[id * 2 + 1].lazy = t;
	tree[id].lazy = oo;
}
void update(int id , int l , int r , int u , int v , int val)
{
	if(r < u || v < l)
	{
		return;
	}
	if(u <= l && r <= v)
	{
		tree[id].lazy = val;
		return;
	}
	push(id , l , r);
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , v , val);
	update(id * 2 + 1 , mid + 1 , r , u , v , val);
}
void Get(int id , int l , int r , int u , int v)
{
	if(r < u || v < l)
	{
		return ;
	}
	if(u <= l && r <= v)
	{
		ans = tree[id].lazy;
		return;
	}
	push(id , l , r);
	int mid = (l + r) / 2;
	Get(id * 2 , l , mid , u , v);
	Get(id * 2 + 1 , mid + 1 , r , u , v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    memset(tree , 0x3f , sizeof(tree));
    cin >> n >> m;
    for (int i=1 ; i<=n ; i++)	cin >> a[i];
    for (int i=1 ; i<=n ; i++)	cin >> b[i];
    while(m--)
    {
    	int type , x , y , k;
    	cin >> type;
    	if(type == 1)
    	{
    		cin >> x >> y >> k;
    		update(1 , 1 , n , y , y + k - 1, x - y);
    	}
    	else
    	{
    		cin >> k;
    		Get(1 , 1 , n , k , k);
    		if(ans > oo)	cout << b[k] << endl;
    		else	cout << a[k + ans] << endl;
    	}
    }
    return 0;
}
