#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int INF = 1e7;

bool f;
int ans, b, n, l;
long long int p[1024], q[1024], temp[1024], mask;
string s;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;

	for (int Case = 1; Case <= T; Case++) {
		ans = INF;
		memset(p, 0, sizeof(p));
		memset(q, 0, sizeof(q));

		cin >> n >> l;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < l; j++)
				p[i] |= ((long long int)(s[j] - '0') << j);
		}
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < l; j++)
				q[i] |= ((long long int)(s[j] - '0') << j);
		}

		sort(p, p + n);
		for (int i = 0; i < n; i++) {
			f = true;

			mask = (p[0] ^ q[i]);
			for (int j = 0; j < n; j++)
				temp[j] = (q[j] ^ mask);
			sort(temp, temp + n);
			for (int j = 0; j < n; j++) {
				if (p[j] != temp[j]) {
					f = false;
					break;
				}
			}
			if (f) {
				b = 0;
				while (mask) {
					mask ^= (mask & -mask);
					b++;
				}
				ans = min(ans, b);
			}
		}

		if (ans == INF)
			cout << "Case #" << Case << ": " << "IMPOSSIBLE" << '\n';
		else
			cout << "Case #" << Case << ": " << ans << '\n';
	}
}
