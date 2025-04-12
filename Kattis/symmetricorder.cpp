#include <iostream>
using namespace std;

int id, top = -1;
string name[100], stk[100];

void push(string name) {
	stk[++top] = name;
}

void pop() {
	if (top == -1)
		return;
	top--;
}

string query() {
	return stk[top];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;

	while (cin >> n && n) {
		id++;
		for (int i = 0; i < n; i++)
			cin >> name[i];

		cout << "SET " << id << '\n';
		for (int i = 0; i < n; i++) {
			if (i & 1)
				push(name[i]);
			else
				cout << name[i] << '\n';
		}
		while (top != -1) {
			cout << query() << '\n';
			pop();
		}
	}
}
