/*
 * PirateMates.h
 * COMP15
 * Spring 2018
 *
 * Interface for a PirateMate class
 * yo ho ho
 */
#include <string>
#include <Pirate.h>
#include <ArrayList.h>


using namespace std;


#ifndef PIRATESMATE_H_
#define PIRATESMATE_H_

struct PirateMates
{
	Pirate pirate;
	ArrayList mates;
};

#endif