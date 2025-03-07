#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;

	cin >> n >> s;

	for (int i = 0; i < n; i++)
		if (s[i] & (1 << 5))
			cout << (char)(s[i] - 32);
		else
			cout << (char)(s[i] + 32);
	cout << '\n';
}
