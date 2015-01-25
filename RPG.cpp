#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include<cstdio>
using namespace std;

class character{ //This class is used for enemies and for the player
private:
	int str;
	int phys;
	int dex;
	int hp;
	int ac; 
	int weapon; //1 = dagger, 2 = short sword, 3 = rapier, 4 = longsword
	int race; // 1 = Dwarf, 2 = Elf, 3 = Human
	int level;
public:
	character(int race);
	int get_str(){return str;};
	int get_phys(){return phys;};
	int get_dex(){return dex;};
	int get_hp(){return hp;};
	int get_ac(){return ac;};
	int get_race(){return race;};
	int get_level(){return level;};
	int get_wep(){return weapon;};
	void set_wep(int wep){weapon = wep;};
	void inc_str(int newstr){str=str + newstr;};
	void inc_phys(int newphys){phys=phys + newphys;};
	void inc_dex(int newdex){dex= dex +newdex;};
	void reset_hp(){hp = phys + level;};
	void reset_ac(){ac=6 + (phys-10) + (dex-10);};
	void take_damage(int damage){hp = hp - damage;};
	void level_up();
	void print_stats();
	int check_hit(int hit){return ac - hit;};
};

character::character(int rc){
	race = rc;
	if(rc == 1) 
	{
		str = 12;
		phys = 12;
		dex = 8;
	}
	else if(rc == 2)
	{
		str = 12;
		phys = 8;
		dex = 12;
	}
	else
	{
		str = 10;
		phys = 10;
		dex = 10;	
	}
	level = 1;
	hp = (phys + level);	
	ac = (6 + (phys-10) + (dex - 10));
	weapon = 1;
}
int fight(character *player, character *enemy);
int hit_enemy(int str, int dex, int wep, int enemy_ac);
int get_weapon(int level);
void tutorial_menu();
void character::level_up(){
level++;
cout << "You leveled! Upgrade which stat?" << endl;
		cout << "1->STR: " << get_str() << endl;
		cout << "2->PHYS: " << get_phys() << endl;
		cout << "3->DEX: " << get_dex() << endl;
int new_choice;
scanf("%d",&new_choice);
switch(new_choice)
{
	case 1: 
		inc_str(1);
		break;
	case 2:
		inc_phys(1);
		break;
	default:
		inc_dex(1);
		break;
}
cout << endl;
if(level ==10){cout << "You've unlocked the Great Axe!" << endl;}
else if( level >= 6){cout << "You've unlocked the Longsword!" << endl;}
else if(level == 3){cout << "You've unlocked the Short Sword and the Rapier!" << endl;}

}

void character::print_stats(){
		cout << "Stats: " << endl;
		cout << "STR: " << this->get_str() << endl;
		cout << "PHYS: " << this->get_phys() << endl;
		cout << "DEX: " << this->get_dex() << endl << endl;


}

