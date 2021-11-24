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
using namespace std;
const int MAXN = 1001;
int test , n;
int a[MAXN];
multiset<int , greater<int> > mu;
vector<pii> res;
bool cmp(pii x , pii y)
{
    return x.fi < y.fi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
        mu.clear();
        res.clear();
        cin >> n;
        for (int i=1 ; i<=2*n ; i++)
        {
            cin >> a[i];
            mu.insert(a[i]);
        }
        bool ok = true;
        int x = *mu.begin();
        int ans = x;
        while(true)
        {
            mu.erase(mu.begin());
            int tmp = *mu.begin();
//            cout << x << " " << tmp << endl;
            mu.erase(mu.begin());
            if(mu.find(x-tmp) == mu.end())
            {
                ok = false;
                break;
            }
            else
            {
                res.push_back({*mu.find(x-tmp) , tmp});
                mu.erase(mu.find(x-tmp));
                x = tmp;
            }
            if(mu.size() == 1)
            {
                res.push_back({*mu.begin() , ans});
                break;
            }
        }
        if(ok == false)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            sort(res.begin() , res.end() , cmp);
            cout << "YES" << endl;
            for (pii j : res)
            {
                cout << j.fi << " " << j.se << endl;
            }
        }
    }
    return 0;
}
