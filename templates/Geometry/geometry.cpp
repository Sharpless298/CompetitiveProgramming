template <typename T>
struct Point {
	T x, y;

	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}
	Point operator +(Point p) { return Point(x+p.x, y+p.y); }
	Point operator -(Point p) { return Point(x-p.x, y-p.y); }
	Point operator *(int c) { return Point(x*c, y*c); }
	Point operator /(int c) { return Point(x/c, y/c); }
	T dot(Point p) { return x*p.x + y*p.y; }
	T cross(Point p) { return x*p.y - y*p.x; }
};
