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
const int MAXN = 3e5 + 1;
int n;
int a[MAXN];
struct Data1
{
	int val , pos;
};
bool operator < (const Data1 &tmp1 , const Data1 &tmp2)
{
	return tmp1.val > tmp2.val;
}
struct Data2
{
	int val1 , pos1;
};
bool operator < (const Data2 &tmp1 , const Data2 &tmp2)
{
	return tmp1.pos1 > tmp2.pos1;
}
priority_queue<Data1> p1;
priority_queue<Data2> p2;
vector<pii> v;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    for (int i=1 ; i<=3*n ; i++)	cin >> a[i];
    for (int i=1 ; i<=n ; i++)	p1.push({a[i] , i});
    for (int i=n+1 ; i<=2*n ; i++)	p2.push({a[i] , i});
    for (int i=2*n+1 ; i<=3*n ; i++)
    {
    	if(a[i] <= p2.top().val1)
    	{
    		if(p1.top().val < p2.top().val1)
    		{
    			p1.pop();
    			p1.push({p2.top().val1 , p2.top().pos1});
    			p2.pop();
    			p2.push({a[i] , i});
    		}
    		else
    		{
    			p2.pop();
    			p2.push({a[i] , i});
    		}
    	}
    	else
    	{
    		v.clear();
    		while(true)
    		{
    			if(p2.top().val1 > a[i] || p2.size())
    			{
    				break;
    			}
    			v.push_back({p2.top().val1 , p2.top().pos1});
    			p2.pop();
    		}
    		p2.pop();
    		for (pii x : v)
    		{
    			p2.push({x.fi , x.se});
    		}
    	}
    }
    int ans1 = 0 , ans2 = 0;
    while(p1.size())
    {
    	ans1 += p1.top().val;
    	cout << p1.top().val <<  " " ;
    	p1.pop();
    }
    cout << endl;
    while(p2.size())
    {
    	ans2 += p2.top().val1;
    	cout << p2.top().val1 << " ";
    	p2.pop();
    }
    // cout << ans1 << " " << ans2 << endl;
    cout << endl;
    cout << ans1 - ans2;
    return 0;
}
