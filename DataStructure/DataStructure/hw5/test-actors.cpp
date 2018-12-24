#include "SixDegrees.h"
using namespace std;

void add_movies(Actor &, Actor &);
void if_movie_in(Actor &, Actor &);
void if_connect(Actor &, Actor &);
void operator_test();
//void test_populate_tree();

int main()
{
	Actor a,b;
	add_movies(a,b);
	if_movie_in(a,b);
	if_connect(a,b);
	operator_test();

}



void add_movies(Actor &a, Actor &b)
{
	a.add_name("q");
	a.add_name("w");
	a.add_name("e");
	a.add_name("r");

	b.add_name("a");
	b.add_name("s");
	b.add_name("d");
	b.add_name("r");

	if (a.if_in("r"))
		cout << "insert success" << endl;
	else 
		cout << "insert fail" << endl;
}

void if_movie_in(Actor &a, Actor &b)
{
	if (b.if_in("s"))
		cout << "find movie success" << endl;
	else 
		cout << "find movie fail" << endl;
}

void if_connect(Actor &a, Actor &b)
{
	string common = a.connect(b);
	if (common == "r")
		cout << "connect success" << endl;
	else 
		cout << "connect fail" << endl;
}

void operator_test()
{
	Actor c,d;
	c.add_name("q");
	c.set_name("Jackie Chen");
	if (c != d)
		cout << "!= success" << endl;
	//else cout << "!= fail" << endl;
	d.set_name("Jackie Chen");
	d.add_name("q");
	if (c == d)
		cout << "== success" << endl;
	//else 
		//cout << "== fail" << endl;
}