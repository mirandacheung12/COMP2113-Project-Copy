#include <string>
#include <iostream>
using namespace std;

void drawEnemy(string enemyName) {
	//stage 1: low level
	if (enemyName == "Rat King" || enemyName == "Graffiti Goblin" || 
    	enemyName == "Hobo Warlord"  || enemyName == "Metro Mummy" ||  
   	enemyName == "Vagrant Vampire" || enemyName == "Subway Shaman" || 
    	enemyName == "Tunnel Troll") {
				cout << "++++++++++++++^+++++++++++++++++" << endl;
				cout << "+++++++++___/====\\O_____++++++++" << endl; 
				cout << "++++++++++\\(=v==v=)===/+++++++++" << endl; 
				cout << "+++++v=v++++\\======\\+++v=v++++++" << endl; 
				cout << "++++++++\\\\+++\\======\\++++\\\\+++++" << endl; 
				cout << "********************************" << endl; 
	} else if (enemyName == "Pigeon Sorcerer") {
      				cout << "++++++++++++++^+++++++++++++++++" << endl;
				cout << "+++++++++++/=====\\+++++++---++++" << endl; 
				cout << "++++++++++/=======\\+++++--*--+++" << endl; 
				cout << "+++++++++(=======O==>+++-/--++++" << endl; 
				cout << "+++++++++|========/+++++/+++++++" << endl; 
				cout << "********************************" << endl; 
	} else if (enemyName == "Sewer Snake") {
				cout << "+++++++++++______+++++++++++++++" << endl; 
				cout << "+++++++++/=========\\++++++++++++" << endl; 
				cout << "++++++++[===0=======|+++++++++++" << endl; 
				cout << "++++++++++|+++|=====|+++++++++++" << endl; 
				cout << "++++++++++^+++|=====|+++++++++++" << endl;
				cout << "********************************" << endl; 
	}
    
    	//stage 1: mid level
	if (enemyName == "Mutant Alligator" || enemyName == "Subway Stalker" || 
    	enemyName == "Demon of the Underground"  || enemyName == "Lurker in the Shadows") {
				cout << "++++++++^++^++++++++++++++++++++" << endl;
				cout << "++++++++\\====\\\\++/++++++++++++++" << endl;
				cout << "+++++++++>====>>\\O++++++++++++++" << endl; 
				cout << "++++++++/====//===\\+++++++++++++" << endl; 
				cout << "++++++++\\==//=======\\+++++++++++" << endl; 
				cout << "********************************" << endl; 
	} else if (enemyName == "Underground Wraith" || enemyName == "Banshee of the Tunnels" || 
    	enemyName == "Phantom Conductor" || enemyName == "Sewer Beastmaster" || 
	enemyName == "Cyborg Enforcer" || enemyName == "Graffiti Golem") {
      				cout << "++++++++++++++^+++++++++++++++++" << endl;
				cout << "+++++++++++/=====\\+++++++---++++" << endl; 
				cout << "++++++++++/====\\==\\++/++--*--+++" << endl; 
				cout << "+++++++++(=====[]=<>[]++-/--++++" << endl; 
				cout << "+++++++++|========/+++++/+++++++" << endl; 
				cout << "********************************" << endl; 
	}

    	//stage 1: high level
	if (enemyName == "Cthulu's Ratspawn" || enemyName == "The Overlord of the Underground" || 
    	enemyName == "King of the Sewers" || enemyName == "Nightmare beneath the Tracks" || 
	enemyName == "Eldritch Horror of the Tunnels") {
      				cout << "+++++++++++\\++^+++/+++++++++++++" << endl;
				cout << "++++++++_{|}/====\\{|}___++++++++" << endl; 
				cout << "+++++++++\\=(=v==v=)===/+++++++++" << endl; 
				cout << "+++++v=v++++\\======\\+++v=v++++++" << endl; 
				cout << "++++++++\\\\+++\\======\\++++\\\\+++++" << endl; 
				cout << "********************************" << endl; 
	} else if (enemyName == "Metro Leviathan" || enemyName == "Dreaded Subway Demon" || 
    	enemyName == "Apocalypse Subterran" || enemyName == "The Abyssal Conductor" || 
	enemyName == "The Dark Railmaster") {
      				cout << "+++++++++++^__^__^++++++++++++++" << endl; 
				cout << "++++++++</=========\\>+++++++++++" << endl; 
				cout << "++++++{|[=={|}======|>++++++++++" << endl; 
				cout << "++++++++++|+++|=====|>++++++++++" << endl; 
				cout << "++++++++++^+++|=====|>++++++++++" << endl;
				cout << "********************************" << endl; 
	}
	

		
	//stage 2: low level
	if (enemyName == "Mummy Guardian" || enemyName == "Pyramid Phantom" || 
    	enemyName == "Sand Wraith" || enemyName == "Scarab Swarm") {
				cout << "++++---+++++--++++--++++++--++++" << endl; 
				cout << "++++++---++----++---++++-+++++++" << endl; 
				cout << "+++++--++++-O----O--++++--++++++" << endl; 
				cout << "--+++----+++--<>--+++++---++++--" << endl; 
				cout << "+--+++--++++-----++++++----++--+" << endl; 
				cout << "********************************" << endl;
	} else if (enemyName == "Sphinx Specter" || enemyName == "Cursed Pharaoh" || 
    	enemyName == "Anubis' Minion" || enemyName == "Hieroglyphic Horror") {
				cout << "+++++++++++++__^_____^++++++++++" << endl;
				cout << "+++++++++{|/----{|}---}+++++++++" << endl;
				cout << "+++++++[vv-------------}++++++++" << endl;
				cout << "++++++++[^-------------\\++++++++" << endl;
				cout << "++++++++++++\\-----------\\+++++++" << endl;
				cout << "********************************" << endl;
	} else if (enemyName == "Desert Bandit" || enemyName == "Tomb Raider") {
				cout << "+++++^++++++++++^+++++++++++++++" << endl;
				cout << "++++|==\\+++++++|==\\+++++++++++++" << endl; 
				cout << "++++|==============|++++++++++++" << endl; 
				cout << "++++{====O=======O==\\+++++++++++" << endl; 
				cout << "+++++|========V=V==|++++++++++++" << endl; 
				cout << "********************************" << endl; 
	}

	//stage 2: mid level
	if (enemyName == "Pyramid Sentinel" || enemyName == "Pharaoh's Curse" || 
    	enemyName == "Treasure Guardian" || enemyName == "Giant Scorpion" ||
	enemyName == "Sphyinx Guardian") {
				cout << "+++++++++__/_^___^+++++++_/-/+--" << endl;
				cout << "+++++++/--{|}-----}++++/=++/=++-" << endl;
				cout << "+++[vv-------------}+++++++++++-" << endl;
				cout << "++++V--V|----------\\++++++++++/-" << endl;
				cout << "+++++[U/+\\----------\\++++++/--/+" << endl;
				cout << "********************************" << endl;
	} else if (enemyName == "Egyptian Sorcerer" || enemyName == "Cursed Tomb Raider" || 
    	enemyName == "Undead Mummified King" || enemyName == "Sandstorm Djinn" ||
	enemyName == "Desert Djinn") {
				cout << "+++++^++++++++++^+++++++++++++++" << endl;
				cout << "++++|--\\+++++++|--\\+++++++++++++" << endl; 
				cout << "++++|--------------|++++++++++++" << endl; 
				cout << "++++{----{}-----{}--\\+++++++++++" << endl; 
				cout << "+++++|--------V-V--|++++++++++++" << endl; 
				cout << "********************************" << endl; 
	}

	//stage 2: high level
	if (enemyName == "Anubis, God of the Dead" || enemyName == "Pharaoh of the Abyss" || 
    	enemyName == "Cursed Mummy King" || enemyName == "The Great Sphinx" ||
	enemyName == "The Wrath of Ra") {
				cout << "+++++++++\\++__/_^___^+++++++++++" << endl;
				cout << "++++++++{|/--{|}-----}++++++++++" << endl;
				cout << "+++++++[vv---------//--}++++++++" << endl;
				cout << "++++++++V--V|----/-/---\\++++++++" << endl;
				cout << "+++++++++[U/+\\-/-/------\\+++++++" << endl;
				cout << "********************************" << endl;
	} else if (enemyName == "Sand Leviathan" || enemyName == "The Serpent of Chaos" || 
    	enemyName == "The Ancient Curse" || enemyName == "The Eternal Guardian" ||
	enemyName == "Ruler of the Desert Tombs") {
				cout << "+++++++++\\++++/+++++++++++++++++" << endl;
				cout << "+++++++++0____0++++++++++++++++=" << endl;
				cout << "++++++++(V===V=}++++++++++++/===" << endl;
				cout << "+++++++++(=|=/=\\+++++++++/====/+" << endl;
				cout << "+++++++++++^\\===\\++++++/====/+++" << endl;
				cout << "********************************" << endl;
	}

		
			
	//stage 3: low level
	if (enemyName == "Ghostly Butler" || enemyName == "Wandering Spirit" || 
    	enemyName == "Phantom Maid" || enemyName == "Whispering Ghost" ||  
   	enemyName == "Haunting Portrait" || enemyName == "Echoing Laughter" || 
    	enemyName == "Mysterious Footsteps" || enemyName == "Cursed Doll" ||
	enemyName == "Creepy Shadow" || enemyName == "Abandoned Child") {
				cout << "++++---+++++------++++++--++++++" << endl; 
				cout << "++++++---+++-------++++-++++++++" << endl; 
				cout << "+++++--++++)0----0-(++++--++++++" << endl; 
				cout << "+++++----++\\--<>--/++++---++++++" << endl; 
				cout << "+++++++++--|-----|++----++++++++" << endl; 
				cout << "********************************" << endl; 
	}

	//stage 3: mid level
	if (enemyName == "Spectral Hound" || enemyName == "The Shadowed Figure" || 
    	enemyName == "The Lurking Horror" || enemyName == "Restless Soul" ||  
   	enemyName == "Sinister Presence") {
				cout << "+++++++++++^+++++++^++++++++++++" << endl; 
				cout << "+++++++++/-\\---/---|++++++++++++" << endl; 
				cout << "++++++++|[|]--[|]--)++++++++++++" << endl; 
				cout << "+++++++|-vv-------/-|+++++++++++" << endl; 
				cout << "++++++++-v-v---------\\++++++++++" << endl; 
				cout << "********************************" << endl; 
	} else if (enemyName == "Vengeful Spirit" || enemyName == "Ghostly Apparition" || 
    	enemyName == "Haunted Mirror" || enemyName == "Cursed Mirror" ||  
   	enemyName == "The Weeping Woman") {
				cout << "++++++____________________++++++" << endl; 
				cout << "+++++|=======-------======|+++++" << endl; 
				cout << "+++++|======-U---U---=====|+++++" << endl; 
				cout << "+++++|======---------=====|+++++" << endl; 
				cout << "+++++|=======--^-----=====|+++++" << endl; 
				cout << "********************************" << endl; 
	}

	//stage 3: high level
	if (enemyName == "The Haunted Lord" || enemyName == "The Phantom of the Manor" || 
    	enemyName == "The Wraith King" || enemyName == "The Lady of the House" ||  
   	enemyName == "The Cursed Revenant" || enemyName == "The Undying Specter" || 
	enemyName == "The Original Owner" || enemyName == "The Dark Guardian" || 
	enemyName == "The Keeper of Secrets" ||  enemyName == "The Abomination of the Manor" ) {
				cout << "++++---+++++--++++--++++++--++++" << endl; 
				cout << "++++++---++----++---++++-+++++++" << endl; 
				cout << "+++++--++-{|}---{|}--++++--+++++" << endl; 
				cout << "--+++----++---<>----++++---+++++" << endl; 
				cout << "+--+++--++++-----++++++----++--+" << endl;
				cout << "********************************" << endl; 
	}
		
		
			
	//stage 4: low level
	if (enemyName == "Demonic Imp" || enemyName == "Hellhound" ||
	enemyName == "Infernal Wraith" || enemyName == "Fire Elemental" ||
	enemyName == "Cursed Soul" ||enemyName == "Tormented Spirit" || 
	enemyName == "Shadow Demon" || enemyName == "The Bloodletter" || enemyName == "The Whispering Fiend") {
				cout << "+++++++++++^+++++++^++++++++++++" << endl; 
				cout << "+++++++++/=\\===/===|++++++++++++" << endl; 
				cout << "++++++++{{|}=={|}==}++++++++++++" << endl; 
				cout << "+++++++{=vv=======/=}+++++++++++" << endl; 
				cout << "+++++++++\\v=v===/====\\++++++++++" << endl; 
				cout << "********************************" << endl; 
	}

	//stage 4: mid level
	if (enemyName == "Demon Knight" || enemyName == "Hellfire Beast" ||
	enemyName == "Screaming Banshee" || enemyName == "The Scourge" ||
	enemyName == "The Reaper" || enemyName == "Infernal Executioner" ||
	enemyName == "The Voidwalker" || enemyName == "The Tormentor" ||
	enemyName == "The Vile Sorcerer" || enemyName == "The Bloodthirsty Fiend") {
				cout << "++---+++++++++++++^+++++++++++++" << endl;
				cout << "+-**--++++++++\\===/=\\+++++++++++" << endl;
				cout << "+-***---++++{|}==={|}\\++++++++++" << endl;
				cout << "+--+\\+++++/=====V======\\++++++++" << endl;
				cout << "+++++\\+++/==============\\+++++++" << endl;
				cout << "********************************" << endl;
	}

	//stage 4: high level
	if (enemyName == "The Dark Lord" || enemyName == "Satan's Chosen" ||
	enemyName == "The Devil Incarnate" || enemyName == "The Master of Hell" ||
	enemyName == "The Abyssal Overlord" || enemyName == "The Great Deceiver" ||
	enemyName == "The Infernal Tyrant" || enemyName == "The Harbinger of Chaos" ||
	enemyName == "The Eternal Damnation" || enemyName == "The Ruler of the Underworld") {
				cout << "++++++^++++++++++++++++++^++++++" << endl;
				cout << "+++++|=|++++________++++|=|+++++" << endl;
				cout << "++++++\\==\\/==========\\/==/++++++" << endl;
				cout << "++++++++{===^======^===}++++++++" << endl;
				cout << "++++++++)=={|}===={|}==(++++++++" << endl;
				cout << "********************************" << endl;
	}


			
	//final boss
	if (enemyName == "Fallen Angel") {
				cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "+++++++++++_____+++++++++++++++++_____+++++++++++" << endl;
				cout << "+++++++++/========\\+++++++++++/========\\+++++++++" << endl;
				cout << "++++++++/============\\++^++/============\\++++++++" << endl;
				cout << "++++++/=======/=======-----======\\========\\++++++" << endl;
				cout << "++++/======//+++\\==={--{|}--}===/++\\==\\====\\+++++" << endl;
				cout << "+++/=====/+++++++++\\==-----==/+++++++\\=\\\\==\\+++++" << endl;
				cout << "+/=//==/++++++++++++++++V+++++++++++++++++\\=\\\\+++" << endl;
				cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "*************************************************" << endl;
	}
}
