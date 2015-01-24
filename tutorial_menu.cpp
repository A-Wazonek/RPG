#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include<cstdio>
using namespace std;

void tutorial_menu(void)
{
	cout << "Your character has 3 stats, STR, PHYS, DEX" << endl;
	cout << "STR affects your damage with weapons" << endl;
	cout << "PHYS affects your health and your AC" << endl;
	cout << "DEX affects your AC and your hit with Rapiers"<< endl;
	cout << endl;
	cout << "When you make your character you get 2 stat boosts, humans get 4. " << endl;
	cout << "Elves are fast and strong, and have +2 to Dex and Str, but are frail and get -2 to Phys" << endl;
	cout << "Dwarves are slow but strong and hardy, they get +2 to STR and PHYS but -2 to DEX" << endl;
	cout << "Humans vary, they get +2 custom stats" << endl;
	cout << endl << endl;
	
	cout << "Combat works as follows: " << endl;
	cout << "HP is equal to your Phys + your level. When your HP is 0 you're dying, and when its negative you're dead!" << endl;
	cout << "AC is equal to 6 + your Phys-10 + your Dex - 10" << endl;
	cout << "Each weapon has its own roll, and STR is added to that roll, unless you're using a Rapier then DEX is added." << endl;
	cout << "Roll higher than your opponents AC and you'll deal damage!" << endl;
	cout << endl << endl;
	cout << "At the first level you start with a dagger, but as you level you get stronger and stronger weapons" << endl;

}