#include <iostream>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	lli n, k;

	cin >> T;
	while(T--) {
		cin >> n >> k;
		
		if(k%(n-1) == 0) cout << k/(n-1)*n-1 << '\n';
		else cout << k/(n-1)*n+k%(n-1) << '\n';
	}
}
