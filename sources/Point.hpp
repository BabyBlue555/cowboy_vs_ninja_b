// #pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <iostream>
#include <cmath>
using namespace std;
namespace ariel{
    class Point{
        private:
            double _x;
            double _y;

        public:
            Point(double x_ptr,double y_ptr);
            double distance(Point point) const;
            std::string print() const;
            
            double getX() const;
            double getY() const;

            static Point moveTowards(Point src, Point dest, double distance){
                if(distance<0){
                    throw invalid_argument("distance cannot be negative!");
                }
                double src_dest_dist = src.distance(dest);
                if(src_dest_dist<=distance){
                    return dest;
                }

                double ratio = distance / src_dest_dist;

                // Calculate the new coordinates for the point within the desired range
                double newX = src._x + (dest._x-src._x) * ratio;
                double newY = src._y + (dest._y-src._y) * ratio;
                return Point(newX, newY);


            }

    // static Point moveTowards(Point src, Point dest, double dist){
    };
};

#endif

