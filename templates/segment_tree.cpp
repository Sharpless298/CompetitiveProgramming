#include <iostream>
#include <vector>
using namespace std;

vector<Node> seg;

void pull(){}

void build(int L = 0, int R = n, int id = 0) {
	if(R-L == 1) {
		seg[id] = a[L];
		return;
	}

	int M = (L+R)/2;
	build(L, M, id*2+1);
	build(M, R, id*2+2);
	pull(id);
}

void update(int l, int r, int L = 0, int R = n, int id = 0) {
	if(l>=R || r<=L) return;
	if(l<=L && R<=r) return seg[id];

	int M = (L+R)/2;
	update(l, r, L, M, id*2+1);
	update(l, r, M, R, id*2+2);
	pull(id);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

}
