#include <iostream>
#include <unordered_set>
using namespace std;

int ans;
unordered_set<string> us;

void check(string &t) {
	string p, q;

	for (int i = 1; i * 2 <= (int)t.size(); i++) {
		p = t.substr(0, i);
		q = t.substr(t.size() - i, i);
		if (p == q && us.find(t.substr(i, t.size() - i * 2)) != us.end())
			ans++;
	}
	return;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	string s;

	cin >> m;
	while (m--) {
		cin >> s;
		us.insert(s);
	}

	for (string t : us)
		check(t);

	cout << ans << '\n';
}
