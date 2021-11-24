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
const int MAXN = 501;
int n;
pii ans;
string s;
int sumprefix[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> s;
    s = " " + s;
    int res = 0;
    foru (i , 1 , n)
    {
        res += (s[i] == '(') ? 1 : -1;
    }
    if(res != 0)
    {
        cout << 0 << endl << "1 1";
        return 0;
    }
    foru (i , 1 , n)
    {
    	foru (j , 1 , n)
    	{
    		if(i == j)	continue;
    		swap(s[i] , s[j]);
    		int Min = oo , cnt = 0;
            foru (x , 1 , n)
            {
                sumprefix[x] = sumprefix[x-1] + ((s[x] == '(') ? 1 : -1);
                Min = min(Min , sumprefix[x]);
            }
            foru (x , 1 , n)
            {
                if(sumprefix[x] == Min) cnt++;
            }
    		if(cnt > res)
    		{
    			res = cnt;
    			ans = {i , j};
    		}
    		swap(s[i] , s[j]);
    	}
    }
    cout << res << endl;
    cout << ans.fi << " " << ans.se;
    return 0;
}
