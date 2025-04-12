#include <iostream>
using namespace std;

bool f;
int n, ary[1000005], ans;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	f = true;
	for (int i = 0; i < n; i++) {
		if (f)
			while (i + 1 < n && ary[i] <= ary[i + 1])
				i++;
		else
			while (i + 1 < n && ary[i] >= ary[i + 1])
				i++;
		f = !f;
		ans++;
	}
	if (f)
		ans--;

	cout << ans << '\n';
}
