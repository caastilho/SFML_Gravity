#pragma once
#include <SFML/Graphics.hpp>
#include <Math/vector.hpp>
#include <vector>


class Body
{  
    
    private:
        sf::RectangleShape velocityLine;
        sf::RectangleShape accelerationLine;
        sf::CircleShape shape;
        
        sf::Vector2f velocity, acceleration;
        float radius;
        float mass;
    
    
    public:
        Body() {};
        Body(float x, float y, float _mass, float _radius, sf::Color color);
        
        sf::Vector2f getPosition();
        float getMass();
        
        void update();
        void display(sf::RenderWindow* renderer);
        void calculateGravity(float g, std::vector<Body>& bodies);
        
};
