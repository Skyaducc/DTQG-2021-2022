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
string s;
char c[6] = {'a' , 'e' , 'i' , 'o' , 'u'};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("syllable.inp" , "r" , stdin);
    freopen("syllable.out" , "w" , stdout);
    cin >> s;
    s = " " + s;
    int res = 0;
    foru (i , 1 , (int)s.length() - 1)
    {
    	foru (j , 0 , 4)
    	{
    		if(s[i] == c[j])	res++;
    	}
    }
    foru (i , 1 , (int)s.length() - 2)
    {
    	string tmp = "" , tmp1 = "";
    	tmp += s[i] , tmp += s[i+1];
    	if(i <= (int)s.length() - 3)	tmp1 += s[i] , tmp1 += s[i+1] , tmp1 += s[i+2];
    	if(tmp == "au" || tmp == "oa" || tmp == "oo" || tmp1 == "iou")
    	{
    		res--;
    	}
    }
    if(s[(int)s.length()-1] == 'e')	res--;
    string tmp = "";
    tmp += s[s.length() - 2] , tmp += s[s.length() - 1];
    if(tmp == "le")
    {
    	bool ok = false;
    	foru (i , 0 , 4)
    	{
    		if(s[s.length() - 3] == c[i])
    		{
    			ok = true;
    			break;
    		}
    	}
    	if(!ok)	res++;
    }
    if(res < 1)	cout << 1;
    else	cout << res;
    return 0;
}
