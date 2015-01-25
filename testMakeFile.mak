arenaproject: RPG.cpp hit_enemy.cpp get_weapon.cpp tutorial_menu.cpp
	g++ RPG.cpp hit_enemy.cpp get_weapon.cpp tutorial_menu.cpp -o ARENA
RPG.cpp: RPG.cpp
	g++ -c RPG.cpp
hit_enemy.cpp: hit_enemy.cpp
	g++ -c hit_enemy.cpp
get_weapon.cpp: get_weapon.cpp
	g++ -c get_weapon.cpp
tutorial_menu.cpp: tutorial_menu.cpp
	g++ -c tutorial_menu.cpp