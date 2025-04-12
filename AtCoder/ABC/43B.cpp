#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	vector<int> v;
	for (char c : s) {
		if (c == '0')
			v.push_back(0);
		if (c == '1')
			v.push_back(1);
		if (c == 'B' && !v.empty())
			v.pop_back();
	}

	for (int i : v)
		cout << i;
	cout << '\n';
}
