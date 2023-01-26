#pragma once
#include "Context.h"
#include "Ghost.h"

class Clyde : public Ghost {
    public:
    using Ghost::Ghost;
    private:
    void swapDirections() override;
};