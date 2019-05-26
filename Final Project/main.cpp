#include "tgaimage.h"
#include <vector>
using namespace std;

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);


class Point {
	int x, y;

public:
	Point() {};

	Point(int x_, int y_) {
		x = x_;
		y = y_;
	}

	void Set(int x_, int y_) {
		x = x_;
		y = y_;
	}

	int Get_x() {
		return x;
	}

	int Get_y() {
		return y;
	}

	~Point() {};
};


class Figure {
	vector <Point> points;
	double ro = 1;

public:
	Figure(int n) {
		Point now;
		int x, y;

		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			now.Set(x, y);
			points.push_back(now);
		}
	}

	~Figure() {};

	void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
	    bool steep = false;
	    if (std::abs(x0-x1)<std::abs(y0-y1)) { // if the line is steep, we transpose the image
		std::swap(x0, y0);
		std::swap(x1, y1);
		steep = true;
	    }
	    if (x0>x1) { // make it left-to-right
		std::swap(x0, x1);
		std::swap(y0, y1);
	    }

	    for (int x=x0; x<=x1; x++) {
		float t = (x-x0)/(float)(x1-x0);
		int y = y0*(1.-t) + y1*t;
		if (steep) {
		    image.set(y, x, color); // if transposed, de-transpose
		} else {
		    image.set(x, y, color);
		}
	    }
	}

	void draw(){
	TGAImage image(100, 100, TGAImage::RGB);
        image.set(52, 41, red);
        image.flip_vertically();
        
	for (int i = 0; i < points.size() - 1; i++){
		line(points[i].Get_x(), points[i].Get_y(), points[i+1].Get_x(), points[i+1].Get_y(), image, red);
	}

	image.write_tga_file("output.tga");
	}

	double Squre(Point p1, Point p2, Point p3) {
		double ans;
		ans = 0.5 * abs((p2.Get_x() - p1.Get_x()) * (p3.Get_y() - p1.Get_y()) - (p3.Get_x() - p1.Get_x()) * (p2.Get_y() - p1.Get_y()));
		return ans;
	}

	Point Find_Center(Point p1, Point p2, Point p3) {
		Point ans((p1.Get_x() + p2.Get_x() + p3.Get_x()) / 3, (p1.Get_y() + p2.Get_y() + p3.Get_y()) / 3);
		return ans;
	};

	double Dist_2(Point p1, Point p2) {
		double ans;
		ans = (p1.Get_x() - p2.Get_x()) * (p1.Get_x() - p2.Get_x()) + (p1.Get_y() - p2.Get_y()) * (p1.Get_y() - p2.Get_y());
		return ans;
	}

	double Gravity(Point p, double m) {
		double ans = 0;
		for (int i = 0; i < points.size() - 2; i++) {
			if (Dist_2(p, Find_Center(points[i], points[i + 1], points[i + 2])) != 0) {
				ans += Squre(points[i], points[i + 1], points[i + 2]) * ro * m / Dist_2(p, Find_Center(points[i], points[i + 1], points[i + 2]));
			}
		}
		return ans;
	}
};

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	Figure f(n);

	int x, y;
	scanf("%d%d", &x, &y);
	Point p1(x, y);


	int m;
	scanf("%d", &m);

	printf("%d", f.Gravity(p1, m) );

	f.draw();
	return 0;
}
