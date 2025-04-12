#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<string> words;

bool cmp(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	return a < b;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int start = 0, end = 26;
	string s;

	for (string i = "a"; i <= "z"; i[0]++)
		words.push_back(i);

	for (int i = 0; i < 4; i++) {
		for (int j = start; j < end; j++)
			for (char k = words[j][i] + 1; k <= 'z'; k++)
				words.push_back(words[j] + k);
		start = end;
		end = (int)words.size();
	}

	while (cin >> s) {
		auto iter = lower_bound(words.begin(), words.end(), s, cmp);

		if (*iter != s)
			cout << '0' << '\n';
		else
			cout << iter - words.begin() + 1 << '\n';
	}
}
