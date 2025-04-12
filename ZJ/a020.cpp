#include <iostream>
using namespace std;

char c;
int x, sum, tbl[128];
string id = "__________ABCDEFGHJKLMNPQRSTUVXYWZIO";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> c >> x;

	for (int i = 10; i < id.size(); i++)
		tbl[id[i]] = i;

	sum += (tbl[c] % 10) * 9 + (tbl[c] / 10);
	for (int i = 0; i < 9; i++) {
		if (!i)
			sum += x % 10;
		else
			sum += (x % 10) * i;
		x /= 10;
	}

	if (sum % 10 == 0)
		cout << "real\n";
	else
		cout << "fake\n";
}
