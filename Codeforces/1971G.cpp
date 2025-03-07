#include <iostream>
#include <map>
#include <queue>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, priority_queue<int, vector<int>, greater<int>>> mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i] >> 2].push(a[i]);
		}

		for (int i = 0; i < n; i++) {
			cout << mp[a[i] >> 2].top() << ' ';
			mp[a[i] >> 2].pop();
		}
		cout << '\n';
	}
}
