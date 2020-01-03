#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "math_vector.h"
using std::string; using std::ostringstream;

MathVector MathVector::add(const MathVector&vec){
    //MathVector Answer = (x+vec.x, y+vec.y);
    return (MathVector(x+vec.x, y+vec.y));
}

MathVector MathVector::mult(long scalar){
    //MathVector Answer = (x*lo.x,y*lo.y);
    return(MathVector(x*scalar, y*scalar));
}

long MathVector::mult(const MathVector&vector){
    y*=vector.y;
    x*=vector.x;
    return x+y;
}

double MathVector::magnitude(){
    //double Answer = sqrt((y*y)+(x*x));
    return (sqrt((y*y)+(x*x)));
}

string vec_to_str(const MathVector&vector){
    ostringstream ss;
    ss << vector.x << ':' << vector.y;
    return ss.str();
}