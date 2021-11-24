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
void solve() 
{
    int n;
    string s;
    cin >> n >> s;
    set<string> se;
    for (int i=0 ; i<n ; i++) 
    {
        string ss;
        for(int k=0 ; k<5 ; k++) 
        {
        	if(i + k >= n)	break;
            ss.push_back(s[i + k]);
            se.insert(ss);
        }
    }
    for (int len=1 ; len<=5 ; len++) 
    {
        string t(len, 'a');
        while(true) 
        {
            if(se.count(t) == 0) 
            {
                cout << t << endl;
                return;
            }
            int pos = len - 1;
            while(pos >= 0 && t[pos] == 'z') 
            {
                t[pos] = 'a';
                pos--;
            }
            if(pos < 0) break;
            t[pos]++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("A.INP" , "r" , stdin);
    //freopen("A.OUT" , "w" , stdout);
    int test;
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}
