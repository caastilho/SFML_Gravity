#include <Scenes/mainScene.hpp>


// Setup scene environment
void MainScene::setup(sf::RenderWindow* _renderer, AssetsManager manager)
{
    
    renderer = _renderer;
    sf::Vector2u size = renderer->getSize();
    
    view.setCenter(0, 0);
    view.setSize(size.x, size.y);
    renderer->setView(view);
    
    bodies.push_back(Body(-400,  100, 150, 20, sf::Color(250, 250, 250)));
    bodies.push_back(Body( 200,  100, 150, 20, sf::Color(250, 250, 250)));
    bodies.push_back(Body(   0, -200, 150, 20, sf::Color(250, 250, 250)));
    
}

// Run scene environment
void MainScene::run(bool isFocused)
{
    
    // Clear renderer buffer content
    renderer->clear(sf::Color::Black);
    
    for (Body& body : bodies)
    {
        body.calculateGravity(10, bodies);
        body.update();
        body.display(renderer);
    }

}

// Run scene event handler
void MainScene::events(sf::Event& action)
{
    
}
