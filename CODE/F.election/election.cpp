#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int , int>
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
const long long oo = 1e18;
const int MAXN = 6 * 1e5 + 1;
int subtask , n;
pii a[MAXN];
/*int numvote[52]; // số lượng vote của ứng cử viên i
const int Num_candidate = 50;
ll cost[52][405]; // cost(i , j) : chi phí cướp j phiếu từ người i
ll f[52][389][389];
int index[52];
bool cmp(pii x , pii y)
{
	if(x.fi == y.fi)	return x.se < y.se;
	else	return x.fi < y.fi;
}
void minimize(ll &x , ll y)
{
	x = min(x , y);
}
void sub2()
{
	sort(a + 1 , a + 1 + n , cmp);
	memset(f , 0x3f , sizeof(f));
	foru(i , 1 , n)	numvote[a[i].fi]++;
	foru (i , 1 , 50)
	{
		int num = 0;
		foru (j , 1 , n)
		{
			if(a[j].fi == i)
			{
				cost[i][num+1] = cost[i][num] + a[j].se; 
				num++;
			} 
		}
	}
	// cout << cost[1][2] << endl;
	f[0][numvote[0]][0] = 0; // số người đã xét = 0 , số phiếu hiện có = numvote[0] , max số phiếu những người đã xét = 0
	foru (i , 0 , Num_candidate - 1)
	{
		foru (my , 0 , n)
		{
			foru (other , 0 , n)
			{
				if(f[i][my][other] < oo)
				{
					foru(j , 0 , numvote[i + 1])
					{
						minimize(f[i+1][my+j][max(other , numvote[i+1]-j)] , f[i][my][other] + cost[i+1][j]);
					}
				}
			}
		}
	}
	ll best = oo;
	foru (my , 0 , n)
	{
		foru (other , 0 , my - 1)
		{
			minimize(best , f[Num_candidate	][my][other]);
		}
	}
	cout << best << endl;
}*/
vector<int> people;
vector<pii> candidate[MAXN];
ll result = oo;
ll totalcost;
ll curvote; 
int pos[MAXN];
bool cmp(pii x , pii y)
{
	return x.se < y.se;
}
bool cmp1(int x , int y)
{
	return (int)candidate[x].size() > (int)candidate[y].size();
}
ll tree_sum[4 * MAXN] , tree_cnt[4 * MAXN];
void build(int id , int l , int r)
{
	if(l == r)
	{
		tree_sum[id] = (a[l].fi) ? a[l].se : 0;
		tree_cnt[id] = (a[l].fi) ? 1 : 0;
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2 , l , mid);
	build(id * 2 + 1 , mid + 1 , r);
	tree_sum[id] = tree_sum[id * 2] + tree_sum[id * 2 + 1];
	tree_cnt[id] = tree_cnt[id * 2] + tree_cnt[id * 2 + 1];
}
void update(int id , int l , int r , int u , int v)
{
	if(r < u || v < l)	return;
	if(u <= l && r <= v)
	{
		tree_cnt[id] = (tree_cnt[id] >= 1) ? tree_cnt[id] - 1 : 0;
		tree_sum[id] = (tree_sum[id] >= a[u].se) ? tree_sum[id] - a[u].se : 0;
		// tree_cnt[id] -= 1;
		// tree_sum[id] -= a[u].se;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , v);
	update(id * 2 + 1 , mid + 1 , r , u , v);
	tree_sum[id] = tree_sum[id * 2] + tree_sum[id * 2 + 1];
	tree_cnt[id] = tree_cnt[id * 2] + tree_cnt[id * 2 + 1];
}
ll Get(int id , int l , int r , int x)
{
	if (tree_cnt[id] == x)
	{
		return tree_sum[id];
	}
	if(l == r)	return 0;
	int trai = tree_cnt[id * 2];
	int mid = (l + r) / 2;
	if(trai >= x)
	{
		return Get(id * 2 , l , mid , x);
	}
	else
	{
		return tree_sum[id * 2] + Get(id * 2 + 1 , mid + 1 , r , x - trai);
	}
}
void subfull()
{
	sort(a + 1 , a + 1 + n);
	foru (i , 1 , n)
	{
		if(a[i].fi != a[i-1].fi)	people.push_back(a[i].fi);
	}
	sort(a + 1 , a + 1 + n , cmp);
	foru (i , 1 , n)
	{
		candidate[a[i].fi].push_back({a[i].se , i});
	}
	sort(people.begin() , people.end() , cmp1);
	build(1 , 1 , n);
	curvote = candidate[0].size();
	ford (x , n , 1)
	{
		for (int j : people)
		{
			if((int)candidate[j].size() >= x)
			{
				pii tmp = candidate[j][pos[j]];
				pos[j]++;
				totalcost += tmp.fi;
				update(1 , 1 , n , tmp.se , tmp.se);
				curvote++;
			}
			else	break;
		}
		ll need = max(1LL * 0 , x - curvote);
		ll tmp = Get(1 , 1 , n , need);
		result = min(result , totalcost + tmp);
	}
	cout << result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("election.inp" , "r" , stdin);
    freopen("election.out" , "w" , stdout);
    cin >> subtask >> n;
    foru (i , 1 , n)
    {
    	cin >> a[i].fi >> a[i].se;
    }
    // if(subtask == 2)	sub2();
    subfull();
    return 0;
}