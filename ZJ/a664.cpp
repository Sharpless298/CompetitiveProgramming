#include <iostream>
#include <stack>
using namespace std;

typedef long long int lli;

bool pri[128];
stack<char> op;
stack<lli> stk;

lli calc(lli a, lli b, char ope) {
	if (ope == '+')
		return a + b;
	if (ope == '-')
		return a - b;
	if (ope == '*')
		return a * b;
	if (ope == '/')
		return a / b;

	return -1;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool is_num = false;
	char ope;
	int t;
	lli a, b, num = 0;
	string s;

	pri['*'] = pri['/'] = true;

	cin >> t;

	while (t--) {
		is_num = false;
		num = 0;
		while (!stk.empty())
			stk.pop();

		cin >> s;

		for (auto &c : s) {
			if (isdigit(c)) {
				is_num = true;
				num = num * 10 + c - '0';
			} else {
				if (is_num) {
					stk.push(num);
					is_num = false;
					num = 0;
				}

				if (c == '(')
					op.push(c);
				else if (c == ')') {
					while (op.top() != '(') {
						b = stk.top();
						stk.pop();
						a = stk.top();
						stk.pop();
						ope = op.top();
						op.pop();
						stk.push(calc(a, b, ope));
					}
					op.pop();
				} else {
					while (!op.empty() && op.top() != '(' && pri[(int)op.top()]) {
						b = stk.top();
						stk.pop();
						a = stk.top();
						stk.pop();
						ope = op.top();
						op.pop();
						stk.push(calc(a, b, ope));
					}
					op.push(c);
				}
			}
		}
		if (is_num)
			stk.push(num);

		while (stk.size() > 1) {
			b = stk.top();
			stk.pop();
			a = stk.top();
			stk.pop();
			ope = op.top();
			op.pop();
			stk.push(calc(a, b, ope));
		}

		cout << stk.top() << '\n';
	}
}
