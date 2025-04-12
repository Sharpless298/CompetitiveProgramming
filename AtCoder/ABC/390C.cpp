#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;
	vector<string> G(h);
	for (string &s : G)
		cin >> s;

	int a = 0x3f3f33f, b = -1, c = 0x3f3f3f3f, d = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (G[i][j] == '#') {
				a = min(a, i);
				b = max(b, i);
				c = min(c, j);
				d = max(d, j);
			}
		}
	}

	bool ok = true;
	for (int i = a; i <= b; i++)
		for (int j = c; j <= d; j++)
			if (G[i][j] == '.')
				ok = false;

	cout << (ok ? "Yes\n" : "No\n");
}
