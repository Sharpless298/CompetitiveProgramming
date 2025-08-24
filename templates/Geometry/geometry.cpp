template <typename T>
struct TPoint {
	T x, y;
	int id;

	TPoint() : x(0), y(0), id(-1) {}
	TPoint(T _x, T _y) : x(_x), y(_y), id(-1) {}
	TPoint(T _x, T _y, int _id) : x(_x), y(_y), id(_id) {}

	inline TPoint operator+(const TPoint &rhs) {
		return TPoint(x + rhs.x, y + rhs.y);
	}
	inline TPoint operator-(const TPoint &rhs) {
		return TPoint(x - rhs.x, y - rhs.y);
	}
	inline TPoint operator*(const T &k) {
		return TPoint(x * k, y * k);
	}
	inline TPoint operator/(const T &k) {
		return TPoint(x / k, y / k);
	}
	inline bool operator<(const TPoint &p) {
		return (x < p.x || (x == p.x && y < p.y));
	}
	inline bool operator==(const TPoint &p) {
		return x == p.x && y == p.y;
	}
	friend T dot(const TPoint &p, const TPoint &q) {
		return p.x * q.x + p.y * q.y;
	}
	friend T cross(const TPoint &p, const TPoint &q) {
		return p.x * q.y - p.y * q.x;
	}
};
using Point = TPoint<long long>;
using Point = TPoint<double>;

vector<Point> convex_hull(vector<Point> &pnts) {
	sort(pnts.begin(), pnts.end());
	// pnts.resize(unique(pnts.begin(), pnts.end()) - pnts.begin());
	// if(pnts.size() < 3) return pnts;

	vector<Point> hull;
	for (Point pnt : pnts) {
		while (hull.size() >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0) {
			hull.pop_back();
		}
		hull.push_back(pnt);
	}
	hull.pop_back();

	reverse(pnts.begin(), pnts.end());
	int t = (int)hull.size();
	for (Point pnt : pnts) {
		while (hull.size() - t >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0) {
			hull.pop_back();
		}
		hull.push_back(pnt);
	}
	hull.pop_back();

	return hull;
}
