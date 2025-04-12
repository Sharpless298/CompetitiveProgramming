#include <iostream>
#include <stack>
using namespace std;

stack<char> stk;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, ans;
	string s;

	cin >> n;
	cin.ignore();

	while (n--) {
		ans = 0;
		while (!stk.empty())
			stk.pop();

		getline(cin, s);

		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == 'p')
				stk.push('p');
			if (s[i] == 'q' && !stk.empty()) {
				stk.pop();
				ans++;
			}
		}

		cout << ans << '\n';
	}
}
