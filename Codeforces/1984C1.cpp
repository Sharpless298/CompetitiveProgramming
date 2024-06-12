#include <iostream>
using namespace std;

typedef long long int lli;

int a[200005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n;
	lli sum, mn;

	cin >> T;
	while(T--) {
		sum = mn = 0;

		cin >> n;
		for(int i=0; i<n; i++)
			cin >> a[i];

		for(int i=0; i<n; i++) {
			sum += a[i];
			mn = min(mn, sum);
		}

		cout << sum - 2*mn << '\n';
	}
}
