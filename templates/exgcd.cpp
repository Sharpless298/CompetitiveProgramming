pair<int, int> exgcd(int a, int b) {
	if (b == 0)
		return make_pair(1, 0);
	pair<int, int> res = exgcd(b, a % b);
	return make_pair(res.second, res.first - a / b * res.second);
}
