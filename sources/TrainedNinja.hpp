#pragma once
#include "Ninja.hpp"

namespace ariel{
    class TrainedNinja: public Ninja{
        public:
            TrainedNinja(const std::string name, const Point location);
    };
}
