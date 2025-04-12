#include <iostream>
using namespace std;

char stk[1000];
int top = -1;
string s;

void push(char data) {
	stk[++top] = data;
}

void pop() {
	top--;
}

char query() {
	if (top == -1)
		return 'T';
	return stk[top];
}

bool check(char c) {
	if ((query() == '(' && c == ')') || (query() == '[' && c == ']'))
		return true;
	return false;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		top = -1;

		getline(cin, s);

		if (!s.empty())
			push(s[0]);
		for (int i = 1; i < s.size(); i++) {
			if (check(s[i]))
				pop();
			else
				push(s[i]);
		}

		if (query() == 'T')
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
