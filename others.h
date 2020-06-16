#ifndef OTHERS_H
#define OTHERS_H

#include <math.h>

struct p {
    double x, y;
    p(double _x, double _y);
    p();
};

double dist(p& p1, p& p2);

double dist_from_line(p& A, p& B, p& C);

double dist_from_segment(p& A, p& B, p& C);

p move(p& A, p& B, double distance);

struct color {
        int r, g , b, a;
        color();
        color(int _r, int _g, int _b, int _a);
};

#endif
