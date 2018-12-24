/* 
 * Planet.cpp
 * COMP15
 * Spring 2018
 *
 * Interface for a Planet class
 * with green cheese on top
 */

#include "Planet.h"

Planet::Planet()
{
    name = "Unplanet";
}

Planet::Planet(string n)
{
    name = n;
}

void Planet::print(ostream &out) const
{
    out << name;
}

bool operator == (const Planet &p1, const Planet &p2)
{
    return (p1.name == p2.name);
}

//Operator Overload
bool operator != (const Planet &p1, const Planet &p2)
{
	if(p1.name == p2.name)
	{
		return false;
	}
	else
	{
		return true;
	}

}


