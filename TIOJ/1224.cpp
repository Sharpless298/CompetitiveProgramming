#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node1 {
	int x1, x2, y, t;

	bool operator<(Node1 &a) {
		return y < a.y;
	}
};

struct Node2 {
	int data;
	int tag;
};

vector<Node2> seg(4000004);

void update(int l, int r, int x, int id = 0, int L = 0, int R = 1000001) {
	if (l >= R || L >= r)
		return;
	if (l <= L && R <= r) {
		seg[id].tag += x;
		return;
	}

	int M = (L + R) / 2;
	update(l, r, x, id * 2 + 1, L, M);
	update(l, r, x, id * 2 + 2, M, R);

	seg[id].data =
		(seg[id * 2 + 1].tag ? M - L : seg[id * 2 + 1].data) + (seg[id * 2 + 2].tag ? R - M : seg[id * 2 + 2].data);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<Node1> v;
	for (int i = 0; i < n; i++) {
		int l, r, d, u;
		cin >> l >> r >> d >> u;

		v.push_back({l, r, d, 1});
		v.push_back({l, r, u, -1});
	}

	sort(v.begin(), v.end());

	int y0 = 0, t = 0;
	long long int ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		ans += (long long int)(v[i].y - y0) * t;

		update(v[i].x1, v[i].x2, v[i].t);
		y0 = v[i].y;
		t = seg[0].data;
	}

	cout << ans << '\n';
}
