#include "others.h"

p::p(double _x, double _y) {
    x = _x;
    y = _y;
}

p::p() {}

double dist(p& p1, p& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt( dx*dx + dy*dy );
}

double dist_from_line(p& A, p& B, p& C){
    //AB - line segment 
    //C - a point which dist from AB is to be measured
    double a,b,c;
    a = (A.y - B.y) / (A.x - B.x);
    b = -1;
    c = A.y - a * A.x;
    return fabs(a * C.x + b *C.y + c) / sqrt(a*a + b*b);
}

double dist_from_segment(p& A, p& B, p& C) {
    //AB - line segment 
    //C - a point which dist from AB is to be measured

    double AC = dist(A,C);
    double BC = dist(B,C);
    double AB = dist(A,B);

    if(AC*AC < BC*BC + AB*AB && BC*BC < AC*AC + AB*AB) {
        return dist_from_line(A,B,C);
    }
    return fmin(dist(A,C), dist(B,C));
}

p move(p& A, p& B, double distance) {
    double wA; //wage
    wA = 1 - distance/dist(A, B);
    return p( A.x * wA + B.x * (1 - wA), A.y * wA + B.y * (1 - wA));
}

color::color (int _r, int _g, int _b, int _a) {
    r = _r; g = _g; b = _b; a = _a;
}
color::color() {}









