#include <algorithm>
#include <iostream>
using namespace std;

bool used[128];
char p[128];
int len, c, d;
string s;

char uppercase(char &c) {
	if ('a' <= c && c <= 'z')
		return c - 32;
	return c;
}

bool cmp(char &a, char &b) {
	c = uppercase(a);
	d = uppercase(b);
	if (c == d)
		return a < b;
	else
		return c < d;
}

void DFS(int depth) {
	if (depth == len) {
		for (int i = 0; i < len; i++)
			cout << p[i];
		cout << '\n';
	}

	for (int i = 0, last = -1; i < len; i++) {
		if (!used[i] && s[i] != last) {
			used[i] = true;
			p[depth] = s[i];
			DFS(depth + 1);
			used[i] = false;
			last = s[i];
		}
	}
}

void solve() {
	len = s.size();
	sort(s.begin(), s.end(), cmp);
	DFS(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	while (n--) {
		cin >> s;

		solve();
	}
}
