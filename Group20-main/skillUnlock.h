#ifndef SKILLUNLOCK
#define SKILLUNLOCK


#include <tuple>
#include <map>
#include <string>
using namespace std;


struct Skill {
    string SkillName;         
    int SkillDamage;               
    int SkillCooldown;             
    int SkillRemainingCooldown;     
    int SkillUnlocked;            
};


void skillUnlock (const string& new_skill);


extern vector<Skill> skills;

#endif
