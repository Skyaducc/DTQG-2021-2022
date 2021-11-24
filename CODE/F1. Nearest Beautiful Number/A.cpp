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
#define int long long
using namespace std;
const int oo = 2e9;
int test;
int n , k;
int to_int(string s)
{
    int res = 0;
    foru (i , 0 , (int)s.length() - 1)
    {
        res = res * 10 + s[i] - '0';
    }
    return res;
}
void solve()
{
	cin >> n >> k;
    string s = to_string(n);
    int m = s.length();
	if(k == 1)
	{
        int res = oo;
        foru (i , 0 , 9)
        {
            string tmp = "";
            foru (j , 0 , m - 1)
            {
                tmp += char(i + '0');
            }
            int temp = to_int(tmp);
            if(temp >= n)
            {
                res = min(res , temp);
            }
        }
        cout << res << endl;
	}
    else
    {
        set<char> se;
        foru (i , 0 , m - 1)
        {
            se.insert(s[i]);
        }
        if((int)se.size() <= k)
        {
            cout << s << endl;
            return;
        }
        string res = "";
        res += s[0];
        foru (i , 1 , m - 1)
        {
            if(s[i] != s[i-1])
            {
                bool ok1 = true , ok2 = true;
                foru (j , i + 1 , m - 1)
                {
                    int tmp = s[j] - '0';
                    int tmp1 = s[i] - '0';
                    int tmp2 = s[i-1] - '0';
                    if(tmp < tmp1)
                    {
                        ok1 = false;
                        break;
                    }
                    if(tmp < tmp2)
                    {
                        ok2 = false;
                        break;
                    }
                }
                int tmp = s[i] - '0';
                int tmp1 = s[i-1] - '0';
                if(!ok1 || !ok2)
                {
                    bool flag = true;
                    foru (j , i , m - 1)
                    {
                        if(min(tmp , tmp1) >= s[j] - '0' || !flag)
                        {
                            res += min(tmp , tmp1) + '0';
                            if(min(tmp , tmp1) > s[j] - '0')
                            {
                                flag = false;
                            }
                        }
                        else
                        {
                            res += max(tmp , tmp1) + '0';
                            if(max(tmp , tmp1) > s[j] - '0') flag = false;
                        }
                    }
                    break;
                }
                res += char(tmp + 1 + '0');
                if(tmp1 == tmp + 1)
                {
                    foru (j , i + 1 , m - 1)    res += '0';
                }
                else
                {
                     foru (j , i + 1 , m - 1)    res += char(min(tmp + 1 , tmp1) + '0');
                }
                break;
            }
            else res += s[i];
        }
        cout << res << endl;
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}
