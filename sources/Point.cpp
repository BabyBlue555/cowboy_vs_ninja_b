#include "Point.hpp"

using namespace std;
namespace ariel{

    Point::Point(double x_ptr,double y_ptr): _x(x_ptr),_y(y_ptr){

    }

    double Point::distance(Point point) const{

        double dx =point.getX() - this->_x; // Calculate the difference in x-coordinates
        double dy =point.getY() - this->_y ; // Calculate the difference in y-coordinates
        return sqrt(dx*dx + dy*dy );
    }

    string Point::print() const
    {
        return "(" + to_string(_x)  + ", " + to_string(_y) + ")";
    }

    double Point::getX() const
    {
        return _x;
    }

    double Point::getY() const
    {
        return _y;
    } 
}; 