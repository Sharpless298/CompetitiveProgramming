#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> mp;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, id;
	string s;

	while (cin >> n) {
		id = 0;
		mp.clear();

		for (int i = 0; i < n; i++) {
			cin >> s;
			if (!mp[s])
				cout << "New! ", mp[s] = ++id;
			else
				cout << "Old! ";
			cout << mp[s] << '\n';
		}
	}
}
