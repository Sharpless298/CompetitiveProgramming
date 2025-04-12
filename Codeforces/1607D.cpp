#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool ans;
int T, n, a[200005];
string c;
vector<int> l, r;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		ans = true;
		l.clear(), r.clear();

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cin >> c;

		for (int i = 0; i < n; i++)
			(c[i] == 'B' ? l : r).push_back(a[i]);

		sort(l.begin(), l.end());
		sort(r.begin(), r.end(), greater<int>());

		for (int i = 0; i < (int)l.size(); i++)
			if (l[i] < i + 1)
				ans = false;
		for (int i = 0; i < (int)r.size(); i++)
			if (r[i] > n - i)
				ans = false;

		cout << (ans ? "YES" : "NO") << '\n';
	}
}
