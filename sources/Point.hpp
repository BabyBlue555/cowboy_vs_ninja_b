#pragma once

#include <string>

namespace ariel
{
    };

class Point{
    private:
        double _x,_y;

    public:
        Point(double x_ptr,double y_ptr);
        double distance(Point point) const;
        std::string print() const;
        static Point moveTowards(Point &, Point &, double);
        double getX() const;
        double getY() const;

// static Point moveTowards(Point src, Point dest, double dist){
};



// }

