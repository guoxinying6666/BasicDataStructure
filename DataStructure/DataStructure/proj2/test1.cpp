#include "Indexing.h"
#include <istream>
#include <ostream>
#include <iostream>
using namespace std;

// Wrapped functions
// Traverse Tree
void test_word ();
void test_hash_table();
void test_index();
void test_gerp();
string process_string(string);


int main()
{
	test_word();
	test_hash_table();
	//test_index();
	//test_gerp();
}

void test_word()
{
	Word a; 
	Word b("we");
	a.set_name("we");
	//cout<< a.get_lowcase_name() << "\n" << b.get_lowcase_name() << "\n";
	//cout << a.hash_value() <<  "\n" << b.hash_value() << "\n";
	a.add_location("xxx.xxx::5");
	a.add_location("fhwuk::6");
	//a.display_word();
	//a.display_word();
	//cout << a.get_name();
	//cout << a.parse_location("/comp/15/files/gerp/test-dirs/tinyData/test.txt:5:");
}

void test_hash_table()
{
	Hash h;
	h.insert_item("Shanshan", "xxx.xxx::6");
	//h.insert_item("Shanshan", "xx2.xxx::7");
	h.insert_item("ShanShan", "xx3.xxx::8");
	//h.find_item("ShanShan");
	//h.display_hash();
}

void test_index()
{
	Indexing in;
	Hash h;
	Word k;
	in.biuld_tree("/comp/15/files/gerp/test-dirs/tinyData",h);
	//in.read_in_word("test_queries.txt",h);
	h.display_hash();
	cout << "\n";
	//h.find_item("We");
	//k.display_word();
	//h.find_item("Aghjdgakyge");
	//k.display_word();
	h.find_lowcase_item("we");
	h.find_lowcase_item("we");
	h.find_lowcase_item("We");
	//k.display_word();

}

void test_gerp()
{
	cout << process_string("strange!") << endl;
	cout << process_string("strange.") << endl;

}

string process_string(string query)
{
    int start = 0, end = query.length();

    for (; start < end; start++) 
    {
        if (isalnum(query[start])) {
            break;
        }
    }

    for (; end > start; end--) 
    {
        if (isalnum(query[end])) {
            break;
        }
    }

    return query.substr(start, end - start + 1);
}