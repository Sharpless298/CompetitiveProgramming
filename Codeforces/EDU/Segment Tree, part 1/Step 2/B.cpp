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
	seg[id] = seg[id*2+1] + seg[id*2+2];
}

void update(int k, int L = 0, int R = n, int id = 0) {
	if(k<L || k>=R) return;
	if(R-L==1) {
		seg[id] = !seg[id];
		return;
	}

	int M = (L+R)/2;
	update(k, L, M, id*2+1);
	update(k, M, R, id*2+2);
	seg[id] = seg[id*2+1] + seg[id*2+2];
}

int find(int k, int L = 0, int R = n, int id = 0) {
	if(R-L == 1) return L;

	int M = (L+R)/2;
	if(k < seg[id*2+1]) 
		return find(k, L, M, id*2+1);
	else 
		return find(k-seg[id*2+1], M, R, id*2+2);

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
		int t, k;
		cin >> t >> k;

		if(t == 1) 
			update(k);	
		else 
			cout << find(k) << '\n';
	}
}

