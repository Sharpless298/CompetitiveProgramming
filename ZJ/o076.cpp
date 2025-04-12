#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int len = 0, ans = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1])
			len++;
		else {
			ans = max(len + 1, ans);
			len = 0;
		}
	}
	ans = max(len + 1, ans);

	cout << ans << '\n';
}
