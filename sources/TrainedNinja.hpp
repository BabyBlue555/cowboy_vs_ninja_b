#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include "Ninja.hpp"

namespace ariel{
    
    class TrainedNinja: public Ninja{
        public:
            TrainedNinja(std::string name,Point location);
            // ~TrainedNinja()=default;
    };
};
#endif

