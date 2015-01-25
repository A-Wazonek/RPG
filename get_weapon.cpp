#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include<cstdio>
using namespace std;

int get_weapon(int level)
{
int weapon = 1;
int choice;
if(level < 2)
{
cout << "1. Dagger" << endl;
scanf("%d",&choice);
return 1;
}
else if(level < 4)
{
cout << "1.Dagger, 2. ShortSword, 3.Rapier" << endl;
scanf("%d",&choice);
switch(choice)
{
	case 1: 
		return 1;
	case 2: 
		return 2;
	case 3:
		return 3;
	default:
		cout << "Using Dagger"<< endl;
		return 1;
}
}
else if(level < 6)
{
cout << "1.Dagger, 2. ShortSword, 3.Rapier, 4.Longsword" << endl;
scanf("%d",&choice);
switch(choice)
{
	case 1: 
		return 1;
	case 2: 
		return 2;
	case 3:
		return 3;
	case 4:
		return 4;
	default:
		cout << "Using Dagger" << endl;
		return 1;
}
}
else if(level >= 6)
{
cout << "1.Dagger, 2. ShortSword, 3.Rapier, 4.Longsword, 5. Great Axe" << endl;
scanf("%d",&choice);
switch(choice)
{
	case 1: 
		return 1;
	case 2: 
		return 2;
	case 3:
		return 3;
	case 4:
		return 4;
	case 5:
		return 5;
	default:
		cout << "Using Dagger" << endl;
		return 1;
}

}
else return 1;


}