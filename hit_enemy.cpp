#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include<cstdio>
using namespace std;

int hit_enemy(int str, int dex, int wep, int enemy_ac)
{
	int roll;
	if(wep == 1)
	{
		roll = (rand()%6) + (rand()%6);
	}
	else if(wep == 2)
	{
		roll = (rand()%8) + (rand()%8);	
	}
	else if(wep == 3)
	{
		roll = (rand()%8) + (rand()%8);
		roll =  roll + (dex - 10) - enemy_ac;
		return roll;
	}
	else
	{
		roll = (rand()%10) + (rand()%10);
	}
	roll = (roll + (str - 10)) - enemy_ac;
	return roll; 

}