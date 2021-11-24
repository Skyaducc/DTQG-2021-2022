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
#define RIGHT 131072
#define SIZE 262144
using namespace std;
const int oo = 1e9; 
int n , q , Last;
struct Tree
{
    int val , l , r;
    Tree (int _val = 0 , int _l = 0 , int _r = 0)
    {
        val = _val;
        l = _l;
        r = _r;
    }
};
int Root[100005]; // root(i) : chỉ số nút gốc cây con thứ i
vector<pii> v;
vector<Tree> V(2100000 , Tree(0, 0, 0));
 
int newNode(int n)
{
    V[++Last].val = V[n].val;
    V[Last].l = V[n].l;
    V[Last].r = V[n].r;
    return Last;
}
 
int insert(int id , int l , int r , int OldId)
{
    if(l > OldId || r < OldId)  return id;
    id = newNode(id);
    if(l == OldId && r == OldId)
    {
        V[id].val++;
        return id;
    }
    int mid = (l + r) / 2;
    V[id].l = insert(V[id].l , l , mid , OldId);
    V[id].r = insert(V[id].r , mid + 1 , r , OldId);
    V[id].val = V[V[id].l].val + V[V[id].r].val;
    return id;
}
 
int query(int id , int l , int r , int u , int v)
{
    if(l >= u && r <= v)    return V[id].val;
    if(r < u || l > v)  return 0;
    int mid = (l + r) / 2;
    return query(V[id].l , l , mid , u , v) + query(V[id].r , mid + 1 , r  , u , v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> q;
    foru (i , 1 , n)
    {
        int x;
        cin >> x;
        v.push_back({x , i});
    }
    sort(v.begin() , v.end());
    foru (i , 1 , (int)v.size())
    {
        Root[i] = insert(Root[i-1] , 1 , RIGHT , v[i-1].se);
    }
    while(q--)
    {
        int l , r , k;
        cin >> l >> r >> k;
        int Left = 1 , Right = n;
        while(Right > Left + 1)
        {
            int mid = (Left + Right) / 2;
            if(query(Root[mid] , 1 , RIGHT , l , r) < k)    Left = mid;
            else    Right = mid;
        }
        if(query(Root[Left] , 1 , RIGHT , l , r) == k)  cout << v[Left-1].fi << endl;
        else    cout << v[Right-1].fi << endl;
    }
}