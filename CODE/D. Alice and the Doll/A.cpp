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
int n , m , k;
int markcol[MAXN] , markrow[MAXN];
pii a[MAXN];
vector<int> row[MAXN] , col[MAXN];
int get_pos(int x , int y , int ok , int sign)
{
	int l = 0 , r = (ok) ? ((int)col[x].size() - 1) : ((int)row[x].size() - 1) , ans = 0;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		int tmp = (ok) ? (col[x][mid]) : (row[x][mid]);
		if(sign)
		{
			if(tmp > y)
			{
				ans = (ok) ? col[x][l] : row[x][l];
				r = mid - 1;
			}
			else l = mid + 1;
		}
		else
		{
			if(tmp < y)
			{
				ans = (ok) ? col[x][l] : row[x][l];
				l = mid + 1;
			}
			else r = mid - 1;
		}
	}
	return ans;
}
pii Get(int i , int j , int direct)
{
	if(direct == 1)
	{
		int pos = get_pos(i , j , 1 , 1); // hàng i , tìm cột , tìm vị trí lớn hơn nó 
		if(pos == 0)	return {i , m};
		else return {i , pos - 1};
	}
	else if(direct == 2)
	{
		int pos = get_pos(j , i , 0 , 1); // cột j , tìm hàng , tìm vị trí lớn hơn nó
		if(pos == 0) return {n , j};
		else return {pos - 1 , j};
	}
	else if(direct == 3)
	{
		int pos = get_pos(i , j , 1 , 0); // hàng i , tìm cột , tìm vị trí nhỏ hơn nó
		if(pos == 0)	return {i , 1};
		else return {i , pos + 1};
	}
	else if(direct == 4)
	{
		int pos = get_pos(j , i , 0 , 0); // cột j , tìm hàng , tìm vị trí nhỏ hơn nó
		if(pos == 0) return {1 , j};
		else return {pos + 1 , j};
	}
	return {0 , 0};
}
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> k;
    foru (i , 1 , k)
    {
    	cin >> a[i].fi >> a[i].se;
    	s.insert(a[i].fi);
    	s.insert(a[i].se);
    	row[a[i].se].push_back(a[i].fi);
    	col[a[i].fi].push_back(a[i].se);
    }
    while(s.size())
    {
    	int tmp = *s.begin();
    	sort(row[tmp].begin() , row[tmp].end());
    	sort(col[tmp].begin() , col[tmp].end());
    	s.erase(s.begin());
    }
    int i = 1 , j = 1 , direct = 1 , res = 1; // hàng 1 , cột 1 , hướng 1 
    while(true)
    {
    	cout << i << " " << j << " " << direct << " " << res << endl;
    	pii tmp = Get(i , j , direct);
    	cout << tmp.fi << " " << tmp.se << endl;
    	if(tmp.fi == i && tmp.se == j)	break;
    	if(tmp.fi == i)
    	{
    		while(true)
    		{
    			if(markcol[tmp.se] == 0)	break;
    			if(direct == 1)	tmp.se--;
    			else tmp.se++;
    		}
    		if(tmp.se > m || tmp.se < 1)	break;
    		res += abs(tmp.se - j);
    		// cout << tmp.fi << " " << tmp.se << endl;
    		markrow[i] = 1;
    		j = tmp.se;
    	}
    	else
    	{
    		while(true)
    		{	
    			if(markrow[tmp.fi] == 0)	break;
    			if(direct == 2) tmp.fi--;
    			else tmp.fi++;
    		}
    		if(tmp.fi > n || tmp.fi < 1)	break;
    		res += abs(tmp.fi - i);
    		// cout << tmp.fi << " " << tmp.se << endl;
    		markcol[j] = 1;
    		i = tmp.fi;
    	}
    	direct++;
    	if(direct == 5) direct = 1;
    }
    // cout << res << endl;
    cout << ((res == n * m - k) ? "Yes" : "No"); 
    return 0;
}
