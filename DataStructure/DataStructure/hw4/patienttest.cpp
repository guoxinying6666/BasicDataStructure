#include <iostream>
#include "MinHeap.h"
#include "Patient.h"
using namespace std;

int main ()
{
	cout << "excuse me" << endl;
	Patient p1,p2,p3,p4,p5,p6;
	p1.calculate_priority(true,true,100, 100, 6, false);
	p2.calculate_priority(true,true,100, 100, 5, false);
	p3.calculate_priority(true,true,100, 100, 4, false);
	p4.calculate_priority(true,true,100, 100, 3, false);
	p5.calculate_priority(true,true,100, 100, 2, false);
	p6.calculate_priority(true,true,100, 100, 1, false);
	Heap<Patient> *min = new MinHeap<Patient>;
	
	min->insert_item(p1);
	min->insert_item(p2);	
	min->insert_item(p3);	
	min->insert_item(p4);		
	min->insert_item(p5);
	min->insert_item(p6);	

	for (int i = 0; i < 6; i++)
	{
		cout << min[i];
	}
	cout << endl;
	return 0;
}