#include <iostream>
#include <stack>
using namespace std;

int ary[1005];
stack<int> stk;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t;

	while (cin >> n && n) {
		while (cin >> t) {
			while (!stk.empty()) {
				stk.pop();
			}

			if (!t) {
				cout << '\n';
				break;
			}

			ary[0] = t;
			for (int i = 1; i < n; i++)
				cin >> ary[i];
			for (int i = 1, j = 0; i <= n; i++) {
				stk.push(i);
				while (!stk.empty() && ary[j] == stk.top()) {
					stk.pop();
					j++;
				}
			}

			if (!stk.empty())
				cout << "No\n";
			else
				cout << "Yes\n";
		}
	}
}
