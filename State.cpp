#include "State.h"

State::State()
{
    if (!texture_background.loadFromFile("resources/background.png"))
        std::cout << "Failed to load resources/background.png\n";
    sprite_background.setTexture(texture_background);
}
