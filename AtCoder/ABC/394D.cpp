#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	if (s.size() & 1) {
		cout << "No\n";
	} else {
		stack<char> stk;
		for (char c : s) {
			if (!stk.empty() && stk.top() == '(' && c == ')') {
				stk.pop();
				continue;
			}
			if (!stk.empty() && stk.top() == '<' && c == '>') {
				stk.pop();
				continue;
			}
			if (!stk.empty() && stk.top() == '[' && c == ']') {
				stk.pop();
				continue;
			}
			stk.push(c);
		}
		cout << (stk.empty() ? "Yes\n" : "No\n");
	}
}
