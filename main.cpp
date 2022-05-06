#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

    sf::Texture texture_grass;
    if (!texture_grass.loadFromFile("grass.png")) {return 1;}

    sf::Texture texture_wall;
    if(!texture_wall.loadFromFile("wall.png")) {return 1;}

    sf::Texture texture_guy;
    if(!texture_guy.loadFromFile("guy.png")) {return 1;}

    //Grass Background
    texture_grass.setRepeated(true);
    sf::Sprite grass;
    grass.setTexture(texture_grass);
    grass.setTextureRect(sf::IntRect(0, 0, 800,800));

    // Walls
    texture_wall.setRepeated(true);
    sf::Sprite wall;
    wall.setTexture(texture_wall);

    std::vector<sf::Sprite> walls;

    // Left wall
    wall.setTextureRect(sf::IntRect(0, 0, 50, window.getSize().y - 125));
    wall.setPosition(0.0, 125.0); // Starting position
    walls.emplace_back(wall);
    // Top wall
    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50));
    wall.setPosition(0.0, 0.0);
    walls.emplace_back(wall);
    // Right wall
    wall.setTextureRect(sf::IntRect(0, 0, 50, window.getSize().y - 125));
    wall.setPosition(window.getSize().x - 50, 0.0);
    walls.emplace_back(wall);
    // Bottom wall
    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50));
    wall.setPosition(0.0, window.getSize().y - 50);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 50, 200));
    wall.setPosition(300.0, 400.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 200, 50));
    wall.setPosition(200.0, 200.0);
    walls.emplace_back(wall);

    // Characte
    sf::Sprite guy;
    guy.setTexture(texture_guy);
    guy.setPosition(0.0, 50.0);

    // Start clock
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();



        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.draw(grass);
        for(auto &wall : walls)
        {
            window.draw(wall);
        }
        window.draw(guy);
        window.display();
    }

    return 0;
}
