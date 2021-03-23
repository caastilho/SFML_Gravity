#include <Bodies/body.hpp>
#include <iostream>


Body::Body(float x, float y, float _mass, float _radius, sf::Color color): mass(_mass), radius(_radius)
{
    
    shape.setPosition(sf::Vector2f(x - radius, y - radius));
    shape.setRadius(radius);
    shape.setPointCount(50);
    shape.setFillColor(color);
    
    velocityLine.setSize(sf::Vector2f(70, 1));
    velocityLine.setFillColor(sf::Color::Blue);
    velocityLine.setPosition(sf::Vector2f(x, y));

    accelerationLine.setSize(sf::Vector2f(50, 1));
    accelerationLine.setFillColor(sf::Color::Red);
    accelerationLine.setPosition(sf::Vector2f(x, y));
    
}


sf::Vector2f Body::getPosition()
{
    return shape.getPosition();
}

float Body::getMass()
{
    return mass;
}


void Body::update()
{
    
    velocity += acceleration;
    
    shape.move(velocity);
    velocityLine.move(velocity);
    accelerationLine.move(velocity);
    
    velocityLine.setRotation(getAngle(velocity));
    accelerationLine.setRotation(getAngle(acceleration));
    
}

void Body::display(sf::RenderWindow* renderer)
{
    
    renderer->draw(shape);
    renderer->draw(velocityLine);
    renderer->draw(accelerationLine);
    
}

void Body::calculateGravity(float g, std::vector<Body>& bodies)
{
    
    acceleration *= 0.0f;
    
    for (Body& body : bodies)
    {
        
        float distance = getDistance(body.getPosition(), shape.getPosition());
        
        if (this != &body && distance > radius)
        {
            float magnitude = (g * body.getMass()) / (distance * distance);
            sf::Vector2f direction = body.getPosition() - shape.getPosition();
            acceleration += setMagnitude(direction, magnitude);
        }
    }
    
}
