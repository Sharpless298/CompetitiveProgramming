#include <cstring>
#include <iostream>
using namespace std;

char t;
int n, ans, mask, id;
int G[32];

void DFS(int depth, int p, int q, int c) {
	if (depth == n) {
		ans++;
		return;
	}

	int valid = ~(p | q | c | G[depth]) & mask;
	while (valid) {
		int lowbit = (valid & -valid);
		DFS(depth + 1, (p | lowbit) << 1, (q | lowbit) >> 1, (c | lowbit));
		valid &= ~lowbit;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n && n) {
		ans = 0;
		mask = (1 << n) - 1;
		memset(G, 0, sizeof(G));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> t;
				if (t == '*')
					G[i] |= (1 << j);
			}
		}

		DFS(0, 0, 0, 0);

		cout << "Case " << ++id << ": " << ans << '\n';
	}
}
