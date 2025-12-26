#include <bits/stdc++.h>
using namespace std;

string encode(int x) {
	string s(7, 'a');
	for (int i = 0; i < 7; i++) {
		s[i] = (char)(x % 26 + 'a');
		x /= 26;
	}
	return s;
}

int decode(string s) {
	int x = 0;
	for (int i = 6; i >= 0; i--) {
		x = x * 26 + (s[i] - 'a');
	}
	return x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string t;
	cin >> t;
	if (t == "first") {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			cout << encode(a);
		}
	} else {
		string s;
		cin >> s;
		cout << s.size() / 7 << '\n';
		for (int i = 0; i < (int)s.size(); i += 7) {
			string u = s.substr(i, 7);
			cout << decode(u) << " ";
		}
	}
}
