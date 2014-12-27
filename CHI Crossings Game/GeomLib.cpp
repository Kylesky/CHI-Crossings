#include "GeomLib.hpp"

#define PI 3.14159265359
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

double dist(double x, double y, double x2, double y2){
	return sqrt(dist2(x, y, x2, y2));
}

double dist2(double x, double y, double x2, double y2){
	return (x-x2)*(x-x2) + (y-y2)*(y-y2);
}

double ccw(double x, double y, double xa, double ya, double xb, double yb){
	double dxa = xa-x;
	double dya = ya-y;
	double dxb = xb-x;
	double dyb = yb-y;
	return dxa*dyb-dya*dxb;
}

bool segmentIntersection(double* ans, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
	double A1 = y2-y1;
	double B1 = x1-x2;
	double C1 = y2*x1-x2*y1;
	double A2 = y4-y3;
	double B2 = x3-x4;
	double C2 = y4*x3-x4*y3;
	double det = A1*B2 - A2*B1;
    if(abs(det) <= 1e-7){
		return false;
    }else{
		ans[0] = (B2*C1 - B1*C2)/det;
		ans[1] = (A1*C2 - A2*C1)/det;
		return std::min(x1, x2) <= ans[0] && ans[0] <= std::max(x1, x2) &&
				std::min(y1, y2) <= ans[1] && ans[1] <= std::max(y1, y2) &&
				std::min(x3, x4) <= ans[0] && ans[0] <= std::max(x3, x4) &&
				std::min(y3, y4) <= ans[1] && ans[1] <= std::max(y3, y4) ;
    }
}

bool pointInTriangle(double x, double y, double xa, double ya, double xb, double yb, double xc, double yc){
	std::vector<double> xs;
	xs.push_back(xa); xs.push_back(xb); xs.push_back(xc);
	std::vector<double> ys;
	ys.push_back(ya); ys.push_back(yb); ys.push_back(yc);
	return pointInPolygon(x, y, 3, xs, ys);
}

bool pointInRectangle(double x, double y, double xa, double ya, double xb, double yb){
	return std::min(xa, xb) <= x && x <= std::max(xa, xb) &&
		   std::min(ya, yb) <= y && y <= std::max(ya, yb);
}

bool pointInPolygon(double x, double y, int v, std::vector<double> xs, std::vector<double> ys){
	bool less = true;
	bool great = true;

	for(int i=0; i<v && less && great; i++){
		double t = ccw(xs[i], ys[i], xs[(i+1)%v], ys[(i+1)%v], x, y);
		less &= t<0;
		great &= t>0;
	}

	return less || great;
}

bool isIntersecting_Circle_Circle(double x, double y, double r, double x2, double y2, double r2){
	return dist2(x, y, x2, y2) <= (r+r2)*(r+r2);
}
	
bool isIntersecting_Circle_Line(double x, double y, double r, double xa, double ya, double xb, double yb){
	double proj = abs(xa*x + ya*y)/dist(xa, ya, xb, yb);
	return proj <= r;
}
	
bool isIntersecting_Circle_Segment(double x, double y, double r, double xa, double ya, double xb, double yb){
	double d = dist(xa, ya, xb, yb);
	double proj = abs(xa*x + ya*y)/d;
	double intx = xa+proj*(xb-xa)/d;
	double inty = ya+proj*(yb-ya)/d;
	if( std::min(xa, xb) <= intx && intx <= std::max(xa, xb) ){
		return proj <= r;
	}else{
		return (dist(x, y, xa, ya) <= r) || (dist(x, y, xb, yb) <= r);
	}
}

bool isIntersecting_Circle_Rectangle(double x, double y, double r, double x2, double y2, double l, double w, double t){
	t = t*PI/180;
	double ang = atan(w/l);
	double d = sqrt(l*l/4+w*w/4);
	double xa = x2+d*cos(ang+t);
	double ya = y2+d*sin(ang+t);
	double xb = x2+d*cos(ang-t);
	double yb = y2+d*sin(ang-t);
	double xc = x2-d*cos(ang+t);
	double yc = y2-d*sin(ang+t);
	double xd = x2-d*cos(ang-t);
	double yd = y2-d*sin(ang-t);
	std::vector<double> xs; xs.push_back(xa); xs.push_back(xb); xs.push_back(xc); xs.push_back(xd);
	std::vector<double> ys; ys.push_back(ya); ys.push_back(yb); ys.push_back(yc); ys.push_back(yd);
	return isIntersecting_Circle_Segment(x, y, r, xa, ya, xb, yb)
	|| isIntersecting_Circle_Segment(x, y, r, xb, yb, xc, yc)
	|| isIntersecting_Circle_Segment(x, y, r, xc, yc, xd, yd)
	|| isIntersecting_Circle_Segment(x, y, r, xd, yd, xa, ya)
	|| pointInPolygon(x, y, 4, xs, ys);
}

double signum(double n){
	if(n < -1e-7){
		return -1.0;
	}else if(n > 1e-7){
		return 1.0;
	}else{
		return 0;
	}
}