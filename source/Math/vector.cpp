#include <Math/vector.hpp>


// Get distance between two vectors
float getDistance(sf::Vector2f a, sf::Vector2f b)
{
    return getMagnitude(a - b);
}

// Get magnitude from a vector
float getMagnitude(sf::Vector2f source)
{
    return sqrt(pow(source.x, 2) + pow(source.y, 2));
}

// Get vector angle representation
float getAngle(sf::Vector2f source)
{
    return atan2(source.y, source.x) * 180 / 3.14159265;
}

// Set vector's magnitude
sf::Vector2f setMagnitude(sf::Vector2f source, float newMagnitude)
{
    float magnitude = getMagnitude(source);
    float x = source.x * (newMagnitude / magnitude);
    float y = source.y * (newMagnitude / magnitude); 
    
    return sf::Vector2f(x, y);
}

// Normalize vector
sf::Vector2f normalize(sf::Vector2f source)
{
    float magnitude = getMagnitude(source);
    return source / magnitude;
}

// Constrain vector
sf::Vector2f constrain(sf::Vector2f source, float maximum)
{
    return sf::Vector2f(std::min(source.x, maximum), std::min(source.y, maximum));
}
