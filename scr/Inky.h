#include "Blinky.h"
#include "Ghost.h"

class Inky : public Ghost {
    public:
    using Ghost::Ghost;
    private:
    void swapDirections() override;
};