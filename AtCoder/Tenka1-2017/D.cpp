#include <iostream>
using namespace std;

typedef long long int lli;

int n;
lli k, cur, ans, t;
lli a[100005], b[100005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	k++;
	for (int i = 0; i <= 30; i++) {
		cur = 0;
		t = 1 << i;

		if (k & t) {
			t = (k ^ t) | (t - 1);

			for (int j = 0; j < n; j++)
				if ((a[j] & t) == a[j])
					cur += b[j];
			ans = max(ans, cur);
		}
	}

	cout << ans << '\n';
}
