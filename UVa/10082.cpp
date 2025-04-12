#include <iostream>
using namespace std;

int tbl[128];
string s;
string key = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i < key.size(); i++)
		tbl[key[i]] = key[i - 1];
	tbl[' '] = ' ';

	while (getline(cin, s)) {
		for (int i = 0; i < s.size(); i++)
			s[i] = tbl[s[i]];

		cout << s << '\n';
	}
}
