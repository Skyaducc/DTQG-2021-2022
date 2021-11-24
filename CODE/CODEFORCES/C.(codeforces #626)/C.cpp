// ))((())(
// chọn ra các đoạn con sửa lại cho đúng và tổng số phần tử của các đoạn con bé nhất
// chọn (1 , 4) -> (()) chi phí 4
// chọn (7 , 8)	-> ()	chi phí 2
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
const int MAXN = 1e6 + 111;
int n;
string s;
int mark[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> s;
    if(n % 2)
    {
    	cout << -1;
    	return 0;
    }
    s = " " + s;
    int ans = 0 , sum = 0;
    for (int i=1 ; i<=n ; i++)
    {
    	if(s[i] == '(')	sum++;
    	else sum--;
    	if(sum < 0)
    	{
    		mark[i] = 1;
    	}
    	if(sum == 0 && mark[i-1] == 1)	mark[i] = 1;
    }
    int i = 1 , j = 1 , cnt = 0;
    for (int i=1 ; i<=n ; i++)
    {
    	if(s[i] == '(')	cnt++;
    }
    if(n - cnt != cnt)
    {
    	cout << -1;
    	return 0;
    }
    while(true)
    {
    	if(mark[i] == 1)
    	{
    		j = i;
    		while(true)
    		{
    			if(mark[j+1] == 0 || j > n)	break;
    			j++;
    		}
    		ans += (j - i + 1);
    	}
    	else	i++;
    	if(j > i)	i = j + 1;
    	else	i++;
    	if(i > n || j >= n)	break;
    }
   	if(ans < 0)	ans = -1;
   	cout << ans;
    return 0;
}
