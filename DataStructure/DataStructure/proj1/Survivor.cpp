#include "Survivor.h"

// Construction
Survivor::Survivor()
{
	first_name = "None";
	last_name = "None";
	city = "None";
	state = "None";
	age = 0;
}

// Construction 2
// Param: string fn, string ln, 
// string cty,string stt, int a
Survivor::Survivor(string fn, string ln, string cty,string stt, int a)
{		
	first_name = fn;
	last_name = ln;
	city = cty;
	state = stt;
	age = a;
}

// Function: print
// Params: ostream &out
// Returns: Nothing
// Purpose: Print names, hometown and age
void Survivor::print(ostream &out)
{
	out << first_name << " "<< last_name << "\n"
		<< "hometown:" << " " << city << ", "<< state << "\n"
		<< "age:" << " " << age << "\n"<< endl;
}

// Function: set_name
// Params: string fname, string lname
// Returns: Nothing
// Purpose: set first and last names
void Survivor::set_name(string fname, string lname)
{
	first_name = fname;
	last_name = lname;
}

// Function: set_age
// Params: double a
// Returns: Nothing
// Purpose: set age
void Survivor::set_age(double a)
{
  age = a;
}

// Function: generate_castaway
// Params: ifstream &infile, int survivor_count
// Returns: int(count of which name have been read)
// Purpose: Generate the next survivor sequently from file
int Survivor::generate_castaway(ifstream &infile, int survivor_count)
{
    int count = 0;
    stringstream ss;
    string s,ag;

    infile.clear();
    infile.seekg(0, ios::beg);
    while (getline(infile, s))
    {
        if (count == survivor_count)
        {
            stringstream ss(s);
            ss >> first_name >> last_name >> city >> state >> ag;
        	
            try
           	{
           		age = stoi(ag);
           	}
           	catch (invalid_argument exception)
           	{
           		cout << "This is not an integer" << endl;
           	}

            break;
        }

        count++;
    }

    survivor_count++;

    return survivor_count;
}

// Override operator == 
bool operator == (const Survivor &b1, const Survivor &b2)
{
	return (b1.first_name == b2.first_name &&
		   		b1.last_name == b2.last_name);
}
// Override operator <
bool operator < (const Survivor &b1, const Survivor &b2)
{
    return ((b1.last_name + b1.first_name) < 
            (b2.last_name + b2.first_name));
}

// Pverride operator >
bool operator > (const Survivor &b1, const Survivor &b2)
{
	return ((b1.last_name + b1.first_name) > 
          (b2.last_name + b2.first_name));
}

// Function: get_age
// Params: Nothing
// Returns: int (age)
// Purpose: Get age 
int Survivor:: get_age() const
{
	return age;
}

// Function: get_first_name
// Params: Nothing
// Returns: string (first_name)
// Purpose: Get first name
string Survivor::get_first_name() const
{
  return first_name;
}

// Function: get_last_name
// Params: Nothing
// Returns: string (last_name)
// Purpose: Get last name
string Survivor::get_last_name() const
{
  return last_name;
}

// Function: get_city
// Params: Nothing
// Returns: string (city)
// Purpose: Get city
string Survivor::get_city() const
{
  return city;
}

// Function: get_state
// Params: Nothing
// Returns: string (state)
// Purpose: Get state
string Survivor::get_state() const
{
  return state;
}

	

