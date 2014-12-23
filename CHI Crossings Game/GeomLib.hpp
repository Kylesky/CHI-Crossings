#pragma once

#include <vector>

double dist(double x, double y, double x2, double y2);
double dist2(double x, double y, double x2, double y2);
double ccw(double x, double y, double xa, double ya, double xb, double yb);
bool segmentIntersection(double* ans, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
bool pointInTriangle(double x, double y, double xa, double ya, double xb, double yb, double xc, double yc);
bool pointInRectangle(double x, double y, double xa, double ya, double xb, double yb);
bool pointInPolygon(double x, double y, int v, std::vector<double> xs, std::vector<double> ys);
bool isIntersecting_Circle_Circle(double x, double y, double r, double x2, double y2, double r2);
bool isIntersecting_Circle_Line(double x, double y, double r, double xa, double ya, double xb, double yb);
bool isIntersecting_Circle_Segment(double x, double y, double r, double xa, double ya, double xb, double yb);
bool isIntersecting_Circle_Rectangle(double x, double y, double r, double x2, double y2, double l, double w, double t);