#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const lli MOD = 1e9 + 9;

int n, m, q, l;
vector<vector<lli>> G(256, vector<lli>(256));

vector<vector<lli>> mul(vector<vector<lli>> &a, vector<vector<lli>> &b) {
	vector<vector<lli>> res(n, vector<lli>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;

	return res;
}

void fpow() {
	vector<vector<lli>> B = G;

	while (l) {
		if (l & 1)
			G = mul(G, B);
		B = mul(B, B), l >>= 1;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> q >> l;
	l--;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		G[u][v]++;
	}

	fpow();
	while (q--) {
		int u, v;

		cin >> u >> v;
		cout << G[u][v] << '\n';
	}
}
