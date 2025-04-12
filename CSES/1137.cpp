#include <iostream>
#include <vector>
using namespace std;

#define lowbit(x) x & -x

int n;
vector<vector<int>> G;

vector<long long> BIT;

void update(int i, int x) {
	for (; i <= n; i += lowbit(i))
		BIT[i] += x;
}

long long query(int i) {
	long long sum = 0;
	for (; i; i -= lowbit(i))
		sum += BIT[i];
	return sum;
}

vector<int> in, out;

int t;
void DFS(int u, int f) {
	in[u] = t++;
	for (int v : G[u])
		if (v != f)
			DFS(v, u);
	out[u] = t;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	G.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;

		G[u].push_back(v);
		G[v].push_back(u);
	}

	in.resize(n);
	out.resize(n);
	DFS(0, -1);

	BIT.resize(n + 1);
	for (int i = 0; i < n; i++)
		update(in[i] + 1, a[i]);

	while (q--) {
		int type;
		cin >> type;

		if (type == 1) {
			int s, x;
			cin >> s >> x;
			s--;

			update(in[s] + 1, x - a[s]);
			a[s] = x;
		} else {
			int s;
			cin >> s;
			s--;

			cout << query(out[s]) - query(in[s]) << '\n';
		}
	}
}
