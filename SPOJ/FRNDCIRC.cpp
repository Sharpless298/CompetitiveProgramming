#include <iostream>
#include <map>
using namespace std;

map<string, string> parent;
map<string, int> sz;

string query(string x) {
	if (parent[x] == x)
		return x;
	return parent[x] = query(parent[x]);
}

void Union(string a, string b) {
	a = query(a), b = query(b);

	if (a == b) {
		cout << sz[a] << '\n';
		return;
	}

	if (sz[a] > sz[b])
		swap(a, b);
	parent[a] = b, sz[b] += sz[a], sz[a] = sz[b];
	cout << sz[b] << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n;
	string s, t;

	cin >> T;
	while (T--) {
		parent.clear(), sz.clear();

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s >> t;

			if (parent[s] == "")
				parent[s] = s, sz[s] = 1;
			if (parent[t] == "")
				parent[t] = t, sz[t] = 1;
			Union(s, t);
		}
	}
}
