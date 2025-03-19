#include <iostream>
#include "pointCol.h"

using namespace std;

void pointCol(Player &player, int awarded_pts) {
    player.playerExp += awarded_pts;
}
