#pragma once
#include <SFML/Graphics.hpp>
#include <Graphics/assetsManager.hpp>
#include <vector>

#include <Bodies/body.hpp>


class MainScene
{

    private:
        
        // Scene view
        sf::View view;
        
        // Renderer object (Buffer content manipulator)
        sf::RenderWindow* renderer;
        
        // Array of bodies
        std::vector<Body> bodies;

    
    public:
        
        // Default scene constructor
        MainScene() {};
        
        
        // Scene default methods
        void setup(sf::RenderWindow* _renderer, AssetsManager manager);
        void run(bool isFocused);
        void events(sf::Event& action);
        
};
