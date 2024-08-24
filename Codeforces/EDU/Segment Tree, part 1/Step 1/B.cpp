#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

int n, m;
vector<int> a;
vector<lli> seg;

void build(int L = 0, int R = n, int id = 0) {
	if(R-L == 1) {
		seg[id] = a[L];
		return;
	}
	int M = (L+R)/2;
	build(L, M, id*2+1);
	build(M, R, id*2+2);
	seg[id] = min(seg[id*2+1], seg[id*2+2]);
}

void update(int x, int v, int L = 0, int R = n, int id = 0) {
	if(R-L == 1) {
		seg[id] = v;
		return;
	}
	
	int M = (L+R)/2;
	if(x < M)
		update(x, v, L, M, id*2+1);
	else 
		update(x, v, M, R, id*2+2);
	seg[id] = min(seg[id*2+1], seg[id*2+2]);
}

lli query(int l, int r, int L = 0, int R = n, int id = 0) {
	if(l>=R || r<=L) return 2000000000;
	if(l<=L && R<=r) return seg[id];
	
	int M = (L+R)/2;
	return min(query(l, r, L, M, id*2+1), query(l, r, M, R, id*2+2));
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
		int t, i, v, l, r;
		cin >> t;
		
		if(t == 1) {
			cin >> i >> v;
			update(i, v);
		}
		else {
			cin >> l >> r;
			cout << query(l, r) << '\n';
		}
	}
}

