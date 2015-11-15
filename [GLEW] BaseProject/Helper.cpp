#include "Helper.h"

Helper::Helper()
{
}

void Helper::platformCollide(Player &player,SolidBlock &platform)
{
    if(platform.isColliding(player))
	{
        player.setY(platform.getY()+platform.getHeight()/2+player.getHeight()/2);
        player.setFloating(true);
        player.land();
    }
}

void Helper::damageChecks(Player &player,DangerBlock &danger1,DangerBlock &danger2,int &life)
{
    if(player.getY() <- 10)
	{
        player.setX(-3);
        player.setY( 2);
        life--;
   }
   if(danger1.isColliding(player) || danger2.isColliding(player))
   {
        player.setX(-3);
        player.setY( 2);
        life--;
    }
}

void Helper::winChecks(Player &player,GoalBlock &goal,int &life)
{
    if(goal.isColliding(player))
	{
        player.setX(-3);
        player.setY( 2);
        life = 3;
    }
}

