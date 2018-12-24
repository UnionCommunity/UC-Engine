#include "Transform.h"

using namespace eng;

Transform::Transform(sf::Vector2f position) : position(position), angle(0) {}

Transform::Transform(sf::Vector2f position, float angle) : position(position), angle(angle) {}