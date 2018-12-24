/*
 * Actor.cpp
 *
 * Implementation for Actor class
 *
 * COMP15
 * Spring 2018
 * Homework 5
 * Author: Xinying Guo
 * date: Monday,April 2
 * Actor class with actor name 
 * and movies 
 */

#include "Actor.h"

// Default constructor
Actor::Actor()
{
	name = "-1";
}

// Function add_name
// Input: string 
// Returns: void
// Does: add movie name to the movies
void Actor::add_name(string movie)
{
	movies.insert(movie);
}

// Function if_in
// Input: string 
// Returns: bool
// Does: check if the actor showed in this movie 
bool Actor::if_in(string movie)
{
	bool in_movies;
	movie = movies.find(movie, in_movies);
	return in_movies;
}

// Function connect
// Input: Actor 
// Returns: string
// Does: find the first commom movie played 
// 		with another actor
string Actor::connect(Actor actor)
{
	bool in_movies;

	for (int i = 0; i < movies.get_length(); i++)
	{
		string movie = movies.get_value_at(i);
		actor.movies.find(movie, in_movies);
		if (in_movies)
			return movie;
	}

	return "";
}

// Override operating operator
// Input: const Actor &a, const Actor &b
// Returns: bool 
// Does: if 2 actors name is same, they are same 
bool operator == (const Actor &a, const Actor &b)
{
	return (a.name == b.name);
}

// Override operating operator
// Input: const Actor &a, const Actor &b
// Returns: bool 
// Does: if 2 actors name is not same, they are different
bool operator != (const Actor &a, const Actor &b)
{
	return !(a == b);
}

// Override operating operator
// Input: ostream & out, const Actor &a
// Returns: ostream
// Does: out put the actors name to ostream out
ostream & operator << (ostream & out, const Actor &a)
{
	out << a.name;
	return out;
}

// Function set_name
// Input: string 
// Returns: void 
// Does: set the actor's name to string
void Actor::set_name(string actor)
{
	name = actor;
}

// Function get_name
// Input: None 
// Returns: string
// Does: get the actor's name to string
string Actor::get_name() const
{
	return name;
}
