#ifndef HELPER_H
#define	HELPER_H

#include "SolidBlock.h"
#include "DangerBlock.h"
#include "GoalBlock.h"
#include "Player.h"

class Helper
{
    public:
        Helper();
        void platformCollide(Player &player,SolidBlock &platform);
        void damageChecks(Player &player,DangerBlock &danger1,DangerBlock &danger2,int &life);
        void winChecks(Player &player,GoalBlock &goal,int &life);
};
#endif /* HELPER_H */
