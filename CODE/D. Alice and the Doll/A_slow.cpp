#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main() {
	freopen("A.INP" , "r" , stdin);
    freopen("A.ANS" , "w" , stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	vector<int> ox[n + 5];
	vector<int> oy[m + 5];
	if(k == 0) {
		printf("Yes\n");
		return 0;
	}
	for(int i = 1; i <= k; i++) {
		int x, y;
		scanf("%d%d",&x,&y);
		ox[x].push_back(y);
		oy[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) {
		sort(ox[i].begin(), ox[i].end());
	}
	for(int i = 1; i <= m; i++) {
		sort(oy[i].begin(), oy[i].end());
	}

	int Xmin = 0, Xmax = n + 1, Ymin = 0, Ymax = m + 1;
	int Xnow = 1, Ynow = 1, x = 1, y = 1;
	int pos = 0;
	long long ans = 1;
	bool move = false;
	while(true) {
		if(pos == 0) {
			x = Xnow, y = Ynow;
			int first = lower_bound(ox[Xnow].begin(), ox[Xnow].end(), Ynow) - ox[Xnow].begin();
			//printf("%d\n",first);
			if(first == (int)ox[Xnow].size()) {
				y = Ymax - 1;
			} else {
				y = min(Ymax - 1, ox[Xnow][first] - 1);
			}
			Xmin = Xnow;
		} else if(pos == 1) {
			x = Xnow, y = Ynow;
			int first = lower_bound(oy[Ynow].begin(), oy[Ynow].end(), Xnow) - oy[Ynow].begin();
			//printf("%d\n",first);
			if(first == (int)oy[Ynow].size()) {
				x = Xmax - 1;
			} else {
				x = min(Xmax - 1, oy[Ynow][first] - 1);
			}
			Ymax = Ynow;
		} else if(pos == 2) {
			x = Xnow, y = Ynow;
			int first = lower_bound(ox[Xnow].begin(), ox[Xnow].end(), Ynow) - ox[Xnow].begin();
			//printf("%d\n",first);
			if(first == 0) {
				y = Ymin + 1;
			} else {
				y = max(Ymin + 1, ox[Xnow][first - 1] + 1);
			}
			Xmax = Xnow;
		} else if(pos == 3) {
			x = Xnow, y = Ynow;
			int first = lower_bound(oy[Ynow].begin(), oy[Ynow].end(), Xnow) - oy[Ynow].begin();
			//printf("%d\n",first);
			if(first == 0) {
				x = Xmin + 1;
			} else {
				x = max(Xmin + 1, oy[Ynow][first - 1] + 1);
			}
			Ymin = Ynow;
		}
		if(x == Xnow && y == Ynow && move) {
			break;
		}
		pos++;
		pos %= 4;
		ans += (long long)(abs(x - Xnow) + abs(y - Ynow));
		Xnow = x;
		Ynow = y;
		move = true;
	}
	//printf("%lld\n",ans);
	if(ans == (long long) n*m-k) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}