#include <algorithm>
#include <iostream>
using namespace std;

typedef long long int lli;

int n;
lli k, sum, a[200005], b[200005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		sum += b[i];
	}

	for (int i = 0; i < n; i++)
		a[i] = b[i] - a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (sum - a[i] < k) {
			cout << i << '\n';
			return 0;
		}
		sum -= a[i];
	}
	cout << n << '\n';
}
