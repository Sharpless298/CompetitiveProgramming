#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end(), [&](string a, string b) { return a.size() < b.size(); });
	for (string s : v)
		cout << s;
	cout << '\n';
}
