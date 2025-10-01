#include <bits/stdc++.h>
using namespace std;

int ask (int x) {
    cout << "- " << x << endl;
    if (x == -1)
        exit(0);
    cin >> x;
    return x;
}

signed main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int cnt;
        cin >> cnt;
        int n = 0;
        int was = 0;
        while (cnt > 0) {
            n += 1;
            int nw = ask(1 + was);
            int back = nw - cnt + 1;
            n += (1 << back) - 1;
            was = (1 << back) - 1;
            cnt = nw - back;
        }
        cout << "! " << n << endl;
	}
}
