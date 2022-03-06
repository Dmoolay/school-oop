/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

Person::Person()  // default constructor
{
	this->first_name = "-";
	this->last_name = "-";
	this->id = 0;
}

Person::Person(string First_name, string Last_name, int ID) // constructor
{
	this->first_name = First_name;
	this->last_name = Last_name;
	this->id = ID;
}

Person::~Person()
{

}
/*
void Person::print_details()
{
	cout << "Name: " <<this->first_name << " " << this->last_name << endl;
	cout << "ID: " << this->id << endl;
}

bool Person::check_if_excel()
{
	
	//return false;
}
*/



