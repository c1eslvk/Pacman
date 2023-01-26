#pragma once
#include "Context.h"
#include "Ghost.h"

class Blinky : public Ghost {
    public:
    using Ghost::Ghost;
    private:
    void swapDirections() override;
};