#include <iostream>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int w, h, n;
	cin >> w >> h >> n;
	
	lli l = 0, r = 1e14;

	while(l < r) {
		lli m = (l+r)/2;
	
		if((__int128)(m/w)*(m/h) < n) l = m+1;
		else r = m;
	}

	cout << l << '\n';
}
