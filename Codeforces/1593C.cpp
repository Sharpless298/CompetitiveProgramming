#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int k;
		long long n;
		cin >> n >> k;
		vector<int> a(k);
		for (int i = 0; i < k; i++)
			cin >> a[i];
		sort(a.begin(), a.end(), greater<int>());

		int ans = 0;
		long long sum = 0;
		while (ans < k && sum < a[ans])
			sum += n - a[ans++];

		cout << ans << '\n';
	}
}
