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
		if(x[i] == 1)	ve.push_back(a[i].id);
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
    freopen("teams.out" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
    	int l , v , r;
    	cin >> l >> v >> r;
    	a[i] = {l , v , r , i};
    }
    sort(a + 1 , a + 1 + n);
    // foru (i , 1 , n)
    // {
    // 	cout << a[i].l << " " << a[i].v << " " << a[i].r << endl;
    // }
    // if(n <= 20)
    // {
    // 	backtrack(1);
	   //  cout << ans << endl;
	   //  sort(res.begin() , res.end());
	   //  for (int x : res)	cout << x << " ";
	   //  return 0;
    // }
	foru (i , 1 , n)
	{
		int Ma = 0 , Mi = a[i].v , pos = i , Left = 0 , Right = oo;
		foru (j , i , n)
		{
			Ma = a[j].v;
			Left = max(Left , a[j].l);
			Right = min(Right , a[j].r);
			if(Mi < Left || Ma > Right)	break;
			pos = j;
		}
		if(ans < (pos - i + 1))
		{
			res.clear();
			ans = pos - i + 1;
			foru (j , i , pos)
			{
				res.push_back(a[j].id);
			}
		}
	}
	cout << ans << endl;
	sort(res.begin() , res.end());
	for (int x : res)	cout << x << " ";
    return 0;
}
