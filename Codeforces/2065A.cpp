#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		s.pop_back();
		s.pop_back();
		s.push_back('i');
		cout << s << '\n';
	}
}
