#include <map>
#include <string>
#include <tuple>
#include <vector>
#include "skillUnlock.h"

using namespace std;

// Skills are stored in a map (global object)
vector<Skill> skills = {
    {"InstantKill", 0, 1, 0, 0},
    {"Teleportation", 0, 2, 0, 0},
    {"Fireball", 60, 2, 0, 0},
    {"Lightning", 80, 2, 0, 0}
};

// {skill_name, skill_damage, skill_cooldown, skill_remaining_cooldown, skill_unlocked_locked_status}
// 0 - locked, 1 - unlocked

void skillUnlock(const string& new_skill) {
    for (auto& skill : skills) {
        if (skill.SkillName == new_skill) {
            skill.SkillUnlocked = 1; // Unlock the skill
            break; // Exit after unlocking the skill
        }
    }
}
