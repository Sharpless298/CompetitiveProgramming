#include <iostream>
using namespace std;

int cnt[32];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k = 99;
	string s, a;

	cin >> s;

	for (int i = 0; i < (int)s.size(); i++)
		cnt[s[i] - 'A']++;
	for (int i = 0, j = 0; i < 26; i++) {
		if (cnt[i] & 1) {
			j++;
			k = i;
			if ((int)s.size() % 2 == 0 || ((int)s.size() & 1 && j == 2)) {
				cout << "NO SOLUTION\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < cnt[i] / 2; j++) {
			if (i == k)
				continue;
			a += (char)('A' + i);
		}
	}
	string b(a.rbegin(), a.rend());
	if ((int)s.size() & 1 && k != 99) {
		for (int i = 0; i < cnt[k]; i++)
			a += (char)('A' + k);
	}
	cout << a << b << '\n';
}
