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
const int MAXN = 1511;
int test , subtask , n , m , k , lim = oo;
ll res;
int x[32] , mark[MAXN] , p[MAXN];
struct Data
{
	int x , y , val;
} a[MAXN];
bool cmp(Data x , Data y)
{
	return x.val > y.val;
}
void backtrack(int i , int cnt , ll sum)
{
	if(cnt == k)
	{
		res = max(res , sum);
		return;
	}
	if(i > lim)	return;
	foru (j , 0 , 1)
	{
		x[i] = j;
		int New_cnt = cnt + j;
		ll New_sum = sum;
		if(j)
		{
			if(!mark[a[i].x])	New_sum += p[a[i].x];
			if(!mark[a[i].y])	New_sum += p[a[i].y];
			mark[a[i].x]++;
			mark[a[i].y]++;
		}
		backtrack(i + 1 , New_cnt , New_sum);	
		if(j)
		{
			x[i] = 0;
			mark[a[i].x]--;
			mark[a[i].y]--;
		}
	}
}	
void input()
{
	cin >> n >> m >> k;
	foru (i , 1 , n)	cin >> p[i];
	foru (i , 1 , m)
	{
		int u , v;
		cin >> u >> v;
		a[i] = {u , v , p[u] + p[v]};
	}
	sort(a + 1 , a + 1 + m , cmp);
	lim = min(m , 31);
}
void subfull()
{
	input();
	backtrack(1 , 0 , 0LL);
	cout << res << " ";
	res = 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("repair.inp" , "r" , stdin);
    freopen("repair.out" , "w" , stdout);
    cin >> subtask >> test;
    while(test--)
    {
    	subfull();
    }
    return 0;
}
