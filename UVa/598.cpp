#include <iostream>
using namespace std;

int k, n;
int path[16];
string newspaper[16];

void DFS(int depth, int p) {
	if (depth == n) {
		for (int i = 0; i < n; i++) {
			if (i)
				cout << ", ";
			cout << newspaper[path[i]];
		}
		cout << '\n';
		return;
	}

	for (int i = p; i < k; i++) {
		path[depth] = i;
		DFS(depth + 1, i + 1);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool f = false;
	int t, a, b;
	string s, p;

	cin >> t;
	cin.ignore();
	cin.ignore();

	while (t--) {
		if (f)
			cout << '\n';
		f = true;

		k = 0;

		getline(cin, s);
		while (1) {
			getline(cin, newspaper[k]);
			if (newspaper[k] == "")
				break;
			k++;
		}

		if (s.size() == 1) {
			if (s[0] != '*') {
				n = stoi(s);
				cout << "Size " << n << '\n';
				DFS(0, 0);
			} else {
				for (int i = 0; i < k; i++) {
					if (i)
						cout << '\n';
					n = i + 1;
					cout << "Size " << n << '\n';
					DFS(0, 0);
				}
			}
		} else {
			int space = s.find(" ");

			a = stoi(s.substr(0, space));
			b = stoi(s.substr(space + 1));
			for (int i = a; i <= b; i++) {
				if (i - a)
					cout << '\n';
				n = i;
				cout << "Size " << n << '\n';
				DFS(0, 0);
			}
		}
		cout << '\n';
	}
}
