/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/
#include "Manager.h"

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Manager *Manager::instance = NULL;


Manager::~Manager()
{}

float Manager::get_salary()   // get salary of manager(can be also a teacer)
{
	float x;
	if (this->get_num_courses() > 0)
	{
		 x = this->Teacher::get_salary();
	}
	else
	{
		x = 0;
	}
	float y = 500 * this->get_m_seniority();
	return ((basis*2) + x + y);
}

bool Manager::check_if_excel()  // check if excel by manager terms
{
	if (this->get_m_seniority() > 3)
	{
		return true;
	}
	return false;
}

void Manager::print_details()   // print all manager details
{
	cout << "A manager: " << endl;
	cout << "name: " << this->get_fname() << " " << this->get_lname() << endl;
	cout << "ID: " << this->id << endl;
	cout << "teaching seniority: " << this->t_seniority << endl;
	cout << "administrative seniority: " << this->m_seniority << endl;
	cout << "salary: " << this->get_salary() << endl;
	if (this->get_num_courses() > 0)
	{
		cout << "number of courses: " << this->num_courses << endl;
		this->print_courses();
	}
	if (this->check_if_excel())
	{
		cout << "the manager excels. " << endl;
	}
	else
	{
		cout << "the manager not excels. " << endl;
	}
	cout << "" << endl;
}
