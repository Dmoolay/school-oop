/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/
#pragma once
#include "AdministrationPersonal.h"
//#include "Class.h"
#include "Teacher.h"
#include "Worker.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;


class Manager :public Teacher, public AdministrationPersonal
{
//protected:
	
private:
	static Manager* instance;
	// Private constructor so that no objects can be created.
	Manager():Worker(), Teacher(), AdministrationPersonal()
	{}

	Manager(string fn, string ln, int ID, float m, float t, vector<string> Courses, int num_courses, string office_num):Worker(fn, ln, ID, m, t),Teacher(fn,ln,ID,m,t, Courses, num_courses),AdministrationPersonal(fn, ln, ID, m, t, office_num)
	{}

public:
	static Manager* createmanager(string fn, string ln, int ID, float m, float t, vector<string> Courses, int num_courses, string office_num) 
	{
		if (instance != NULL) 
		{
			cout << "school already has manager!" << endl;
		}
		else
		{
			instance = new Manager(fn, ln, ID, m, t, Courses, num_courses, office_num);
		}
		return instance;
	}

	static Manager* createmanager()
	{
		if (instance != NULL)
		{
			cout << "school already has manager!" << endl;
		}
		else
		{
			instance = new Manager();
			cout << "Manager successfully added" << endl;
		}
		return instance;
	}
	virtual ~Manager(); 
	float get_salary();
	bool check_if_excel();
	void print_details();

	static Manager* get_instance() { return instance; }
	//void set_instance(static Manager* A) { instance = A; }
};

