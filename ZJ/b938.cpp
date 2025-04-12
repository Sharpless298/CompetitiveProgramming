#include <iostream>
using namespace std;

const int MAXN = 1e6 + 5;

bool f[MAXN];
int nxt[MAXN];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n, k;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		nxt[i] = i + 1;

	for (int i = 0; i < m; i++) {
		cin >> k;

		if (f[k] || nxt[k] == n + 1) {
			cout << "0u0 ...... ?\n";
			continue;
		}
		cout << nxt[k] << '\n';
		f[nxt[k]] = true;
		nxt[k] = nxt[nxt[k]];
	}
}
