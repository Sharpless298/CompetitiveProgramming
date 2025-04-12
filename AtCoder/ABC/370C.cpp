#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s, t;
	cin >> s >> t;

	int n = (int)s.size();
	vector<string> ans;
	for (int i = 0; i < n; i++)
		if (s[i] > t[i])
			s[i] = t[i], ans.push_back(s);

	for (int i = n - 1; i >= 0; i--)
		if (s[i] < t[i])
			s[i] = t[i], ans.push_back(s);

	cout << ans.size() << '\n';
	for (string &i : ans)
		cout << i << '\n';
}
