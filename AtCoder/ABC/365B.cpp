#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first, a[i].second = i + 1;

	sort(a.begin(), a.end());

	cout << a[n - 2].second << '\n';
}
