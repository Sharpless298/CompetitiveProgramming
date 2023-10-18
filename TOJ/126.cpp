#include <iostream>
#include <bitset>
using namespace std;

int n, q, ans[20005];
bitset<20005> b;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;

	b[10000] = 1;
	for(int i=0, x; i<n; i++) {
		cin >> x;
		b = (b<<x) | (b>>x);
	}
	for(int i=20000, pre=i; i>=0; i--) {
		if(b[i]) pre = i;
		ans[i] = pre;
	}
	for(int i=0, x; i<q; i++) {
		cin >> x;
		cout << ans[x+10000] - 10000 << '\n';
	}
}
