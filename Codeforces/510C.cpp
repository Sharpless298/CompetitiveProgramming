#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool f;
int in[32];
string s, t;
vector<int> G[32], ans;

void build() {
	int idx = 0;
	while (idx < (int)min(s.size(), t.size())) {
		if (s[idx] != t[idx]) {
			G[s[idx] - 'a'].push_back(t[idx] - 'a');
			in[t[idx] - 'a']++;
			return;
		}
		idx++;
	}

	if (s.size() > t.size())
		f = true;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, v;

	cin >> n;
	cin >> s;
	for (int i = 0; i < n - 1; i++) {
		cin >> t;
		build();
		s = t;
	}

	if (f)
		cout << "Impossible\n";
	else {
		queue<int> q;
		for (int i = 0; i < 26; i++)
			if (in[i] == 0)
				q.push(i);

		while (!q.empty()) {
			v = q.front(), q.pop();
			ans.push_back(v);

			for (int i : G[v])
				if (--in[i] == 0)
					q.push(i);
		}

		if (ans.size() != 26)
			cout << "Impossible";
		else
			for (int i : ans)
				cout << (char)(i + 'a');
		cout << '\n';
	}
}
