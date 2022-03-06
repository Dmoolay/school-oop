/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/
#pragma once
#include "Worker.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

class AdministrationPersonal :virtual public Worker
{
protected:
	string office_number;

public:
	AdministrationPersonal();
	AdministrationPersonal(string, string, int, float, float, string);
	virtual ~AdministrationPersonal();

	// abstract function that will not in this class.
	virtual float get_salary()=0;
	virtual bool check_if_excel()=0;
	virtual void print_details()=0;

	// get and set function.
	void set_office_number(string A) { this->office_number = A; }
	string get_office_number() { return this->office_number; }
};

