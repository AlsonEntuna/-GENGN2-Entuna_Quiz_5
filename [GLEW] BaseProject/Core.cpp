#include "Core.h"

void Core::init(){
    window.create(sf::VideoMode(800, 800), "The Game", sf::Style::Default, sf::ContextSettings(32));
    window.setPosition(sf::Vector2i(0,0));
    window.setVerticalSyncEnabled(true);

    //initialize GLEW
    GLenum status = glewInit();
    if(status != GLEW_OK)
        std::cout << "ERROR" << std::endl;

    timePerFrame = 1.0f/60.0f*1000.0f;
}

bool Core::isAlive(){
    return window.isOpen();
}

void Core::pollEvent()
{
    sf::Event event;
        while (window.pollEvent(event))
		{
            if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
			else if (event.type == sf::Event::Resized) glViewport(0, 0, event.size.width, event.size.height);
        }
}
void Core::clear(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Core::draw(){
    window.display();
    sf::sleep(sf::milliseconds(timePerFrame-
        clock.getElapsedTime().asMilliseconds()));
    clock.restart();
}

bool Core::isCollision(Object& objA, Object& objB){
    return ((objA.getX()+objA.getWidth() >= objB.getX() && objA.getX() <= objB.getX()+objB.getWidth()) &&
        (objA.getY()+objA.getHeight() >= objB.getY() && objA.getY() <= objB.getY()+objB.getHeight()));
}
