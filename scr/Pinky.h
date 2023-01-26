#pragma once
#include "Ghost.h"
#include "Context.h"

class Pinky : public Ghost {
    public:
    using Ghost::Ghost;
    void assignCompanion(Ghost* ghost);
    private:
    Ghost* companion;
    void swapDirections() override;
};