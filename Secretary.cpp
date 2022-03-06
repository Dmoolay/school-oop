#include "Secretary.h"
#include "AdministrationPersonal.h"
#include "Worker.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;


Secretary::Secretary():AdministrationPersonal() // default constructor
{

}

Secretary::Secretary(string fn, string ln, int ID, float m, float t, string office_n, int kids):Worker(fn, ln, ID, m, t), AdministrationPersonal(fn, ln, ID, m, t, office_n)
{
	// constructor
	this->kid_num = kids;
}

Secretary::~Secretary()
{
	//
}

float Secretary::get_salary()  // get salary of secretary
{
	int x = this->kid_num * 200;
	return (basis + x);
}


bool Secretary::check_if_excel()   // check if excel by secretary terms
{
	if (this->m_seniority > 10)
	{
		return true;
	}
	return false;
}

void Secretary::print_details()  // print all secretary details
{
	cout << "A secretary: " << endl;
	cout << "name: " << this->get_fname() << " " << this->get_lname() << endl;
	cout << "ID: " << this->id << endl;
	cout << "administrative seniority: " << this->m_seniority << endl;
	cout << "salary: " << this->get_salary() << endl;
	cout << "office number: " << this->get_office_number() << endl;
	cout << "number of kids: " << this->kid_num << endl;

	if (this->check_if_excel())
	{
		cout << "the secretary excels. " << endl;
	}
	else
	{
		cout << "the secretary not excels. " << endl;
	}
	cout << "" << endl;
}
