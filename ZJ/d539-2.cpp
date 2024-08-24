#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a, seg;

void build(int L = 0, int R = n-1, int id = 0) {
	if(L == R) {
		seg[id] = a[L];
		return;
	}
	int M = (L+R)/2;

	build(L, M, id*2+1);
	build(M+1, R, id*2+2);
	seg[id] = max(seg[id*2+1], seg[id*2+2]);
}

int query(int l, int r, int L = 0, int R = n-1, int id = 0) {
	if(l<=L && R<=r) return seg[id];

	int M = (L+R)/2;
	if(r <= M)
		return query(l, r, L, M, id*2+1);
	else if(l > M)
		return query(l, r, M+1, R, id*2+2);
	else
		return max(query(l, r, L, M, id*2+1), query(l, r, M+1, R, id*2+2));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	a.resize(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	seg.resize(4*n);
	build();

	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;

		if(l > r) swap(l, r);
		cout << query(l, r) << '\n';
	}
}

