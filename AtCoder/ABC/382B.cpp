#include <algorithm>
#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d;
	cin >> n >> d;
	string s;
	cin >> s;
	for (int i = n - 1; i >= 0; i--)
		if (d != 0 && s[i] == '@')
			s[i] = '.', d--;

	cout << s << '\n';
}
