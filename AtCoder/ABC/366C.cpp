#include <iostream>
#include <set>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q, cnt = 0;
	multiset<int> ms;
	cin >> q;
	while (q--) {
		int t, x;

		cin >> t;
		if (t == 1) {
			cin >> x;
			if (ms.count(x) == 0)
				cnt++;
			ms.insert(x);
		} else if (t == 2) {
			cin >> x;
			ms.erase(ms.find(x));
			if (ms.count(x) == 0)
				cnt--;
		} else
			cout << cnt << '\n';
	}
}
