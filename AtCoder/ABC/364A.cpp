#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool f = false;
	int n;
	string s[100];
	cin >> n;
	cin >> s[0];
	for (int i = 1; i < n; i++) {
		cin >> s[i];

		if (s[i] == "sweet" && s[i - 1] == "sweet" && i != n - 1)
			f = true;
	}

	cout << (f ? "No\n" : "Yes\n");
}
