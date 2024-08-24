#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int mn;
	int cnt;
};

int n, m;
vector<int> a;
vector<Node> seg;

void pull(int id) {
	if(seg[id*2+1].mn < seg[id*2+2].mn) 
		seg[id] = seg[id*2+1];
	else if(seg[id*2+1].mn > seg[id*2+2].mn) 
		seg[id] = seg[id*2+2];
	else 
		seg[id].mn = seg[id*2+1].mn, seg[id].cnt = seg[id*2+1].cnt + seg[id*2+2].cnt;
}

void build(int L = 0, int R = n, int id = 0) {
	if(R-L == 1) {
		seg[id].mn = a[L];
		seg[id].cnt = 1;
		return;
	}
	int M = (L+R)/2;
	build(L, M, id*2+1);
	build(M, R, id*2+2);
	pull(id);
}

void update(int x, int v, int L = 0, int R = n, int id = 0) {
	if(R-L == 1) {
		seg[id].mn = v;
		return;
	}
	
	int M = (L+R)/2;
	if(x < M)
		update(x, v, L, M, id*2+1);
	else 
		update(x, v, M, R, id*2+2);
	pull(id);
}

Node query(int l, int r, int L = 0, int R = n, int id = 0) {
	if(l>=R || r<=L) return {2000000000, 1};
	if(l<=L && R<=r) return seg[id];
	
	int M = (L+R)/2;
	Node x = query(l, r, L, M, id*2+1), y = query(l, r, M, R, id*2+2);
	
	if(x.mn < y.mn) 
		return x;
	else if(x.mn > y.mn) 
		return y;
	else
		return {x.mn, x.cnt+y.cnt};
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
			Node ans = query(l, r);
			cout << ans.mn << ' ' << ans.cnt << '\n';
		}
	}
}
