#include <algorithm>
#include <iostream>
using namespace std;

string s[128];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l;

	cin >> n >> l;

	for (int i = 0; i < n; i++)
		cin >> s[i];

	sort(s, s + n);

	for (int i = 0; i < n; i++)
		cout << s[i];
	cout << '\n';
}
