// cho n con quái vật và m anh hùng 
// mỗi anh hùng có 2 chỉ số : sức mạnh và độ bền (pi , si) , con quái vật 1 chỉ số sức mạnh (ai)
// anh hùng đánh bại được quái vật nếu sức mạnh anh hùng lớn hơn sức mạnh con quái vật
// mỗi anh hùng trong một ngày tiêu diệt được tối đa si con quái vật
// mỗi anh hùng có thể chọn nhiều lần và trong một ngày chỉ được chọn 1 anh hùng
// tính số ngày tối thiểu để tiêu diệt được con quái vật cuối cùng
// giả sử chọn anh hùng thứ i và bắt đầu tiêu diệt từ con quái vật thứ j
// thì số con quái vật tối đa có thể tiêu diệt = max(x) (x : j -> j + si) nếu max(ak) (k : j - > x) < pi 
// => với ngày bắt đầu từ con quái vật j chọn anh hùng i sao cho x MAX
// cnp(x) : kiểm tra các con quái vật từ j -> x có tồn tại anh hùng nào mà tiêu diệt hết con quái vật từ j -> x ko
// (tồn tại i sao cho si >= (j - x + 1) && pi >= max(a : j -> x))
#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
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
const int MAXN = 2e5 + 1;
int test;
int nummonster , numheros;
int monster[MAXN];
int Max[MAXN][21][2];
pii heros[MAXN]; // fi : power , se : do ben
vector<int> v;
int Get_max(int l , int r , int t)
{
    int k = log2(r - l + 1);
    return max(Max[l][k][t] , Max[r - (1 << k) + 1][k][t]);
}
bool check(int j , int x)
{
    int ma = Get_max(j , x , 0);
    int tmp = x - j + 1;
    int pos = lower_bound(v.begin() , v.end() , ma) - v.begin() + 1;
    if(pos == numheros + 1) return false;
    int MAX = Get_max(pos , numheros , 1);
    return MAX >= tmp;
}
bool cmp(pii x , pii y)
{
    return x.fi < y.fi;
}
void solve()
{
    cin >> nummonster;
    foru (i , 1 , nummonster)
    {
        cin >> monster[i];
        Max[i][0][0] = monster[i];
    }
    cin >> numheros;
    foru (i , 1 , numheros) cin >> heros[i].fi >> heros[i].se;
    sort(heros + 1 , heros + 1 + numheros , cmp);
    v.clear();
    foru (i , 1 , numheros)
    {
        v.push_back(heros[i].fi);
        Max[i][0][1] = heros[i].se;
    }
    foru (j , 1 , 20)
    {
        foru (i , 1 , nummonster - (1 << (j - 1)))
        {
            Max[i][j][0] = max(Max[i][j-1][0] , Max[i + (1 << (j - 1))][j-1][0]);
        }
        foru (i , 1 , numheros - (1 << (j - 1)))
        {
            Max[i][j][1] = max(Max[i][j-1][1] , Max[i + (1 << (j - 1))][j-1][1]);
        }
    }
    int res = 0;
    foru (i , 1 , nummonster)
    {
        int l = i , r = nummonster , ans = -1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(check(i , mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if(ans == -1)
        {
            cout << "-1" << endl;
            return;
        }
        res++;
        i = ans;
    }
    cout << res << endl;
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
        solve();
    }
    return 0;
}