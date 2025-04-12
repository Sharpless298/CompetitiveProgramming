#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int fact(int n) {
	int res = 1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;

	cin >> s;
	sort(s.begin(), s.end());

	vector<int> cnt(26);
	for (int i = 0; i < (int)s.size(); i++)
		cnt[s[i] - 'a']++;

	int ans = fact((int)s.size());
	for (int i = 0; i < 26; i++)
		ans /= fact(cnt[i]);

	cout << ans << '\n';
	do {
		cout << s << '\n';
	} while (next_permutation(s.begin(), s.end()));
}
