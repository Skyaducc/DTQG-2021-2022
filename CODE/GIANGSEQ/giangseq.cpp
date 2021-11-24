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
#define int long long
using namespace std;
const int oo = 1e18;
const int MAXN = 2050;
int n , k;
int a[MAXN];
struct Data
{
	int val , x;
};
bool operator < (const Data &tmp1 , const Data &tmp2)
{
	return tmp1.val < tmp2.val;
}
priority_queue<Data> pq;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k;
    for (int i=1 ; i<=n ; i++)
    {
    	cin >> a[i];
    }
    for (int i=1 ; i<=n ; i++)
    {
    	if(i == 1)
    	{
    		pq.push({abs(a[i] - a[i+1]) , i});
    		continue;
    	}
    	if(i == n)
    	{
    		pq.push({abs(a[i] - a[i-1]) , i});
    		continue;
    	}
    	pq.push({abs(a[i] - a[i-1]) + abs(a[i] - a[i+1]) , i});
    }
    int cnt = 0;
    while(pq.size())
    {
    	// if(cnt == k+1)	break;
    	int val = pq.top().val , x = pq.top().x;
    	pq.pop();
    	cout << val << " " << x << " " << a[x-1] << " " << a[x] << " " << a[x+1] << " " << cnt << endl;
    	int tmp = 0;
    	if(x == 1)
    	{
    		tmp = abs(a[x] - a[x+1]);
    		continue;
    	}
    	else if(x == n)
    	{
    		tmp = abs(a[x] - a[x-1]);
    	}
    	else if(x!=1 && x!=n)
    	{
    		tmp = abs(a[x] - a[x+1]) + abs(a[x] - a[x-1]);
    	}
    	if(tmp == val)
    	{
    		if(cnt == k)
    		{
    			cout << max(abs(a[x] - a[x-1]) , abs(a[x] - a[x+1]));
    			break;
    		}
    		cnt++;
	    	int tmp1 = (a[x-1] + a[x+1]) / 2;
	    	a[x] = tmp1;
	    	pq.push({tmp1 , x});
    	}
    }
    cout << 0;
    return 0;
}
