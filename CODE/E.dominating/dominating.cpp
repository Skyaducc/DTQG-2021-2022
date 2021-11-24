#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((1LL*x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl; 
#define ll long long
#define ALL(x) x.begin() , x.end()
using namespace std;
const int oo = 1e9;
const int MAXN = 6 * 1e5 + 1;
int n , q;
long long a[MAXN];
vector<long long> values;
vector<int> indices[MAXN];
int sum[MAXN][22]; // sum(i , j) : mảng cộng dồn i số các bit tại vị trí bit j 
long long query(int l , int r) 
{
    int res = 0;
    foru (j , 0 , 21)
    {
        int cnt = sum[r][j] - sum[l-1][j];
        if (2 * cnt > r - l + 1) res |= MASK(j);
    }
    if (res >= (int)values.size() || indices[res].empty()) return -1;
    int idL = lower_bound(ALL(indices[res]) , l) - indices[res].begin();
    int idR = upper_bound(ALL(indices[res]) , r) - indices[res].begin();
    return 2 * (idR - idL) > r - l + 1 ? values[res] : -1LL;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dominating.inp" , "r" , stdin);
    freopen("dominating.out" , "w" , stdout);
    cin >> n >> q;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    }
    foru (i , 1 , n) values.push_back(a[i]);
    sort(ALL(values));
    values.resize(unique(ALL(values)) - values.begin());
    foru (i , 1 , n) a[i] = lower_bound(ALL(values), a[i]) - values.begin();
    foru (i , 1 , n) indices[a[i]].push_back(i);
    foru (j , 0 , 21)
    {
    	foru (i , 1 , n)
    	{
    		int x = BIT(a[i] , j);
    		sum[i][j] = sum[i-1][j] + x;
    	}
    }
    while(q--)
    {
    	int l , r;
    	cin >> l >> r;
    	cout << query(l , r) << " ";
    }
    return 0;
}
