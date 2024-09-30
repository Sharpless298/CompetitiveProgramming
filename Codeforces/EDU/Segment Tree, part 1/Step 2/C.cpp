#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> a, seg;

void build(int L = 0, int R = n, int id = 0) {
	if(R-L == 1) {
		seg[id] = a[L];
		return;
	}

	int M = (L+R)/2;
	build(L, M, id*2+1);
	build(M, R, id*2+2);
	seg[id] = max(seg[id*2+1], seg[id*2+2]);
}

void update(int x, int v, int L = 0, int R = n, int id = 0) {
	if(x<L || x>=R) return;
	if(R-L == 1) {
		seg[id] = v;
		return;
	}
	
	int M = (L+R)/2;
	update(x, v, L, M, id*2+1);
	update(x, v, M, R, id*2+2);
	seg[id] = max(seg[id*2+1], seg[id*2+2]);
}

int query(int x, int L = 0, int R = n, int id = 0) {
	if(R-L == 1) return L;

	int M = (L+R)/2;
	if(seg[id*2+1] >= x) 
		return query(x, L, M, id*2+1);
	else 
		return query(x, M, R, id*2+2);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	a.resize(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	seg.resize(4*n);
	build();
	
	while(m--) {
		int t;
		cin >> t;

		if(t == 1) {
			int i, v;
			cin >> i >> v;
			update(i, v);
		}
		else {
			int x;
			cin >> x;
			if(seg[0] < x) cout << -1 << '\n';
			else cout << query(x) << '\n';;
		}
	}
}

