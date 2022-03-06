#pragma once
#include "AdministrationPersonal.h"
#include "Worker.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;


class Secretary: public AdministrationPersonal
{
protected:
	int kid_num;

public:
	Secretary();
	Secretary(string, string, int, float, float, string, int);
	virtual ~Secretary();

	float get_salary();
	bool check_if_excel();
	void print_details();

	// get and set function.
	void set_kid_num(int A) { this->kid_num = A; }
	int get_kid_num() { return this->kid_num; }
};

