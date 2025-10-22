#include <bits/stdc++.h>
#define ent '\n'
#define int long long

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

const int maxn = 1'000'000 + 12;

int a[maxn];
int n, k;

int get(vector<int> a) {
    if(a.empty()) return 0;

    int pos = (int)a.size() / 2, val = 0;
    for(int i = 0; i < a.size(); i++) {
        val += abs(a[pos] - a[i]) - abs(pos - i);
    }

    return val;
}

void solve() {
    cin >> n;
    vector<int> a, b;
    for(int i = 1; i <= n; i++) {
        char c;
        cin >> c;

        if(c == 'a') {
            a.push_back(i);
        }
        else b.push_back(i);
    }

    cout << min(get(a), get(b)) << ent;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int t;
	cin >> t;
    while(t--) {
        solve();
    }
}
