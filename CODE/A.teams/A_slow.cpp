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
const int MAXN = 4e5 + 1;
int n;
int ans;
int x[21];
vector<int> res;
struct Data
{
	int l , v , r , id;
	Data(int _l = 0 , int _v = 0 , int _r = 0 , int _id = 0)
	{
		l = _l , v = _v , r = _r , id = _id;
	}
	bool operator < (const Data &tmp)	const
	{
		return v < tmp.v;
	}
} a[MAXN];
void check()
{
	vector<int> ve;
	foru (i , 1 , n)
	{
		if(x[i] == 1)	ve.push_back(i);
	}
	bool ok = true;
	foru (i , 0 , (int)ve.size() - 1)
	{
		foru (j , 0 , (int)ve.size() - 1)
		{
			if(a[ve[j]].l > a[ve[i]].v || a[ve[i]].v > a[ve[j]].r)
			{
				ok = false;
				break;
			}
		}
	}
	if(ok)
	{
		if(ans < (int)ve.size())
		{
			ans = (int)ve.size();
			res.clear();
			for (int x : ve)
			{
				res.push_back(x);
			}
		} 
	}
}
void backtrack(int i)
{
	foru (j , 0 , 1)
	{
		x[i] = j;
		if(i == n)
		{
			check();
		}
		else backtrack(i + 1);
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("teams.inp" , "r" , stdin);
    freopen("teams.ans" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
    	int l , v , r;
    	cin >> l >> v >> r;
    	a[i] = {l , v , r , i};
    }
    if(n <= 20)
    {
    	backtrack(1);
	    cout << ans << endl;
	    for (int x : res)	cout << x << " ";
	    return 0;
    }
	// sort(a + 1 , a + 1 + n);
	// foru (i , 1 , n)
	// {
	// 	int Ma = 0 , Mi = oo , pos = i;
	// 	foru (j , i , n)
	// 	{
	// 		Ma = max(Ma , a[j].v);
	// 		Mi = min(Mi , a[j].v);
	// 		if(Mi >= a[j].l && Ma <= a[j].r)
	// 		{
	// 			pos = j;
	// 		}
	// 		else break;
	// 	}
	// 	if(ans < (pos - i + 1))
	// 	{
	// 		res.clear();
	// 		ans = pos - i + 1;
	// 		foru (j , i , pos)
	// 		{
	// 			res.push_back(a[j].id);
	// 		}
	// 	}
	// }
	// cout << ans << endl;
	// for (int x : res)	cout << x << " ";
    return 0;
}
