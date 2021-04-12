#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>


// Get distance between two vectors
float getDistance(sf::Vector2f a, sf::Vector2f b);

// Get magnitude from a vector
float getMagnitude(sf::Vector2f source);

// Get vector angle representation
float getAngle(sf::Vector2f source);

// Set vector's magnitude
sf::Vector2f setMagnitude(sf::Vector2f source, float newMagnitude);

// Normalize vector
sf::Vector2f normalize(sf::Vector2f source);

// Constrain vector
sf::Vector2f constrain(sf::Vector2f source, float maximum);
