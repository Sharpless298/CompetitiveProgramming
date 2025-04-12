#include <iostream>
using namespace std;

string pre, in;

void solve(int l, int r, int pre_idx) {
	if (l >= r)
		return;

	int idx = (int)in.find(pre[pre_idx]);
	int len = idx - l;

	solve(l, l + len, pre_idx + 1);
	solve(idx + 1, r, pre_idx + len + 1);

	cout << in[idx];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> pre >> in) {
		solve(0, (int)pre.size(), 0);
		cout << '\n';
	}
}
