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
#define int long long
using namespace std;
int n;
const int MAXN=1e5+1;
int bit[MAXN];
vector<int> v;
void nen(vector<int> &x)
{
    vector<int> tmp(x.begin(),x.end());
    unique(tmp.begin(),tmp.end());
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<x.size();i++)
    {
        x[i]=lower_bound(tmp.begin(),tmp.end(),x[i])-tmp.begin()+1;
    }
}
void update(int x,int k)
{
    for(;x<=n;x+=x&(-x))
    {
        bit[x]=max(bit[x],k);
    }
}
int Get(int x)
{
    int res=0;
    for (;x>=1;x-=x&-x)
    {
        res=max(res,bit[x]);
    }
    return res;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie();
//    cin>>n;
//    for(int i=1;i<=n;i++)
//    {
//        int tmp;
//        cin>>tmp;
//        v.push_back(tmp);
//    }
//    nen(v);
//    for(int x : v)
//    {
//        update(x,Get(x-1)+1);
//    }
//    cout<<Get(n);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    nen(v);
    for(int i=0;i<v.size();i++)
    {
        update(v[i],Get(v[i]-1)+1);
    }
    cout<<Get(v.size());
    return 0;
}