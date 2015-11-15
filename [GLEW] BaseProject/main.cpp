/*
Linux compile

g++ Camera.cpp Mesh.cpp ModelTransform.cpp Shader.cpp Core.cpp Helper.cpp main.cpp VectorPhysics.cpp Object.cpp Player.cpp SolidBlock.cpp WindBlock.cpp GoalBlock.cpp LifeBlock.cpp DangerBlock.cpp -o run.exe -lGL -lGLEW -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network && ./run.exe

Windows compile

g++ Camera.cpp Mesh.cpp ModelTransform.cpp Shader.cpp Core.cpp Helper.cpp main.cpp VectorPhysics.cpp Object.cpp Player.cpp SolidBlock.cpp WindBlock.cpp GoalBlock.cpp LifeBlock.cpp DangerBlock.cpp -o run.exe -IC:/glew/include -LC:/glew/lib -IC:/sfml/include -LC:/sfml/lib -IC:/glm -lsfml-window -lsfml-graphics -lsfml-system  -lsfml-network -lglew32 -lopengl32 -lglu32 && run.exe

Things to be checked
1pt  - Vector addition & subtractionin VectorPhysics class
2pts - Player movement to the left or right using vectors. The player will move at a constant vector
       of 0.1f to the left or right only while the player is holding the specific keys.
2pts - Player Jump and landing using vectors. Jump will give a sudden change in the y vector of 0.25f
       and only happens once.
1pt  - Give the wind block a vector of -0.03f
1pt  - Create a gravity vector which pulls the player down by -0.01f
1pt  - addition of Gravity & Wind using vector addition in main
*/
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include "SolidBlock.h"
#include "WindBlock.h"
#include "GoalBlock.h"
#include "LifeBlock.h"
#include "DangerBlock.h"
#include "Player.h"
#include "Core.h"
#include "Helper.h"
#include "Camera.h"

int main(){
    Core core;
    core.init();
    Helper helper;
    Player player(-3,2);
    SolidBlock platform1(0,-2,8,1);
    SolidBlock platform2(-1,-1,6,1);
    SolidBlock platform3(-2, 0,4,1);
    WindBlock wind(-2,2,4,4);
    GoalBlock goal(3.5f,-0.5f,1,2);
    DangerBlock danger1(2.5f,-1,1,1);
    DangerBlock danger2(0.5f, 0,1,1);
    LifeBlock life1(-2,-3.5f,1,1);
    LifeBlock life2( 0,-3.5f,1,1);
    LifeBlock life3( 2,-3.5f,1,1);
    Camera camera(glm::vec3(0,0,3),70.0f, 400.0f/300.0f,0.01f,100.0f);
    int life = 3;

    bool hasShot = false;

    while(core.isAlive())
	{
        core.pollEvent();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
            player.jump();
            player.setFloating(false);
        }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.moveLeft();
			player.setFloating(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.moveRight();
			player.setFloating(false);
		}
		else
            player.haltHorizontal();

		// Check Winblock Collision
		if (player.isColliding(wind))
		{
			VectorPhysics windBlockVector;
			windBlockVector.setXVec(-0.03f);

			// Apply vector to player
			player.getVector()->addVector(windBlockVector);
		}

        player.update();

        helper.platformCollide(player, platform1);
        helper.platformCollide(player, platform2);
        helper.platformCollide(player, platform3);

        helper.damageChecks(player,danger1,danger2,life);
        helper.winChecks(player,goal,life);

        // clear the buffers
        core.clear();

        if(life>0)life1.draw(camera);
        if(life>1)life2.draw(camera);
        if(life>2)life3.draw(camera);

        danger1.draw(camera);
        danger2.draw(camera);

        wind.draw(camera);
        platform1.draw(camera);
        platform2.draw(camera);
        platform3.draw(camera);
        goal.draw(camera);
        player.draw(camera);
        
        core.draw();
    }
    return 0;
}//end func
