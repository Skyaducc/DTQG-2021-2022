#include <iostream>
#include <bits/stdc++.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
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
int randnum(int l , int r)
{
	return rand() % (r - l + 1) + l;
}
int a[100001];
int main()
{
	srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("digits.out" , "w" , stdout);
    int h , w , r , c;
    r = randnum(4 , 8);
    c = randnum(r + 1 , 10);
    while(true)
    {
    	h = randnum(2 , r - 1);
    	if(h % 2 == 1)	break;
    }
    while(true)
    {
    	w = randnum(2 , c - 1);
    	if(w % 2 == 1) break;
    }
    foru (i , 1 , r * c)	a[i] = i;
    cout << r << " " << c << " " << h << " " << w << endl;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(a + 1 , a + 1 + r * c , std::default_random_engine(seed));
    foru (i , 1 , r * c)
    {
    	cout << a[i] << " ";
    	if(i % c == 0)	cout << endl;
    }
    return 0;
}