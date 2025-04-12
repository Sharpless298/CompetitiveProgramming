#include <algorithm>
#include <iostream>
using namespace std;

int n, q, ary[100005], l, r, k;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	sort(ary, ary + n);
	while (q--) {
		l = 0, r = 1;
		cin >> k;

		while (r < n) {
			if (ary[r] - ary[l] == k)
				break;
			else if (ary[r] - ary[l] < k)
				r++;
			else
				l++;
		}
		if (ary[r] - ary[l] == k)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
