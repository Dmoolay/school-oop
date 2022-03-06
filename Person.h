/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

#ifndef Person_HEADER
#define Person_HEADER

class Person
{
protected:
	string first_name;
	string last_name;
	int id;              // id that help distinguish cetween each person

public:
	Person();
	Person(string, string, int);
	virtual ~Person();
	// abstract function that will not in this class.
	virtual void print_details()=0;
	virtual bool check_if_excel()=0;

	// get and set function.
	void set_fname(string A) { this->first_name = A; }
	void set_lname(string A) { this->last_name = A; }
	void set_id(int A) { this->id = A; }
	string get_fname() { return this->first_name; }
	string get_lname() { return this->last_name; }
	int get_id() { return this->id; }
};

#endif
