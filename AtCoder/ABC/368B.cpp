#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0;
	while (true) {
		sort(a.begin(), a.end(), greater<int>());

		if (a[1] <= 0)
			break;

		a[0]--, a[1]--;
		ans++;
	}

	cout << ans << '\n';
}