main(){
	int race_choice;
	cout << "Created By: Alex Wazonek" << endl; 
	cout << endl << "Arena Fighter" << endl; 
	cout << "1. Start Game" << endl;
	cout << "2. Help" << endl;
	int help_choice;
	scanf("%d",&help_choice);
	if(help_choice == 2)
	{tutorial_menu();}
	
	cout << "Select your race: " << endl; 
	cout << "1. Dwarf " << endl << "2. Elf " << endl << "3. Human" << endl;
	scanf("%d",&race_choice);
	character player(race_choice);
	int bonus_stats = 2;
	if(race_choice == 3){bonus_stats = 4;};
	
	while(bonus_stats > 0) // The player gets 2 stats at the beginning of the game, 4 if they're human
	{
		int stat_choice;
		cout << "You have " << bonus_stats << " points to spend on stats" << endl;
		player.print_stats();
		cout << "Increase: 1.STR 2.PHYS 3.DEX " << endl;
		scanf("%d",&stat_choice);
		switch(stat_choice)
		{
		case 1:
			player.inc_str(1);
			bonus_stats--;
			break;
		case 2: 
			player.inc_phys(1);
			bonus_stats--;
			break;
		case 3:
			player.inc_dex(1);
			bonus_stats--;
			break;
		default:
			cout << "Wrong choice!" << endl;
			break;
		}
			
	}
	player.reset_hp();
	player.reset_ac();
	
	cout << endl << endl << endl << endl<<endl<<endl<<endl<<endl << endl << endl << endl << endl << endl << endl;
	player.print_stats();
	cout << "HP: " << player.get_hp() << endl;
	cout << "AC: " << player.get_ac() << endl;
	
	//Fight 1
	character rat(3);
	rat.inc_str(-2);
	rat.inc_phys(-4);
	rat.inc_dex(-1);
	rat.reset_hp();
	rat.reset_ac();
	cout << "A rat appears before you, it appears feral" << endl;
	cout << "Press y to start combat" << endl;
	char start;
	cin >> start;
	int result = fight(&player, &rat);
		if(result == 1)
	{
	cout << "You kill the rat!" << endl;
	}
	else 
	{
	cout << "You died to a rat!" << endl;
	return 1;
	}
	player.reset_hp();
	
	//Fight 2
	character dog(3);
	cout << "A feral dog is tossed into the arena, prepare to fight!" << endl;
	cin >> start;
	int result2 = fight(&player, &dog);
	if(result)
	{
	cout << "You killed the dog" << endl;
	}
	else return 1;
	player.level_up();
	player.reset_hp();
	
	//Fight 3
	character human(3);
	human.inc_str(2);
	cout << "An inexperienced Gladiator appears before you, he's armed with a dagger" << endl;
	cin >> start;
	int result3 = fight(&player, &human);
	if(result3)
	{
		cout << "You killed the fighter" << endl;
	}
	else return 1;
	player.level_up();
	player.reset_hp();
	//Fight 4
	character large_human(3);
	large_human.inc_str(2);
	large_human.inc_phys(2);
	large_human.inc_dex(2);
	large_human.set_wep(2);
	cout << "A somewhat trained gladiator appears before you, he's armed with a short sword!" << endl;
	int result4 = fight(&player, &large_human);
	if(result4)
	{
		cout << "You killed the gladiator!" << endl;
	}
	player.level_up();
	player.print_stats();
	
}

//Compares two characters (one being the player, one being the enemy)
//Runs a check to see who goes first, then runs a while loop which fights the two. 
int fight(character *player, character *enemy)
{
	int won = 0;
	int init_player = (rand() % 10) + (player->get_dex() - 10);
	int init_enemy = (rand() % 10) + (enemy->get_dex() - 10);
	char first;
	if(init_player > init_enemy){cout << "You go first! "<< endl; first = 'p';}
	else 
	{
	cout << "You go second" << endl; 
	first = 'e';
	int damage = hit_enemy(enemy->get_str(),enemy->get_dex(),enemy->get_wep(),player->get_ac());
	if(damage > 0){cout << "Enemy hits for " << damage << " damage" << endl;}
	else cout << "Enemy misses" << endl;
	}
	
	
	while(won == 0)
	{
		cout << "Hit enemy with which weapon? ";
		int weapon = get_weapon(player->get_level());
		int damage1 = hit_enemy(player->get_str(),player->get_dex(),weapon,enemy->get_ac());
		if(damage1 > 0){cout << endl << "You hit the enemy for " << damage1 << " damage " << endl;enemy->take_damage(damage1);}
		else cout << "Missed enemy" << endl;
		
		
		int damage = hit_enemy(enemy->get_str(),enemy->get_dex(),enemy->get_wep(),player->get_ac());
		if(damage > 0){cout << "Enemy hits for " << damage << " damage" << endl;player->take_damage(damage);}
		else cout << "Enemy misses" << endl;
		
	
	
	if(player->get_hp() < 0){return 0;}
	if(enemy->get_hp() < 0){ return 1;}
	}
}

