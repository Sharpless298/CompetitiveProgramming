#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a[3];
	string s;

	for (int i = 0; i < 3; i++)
		cin >> a[i];
	cin >> s;
	if (s[0] == 'R')
		s[0] = '0';
	else if (s[0] == 'G')
		s[0] = '1';
	else
		s[0] = '2';

	int ans = 0x3f3f3f3f;
	for (int i = 0; i < 3; i++)
		if (s[0] - '0' != i)
			ans = min(ans, a[i]);

	cout << ans << '\n';
}
