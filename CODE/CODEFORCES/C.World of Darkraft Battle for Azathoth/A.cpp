// n=2 vũ khí với chỉ số tấn công và giá tiền
// (2 , 3) ; (4 , 7)
// m=3 bộ giáp với chỉ số phòng thủ và giá tiền
// (2 , 4) ; (3 , 2) ; (5 , 11)
// k=3 con quái vật với chỉ số phòng thủ , tấn công và số tiền nếu tiêu diệt được
// (1 , 2 , 4) ; (2 , 1 , 6) ; (3 , 4, 6)
// -> mua vũ khí (4 , 7) và bộ giáp (3 , 2) -> tổng tiền = 9;
// -> tiêu diệt con quái vật (1 , 2 , 4) , (2 , 1 , 6) -> tổng tiền = 10;
// tính số tiền nhiều nhất (số tiền kiếm được - số tiền mua) để giết quái vật
// đk : a(i) > x(k) && b(j) > y(k)
// sort các giá trị của vũ khí (a) , giáp (b) , quái vật tăng dần
// Sa : tập hợp các con quái vật bị đánh bại bởi vũ khí a (a(i) > x(k))
// khi đó kết quả bài toán là -ca(i) - cb(j) + tổng tiền các con quái nằm trong Sa
// có chỉ số y(k) < b(j)
// ta duy trì d(j) : b(j) + tổng tiền các con quái vật có chỉ số tấn công < b(j)
// do các giá trị b(j) được sắp xếp tăng dần nên khi ta thêm một con quái vào Sa
// sẽ làm tăng một số giá trị d(j) -> ta duy trì các giá trị d(j) trong cây IT
// đối với vũ khí mới ta thêm các con quái có chỉ số x(k) < a(i) vào 
// và các giá trị d(j) (có b(j) < y(k)) tăng thêm z(k)
// với mỗi vũ khí i kết quả bài toán là -ca(i) + Max(D(j))
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
const long long oo = 1e18;
const int MAXN = 2 * 1e5 + 1;
int n , m , p;
struct Weapon
{
	int atk , cost;
	bool operator < (const Weapon &tmp) const
	{
		return atk < tmp.atk;
	}
};
struct Armor
{
	int def , cost;
	bool operator < (const Armor &tmp) const
	{
		return def < tmp.def;
	}
};
struct Monster
{
	int def , atk , cost;
	bool operator < (const Monster &tmp) const
	{
		return def < tmp.def;
	}
};
vector<Weapon> weapon;
vector<Armor> armor;
vector<Monster> monster;
vector<int> v;
struct Data
{
	long long val , lazy;
} tree[4 * MAXN];
void push(int id)
{
	int t = tree[id].lazy;
	tree[id*2].val += t;
	tree[id*2].lazy += t;
	tree[id*2+1].val += t;
	tree[id*2+1].lazy += t;
	tree[id].lazy = 0;
}
void build(int id , int l , int r)
{	
	if(l == r)
	{
		tree[id].val = -armor[l-1].cost;
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2 , l , mid);
	build(id * 2 + 1 , mid + 1 , r);
	tree[id].val = max(tree[id * 2].val , tree[id * 2 + 1].val);
}
void update(int id , int l , int r , int u , int v , int x)
{
	if(r < u || v < l)	return;
	if(u <= l && r <= v)
	{
		tree[id].val += x;
		tree[id].lazy += x;
		return;
	}
	push(id);
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , v , x);
	update(id * 2 + 1 , mid + 1 , r , u , v , x);
	tree[id].val = max(tree[id * 2].val , tree[id * 2 + 1].val);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> p;
    foru(i , 1 , n)
    {
    	int x , y;
    	cin >> x >> y;
    	weapon.push_back({x , y});
    }
    foru(i , 1 , m)
    {
    	int x , y;
    	cin >> x >> y;
    	armor.push_back({x , y});
    }
    foru(i , 1 , p)
    {
    	int x , y , z;
    	cin >> x >> y >> z;
    	monster.push_back({x , y , z});
    }
  	sort(weapon.begin() , weapon.end());
  	sort(armor.begin() , armor.end());
  	sort(monster.begin() , monster.end());
  	foru(i , 0 , m-1)
  	{
  		v.push_back(armor[i].def);
  	}
  	int Prevmonster = 0;
    build(1 , 1 , m);
    long long res = -oo;
  	foru(i , 0 , n-1)
  	{
        foru(j , Prevmonster , p-1)
        {
            if (monster[j].def < weapon[i].atk)
            {
                Prevmonster++;
                int pos = upper_bound(v.begin() , v.end(), monster[j].atk) - v.begin();
                update(1 , 1 , m , pos + 1 , m , monster[j].cost);
            }
            else
            {
                break;
            }
        }
        push(1);
        res = max(res , tree[1].val - weapon[i].cost);
    }
  	cout << res;
    return 0;
}
