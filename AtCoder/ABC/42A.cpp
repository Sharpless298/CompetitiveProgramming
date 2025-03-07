#include <iostream>
using namespace std;

int cnt[128];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;

	cin >> a >> b >> c;

	cnt[a]++, cnt[b]++, cnt[c]++;

	if (cnt[5] == 2 && cnt[7] == 1)
		cout << "YES\n";
	else
		cout << "NO\n";
}
