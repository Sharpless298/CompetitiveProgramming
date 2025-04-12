#include <iostream>
using namespace std;

int p, ans1, ans2, ans3, depth;
int a[100005];
string s;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (getline(cin, s)) {
		p = ans1 = ans3 = 0;
		ans2 = depth = 1;

		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == '(') {
				a[p]++;
				a[++p] = 0;
				depth++;
				ans2 = max(ans2, depth);
			} else if (s[i] == ')') {
				ans3 = max(ans3, a[p--]);
				depth--;
			}

			if (s[i] == '*') {
				a[p]++;
				ans1++;
			}
		}

		cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
	}
}
