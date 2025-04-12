#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int cnt = 0;
	for (char c : s)
		if (c == '2')
			cnt++;
	for (int i = 0; i < cnt; i++)
		cout << '2';
	cout << '\n';
}
