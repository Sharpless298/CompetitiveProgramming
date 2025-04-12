#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
int p[MAXN], q[MAXN], id[MAXN];

bool cmp(int a, int b) {
	if (p[a] == p[b])
		return q[a] > q[b];
	return p[a] < p[b];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);

	int x, y, ans = 0, maxq = -1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		p[i] = x - y, q[i] = x + y;
		id[i] = i;
	}

	sort(id, id + n, cmp);
	for (int i = 0; i < n; i++) {
		if (q[id[i]] > maxq) {
			ans++;
			maxq = q[id[i]];
		}
	}

	cout << ans << '\n';
}
