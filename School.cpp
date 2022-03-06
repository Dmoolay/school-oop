#include "School.h"
#include "Layer.h"
#include "Class.h"
#include "Manager.h"
#include "Tutor.h"
#include "Teacher.h"
#include "Worker.h"
#include "Person.h"
#include "Pupil.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

School *School::instance = NULL;

bool School::check_if_class(char L, int C) //function that checks if class exists.
{
	for (Layer* x : this->Layers)
	{
		if (x->get_Layer_name() == L)
		{
			for (Class* y : x->get_classes())
			{
				if (y->get_num_class() == C)
				{
					return true;
				}
			}
			return false;
		}
	}
}

Class School::get_class(char L, int C)
{     // get a specific class (if exists) by layer name(a-f) and class number(1-3)
	for (Layer* x : this->Layers)
	{
		if (x->get_Layer_name() == L)
		{
			for (Class* y : x->get_classes())
			{
				if (y->get_num_class() == C)
				{
					return *y;
				}
			}
		}
	}
}

void School::create_pupil()
{
	string fname, lname;
	char layer_name;
	int id, class_number, number_of_grades, grade;
	vector <int> grades;
	bool z = true;

	cout << "insert first name: " << endl;
	cin.clear();
	cin.ignore();
	getline(cin, fname);

	cout << "insert last name: " << endl;
	cin.clear();
	//cin.ignore();
	getline(cin, lname);

	cout << "insert ID number: " << endl;
	while (z) {        // while loop until input is valid
		cin.clear();
		//cin.ignore();
		cin >> id;
		if (id > 0)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert layer name (single letter between 'a' to 'f'): " << endl;
	while (z) {            // while loop until input is valid
		cin.clear();
		cin.ignore();
		cin >> layer_name;
		if (layer_name >= 'a' && layer_name <= 'f')
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert layer name again" << endl;
		}
	}
	z = true;

	cout << "insert class number (number between 1 to 3): " << endl;
	while (z) {               // while loop until input is valid
		cin.clear();
		cin.ignore();
		cin >> class_number;
		if (class_number >= 1 && class_number <= 3)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert class number again" << endl;
		}
	}
	z = true;

	cout << "insert how many grades the pupil has (number between 1 to 10): " << endl;
	while (z) {              // while loop until input is valid
		cin.clear();
		cin.ignore();
		cin >> number_of_grades;
		if (number_of_grades >= 1 && number_of_grades <= 10)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert grade one by one (number between 0 to 100): " << endl;
	for (int i = 0; i < number_of_grades; i++)
	{       //  for loop to get student grades
		cout << "insert grade number " << i + 1 << " : " << endl;
		while (z) {           // while loop until input is valid
			cin.clear();
			cin.ignore();
			cin >> grade;
			if (grade >= 0 && grade <= 100)
			{
				grades.push_back(grade);
				z = false;
			}
			else
			{
				cout << "invalid input, insert number again" << endl;
			}
		}
		z = true;
	}
	
	Pupil* p = new Pupil(fname, lname, id, grades, layer_name, class_number);
	this->pupils.push_back(p);
	if (!this->check_if_class(layer_name, class_number))
	{
		cout << "create a new class for pupil" << endl;
		this->create_class_for_pupil(layer_name, class_number, p);
	}
	else
	{
		//this->get_class(layer_name, class_number).set_students(p);
		for (Layer* x : this->Layers)
		{
			if (x->get_Layer_name() == layer_name)
			{
				for (Class* y : x->get_classes())
				{
					if (y->get_num_class() == class_number)
					{
						y->set_students(p);
					}
				}
			}
		}
	}
	return;
}

void School::create_teacher()
{
	string fname, lname;
	float t;
	string course;
	int id, number_of_courses;
	vector <string> courses;
	bool z = true;

	cout << "insert first name: " << endl;
	cin.clear();
	cin.ignore();
	getline(cin, fname);

	cout << "insert last name: " << endl;
	cin.clear();
	//cin.ignore();
	getline(cin, lname);

	cout << "insert ID number: " << endl;
	while (z) {        // while loop until input is valid
		cin.clear();
		//cin.ignore();
		cin >> id;
		if (id > 0)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert teaching seniority (number of years, 50 max): " << endl;
	while (z) {         // while loop until input is valid
		cin.clear();
		cin.ignore();
		cin >> t;
		if (t >= 0 && t <= 50)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert how many courses the teacher teach (number between 1 to 10): " << endl;
	while (z) {         // while loop until input is valid
		cin.clear();
		cin.ignore();
		cin >> number_of_courses;
		if (number_of_courses >= 1 && number_of_courses <= 10)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert course name one by one: " << endl;
	for (int i = 0; i < number_of_courses; i++)
	{    // for loop to get course names
		cout << "insert course name number " << i + 1 << " : " << endl;
		cin.clear();
		cin.ignore();
		cin >> course;
		courses.push_back(course);
	}
	Teacher* t1 = new Teacher(fname, lname, id, 0, t, courses, number_of_courses);
	this->workers.push_back(t1);
	return;
}

void School::create_tutor()
{
	string fname, lname;
	float t;
	char layer_name;
	string course;
	int id, number_of_courses, class_number;
	vector <string> courses;
	Class* ptr = NULL;
	bool z = true;

	cout << "insert first name: " << endl;
	cin.clear();
	cin.ignore();
	getline(cin, fname);

	cout << "insert last name: " << endl;
	cin.clear();
	//cin.ignore();
	getline(cin, lname);

	cout << "insert ID number: " << endl;
	while (z) {
		cin.clear();
		//cin.ignore();
		cin >> id;
		if (id > 0)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "Insert layer name (single letter between 'a' to 'f'): " << endl;
	while (z) {
		cin.clear();
		cin.ignore();
		cin >> layer_name;
		if (layer_name >= 'a' && layer_name <= 'f')
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert layer name again" << endl;
		}
	}
	z = true;

	cout << "Insert class number (number between 1 to 3): " << endl;
	while (z) {
		cin.clear();
		cin.ignore();
		cin >> class_number;
		if (class_number >= 1 && class_number <= 3)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert class number again" << endl;
		}
	}
	z = true;

	cout << "insert teaching seniority (number of years, 50 max): " << endl;
	while (z) {
		cin.clear();
		cin.ignore();
		cin >> t;
		if (t >= 0 && t <= 50)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert how many courses the teacher teach (number between 1 to 10): " << endl;
	while (z) {
		cin.clear();
		cin.ignore();
		cin >> number_of_courses;
		if (number_of_courses >= 1 && number_of_courses <= 10)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert course name one by one: " << endl;
	for (int i = 0; i < number_of_courses; i++)
	{
		cout << "insert course name number " << i + 1 << " : " << endl;
		cin.clear();
		cin.ignore();
		cin >> course;
		courses.push_back(course);
	}

	Tutor* t2 = new Tutor(fname, lname, id, 0, t, courses, number_of_courses, ptr);
	int tmp = 0;
	if (this->check_if_class(layer_name, class_number)) // if class exists ,conect between tutor to class.
	{
		if (this->get_class(layer_name, class_number).get_teacher()) // if we need to remove old tutor pointer.
		{
			//this->remove_tutor(this->get_class(layer_name, class_number).get_teacher()->get_id()); //remove old tutor.
			for (Layer* x : this->Layers)
			{
				if (x->get_Layer_name() == layer_name)
				{
					for (Class* y : x->get_classes())
					{
						if (y->get_num_class() == class_number)
						{
							tmp = y->get_teacher()->get_id();
						}
					}
				}
			}
			this->remove_tutor(tmp);
		}
		//t2->set_ptr(&get_class(layer_name, class_number)); // set tutor pointer to class.
		for (Layer* x : this->Layers)
		{
			if (x->get_Layer_name() == layer_name)
			{
				for (Class* y : x->get_classes())
				{
					if (y->get_num_class() == class_number)
					{
						t2->set_ptr(y);
					}
				}
			}
		}
		//this->get_class(layer_name, class_number).set_teacher(t2); //set class pointer to tutor.
		for (Layer* x : this->Layers)
		{
			if (x->get_Layer_name() == layer_name)
			{
				for (Class* y : x->get_classes())
				{
					if (y->get_num_class() == class_number)
					{
						y->set_teacher(t2);
					}
				}
			}
		}
	}
	else
		// create a new class for tutor
	{
		cout << "creating new class for tutor." << endl;
		this->create_class_for_tutor(layer_name, class_number, t2);
	}

	this->workers.push_back(t2);
	this->tutors.push_back(t2);
	return;
}

void School::create_secretary()
{
	string fname, lname;
	float m;
	string office_number;
	int id, number_of_kids;
	bool z = true;

	cout << "insert first name: " << endl;
	cin.clear();
	cin.ignore();
	getline(cin, fname);

	cout << "insert last name: " << endl;
	cin.clear();
	cin.ignore();
	getline(cin, lname);

	cout << "insert ID number: " << endl;
	while (z) {   // while loop until input is valid
		cin.clear();
		cin.ignore();
		cin >> id;
		if (id > 0)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert administrative seniority (number of years, 50 max): " << endl;
	while (z) {         // while loop until input is valid
		cin.clear();
		cin.ignore();
		cin >> m;
		if (m >= 0 && m <= 50)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert office number(letter allowed): " << endl;
	cin.clear();
	cin.ignore();
	getline(cin, office_number);
		
	cout << "insert number of kids (15 max): " << endl;  //biggest family i know!
	while (z) {        // while loop until input is valid
		cin.clear();
		//cin.ignore();
		cin >> number_of_kids;
		if (number_of_kids >= 0 && number_of_kids <= 15)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	Secretary* s1 = new Secretary(fname, lname, id, m, 0, office_number, number_of_kids);
	this->workers.push_back(s1);
	return;
}

void School::create_manager()
{
	string fname, lname;
	float t,m;
	string course, office_number;
	int id, number_of_courses;
	vector <string> courses;
	bool z = true;

	cout << "insert first name: " << endl;
	cin.clear();
	cin.ignore();
	getline(cin, fname);

	cout << "insert last name: " << endl;
	cin.clear();
	//cin.ignore();
	getline(cin, lname);

	cout << "insert ID number: " << endl;
	while (z) {        // while loop until input is valid
		cin.clear();
		//cin.ignore();
		cin >> id;
		if (id > 0)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert administrative seniority (number of years, 50 max): " << endl;
	while (z) {         // while loop until input is valid
		cin.clear();
		cin.ignore();
		cin >> m;
		if (m >= 0 && m <= 50)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert teaching seniority (number of years, 50 max): " << endl;
	while (z) {         // while loop until input is valid
		cin.clear();
		cin.ignore();
		cin >> t;
		if (t >= 0 && t <= 50)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	cout << "insert how many courses the manager teach (number between 1 to 10): " << endl;
	while (z) {         // while loop until input is valid
		cin.clear();
		cin.ignore();
		cin >> number_of_courses;
		if (number_of_courses >= 0 && number_of_courses <= 10)
		{
			z = false;
		}
		else
		{
			cout << "invalid input, insert number again" << endl;
		}
	}
	z = true;

	if (number_of_courses != 0)
	{
		cout << "insert course name one by one: " << endl;
		for (int i = 0; i < number_of_courses; i++)
		{    // for loop to get course names
			cout << "insert course name number " << i + 1 << " : " << endl;
			cin.clear();
			cin.ignore();
			cin >> course;
			courses.push_back(course);
		}
	}
	
	cout << "insert office number(letter allowed): " << endl;
	cin.clear();
	cin.ignore();
	getline(cin, office_number);

	Manager* s1 = Manager::createmanager(fname, lname, id, m, t, courses, number_of_courses, office_number);
	this->workers.push_back(s1);
	return;
}

void School::remove_tutor(int num)  // get id number for specific tutor and remove his class pointer (to NULL)
{
	for (Tutor* x : this->tutors) // for loop on tutors vector
	{
		if (x->get_id() == num)
		{
			x->set_ptr(NULL);
			return;
		}
	}
}

void School::create_class_for_pupil(char L, int C, Pupil* p)
{
	Class *class1 = new Class();
	class1->set_layer(L);
	class1->set_num_class(C);
	class1->set_class_size(1);
	class1->set_students(p);
	for (Layer* x : this->Layers)
	{
		if (x->get_Layer_name() == L)
		{
			x->set_Layer_size(1);
			x->set_classes(class1);
			return;
		}
	}
}

void School::create_class_for_tutor(char L, int C, Tutor* T)
{
	Class *class1 = new Class();
	class1->set_layer(L);
	class1->set_num_class(C);
	T->set_ptr(class1);
	class1->set_teacher(T);
	for (Layer* x : this->Layers)
	{
		if (x->get_Layer_name() == L)
		{
			x->set_Layer_size(1);
			x->set_classes(class1);
			return;
		}
	}
}

void School::menu()
{
	
	string fname, lname;
	char layer_name;
	int x, id, class_number, number_of_grades, grade, count = 0, sum = 0;
	vector <int> grades;
	vector <Worker*> high_paid;
	
	Pupil pupil1;
	Pupil* pupil2;
	Pupil *p;
	Teacher teacher1;
	Teacher* teacher2;
	Tutor tutor1;
	Tutor* tutor2;
	//Manager* manager1 = Manager::createmanager();
	//manager1->set_instance(NULL);
	//Manager* manager1 = &manager1->getInstance();

	Secretary secretary1;
	Secretary* secretary2;
	
	bool y = true, z = true;
	while (y)
	{
		cout << "Welcome! please choose one of the following options: " << endl;
		cout << "==========================================================" << endl;
		cout << "1) Add a new pupil to the school." << endl;
		cout << "2) Add a new teacher to the school." << endl;
		cout << "3) Add a new tutor to the school." << endl;
		cout << "4) Add a manager to the school." << endl;
		cout << "5) Add a new secretary to the school." << endl;
		cout << "6) Print all people in school." << endl;
		cout << "7) Print all outstanding people in school." << endl;
		cout << "8) Print specific tutor's class." << endl;
		cout << "9) Print highest paid worker(s)." << endl;
		cout << "10) Quit the program." << endl;
		cout << "==========================================================" << endl;
		cout << "" << endl;
		cin >> x;
		
		switch (x) {
		case 1:
			this->create_pupil();
			cout << "Pupil successfully added" << endl;
			cout << "" << endl;
			continue;
			
		case 2:

			this->create_teacher();
			cout << "Teacher successfully added" << endl;
			cout << "" << endl;
			continue;
			
		case 3:
			this->create_tutor();
			cout << "Tutor successfully added" << endl;
			cout << "" << endl;
			continue;
			
		case 4:
			this->create_manager();
			cout << "" << endl;
			continue;

		case 5:
			this->create_secretary();
			cout << "Secretary successfully added" << endl;
			cout << "" << endl;
			continue;
			
		case 6:
			count = 0;
			cout << "All workers details: " << endl;          // print all workers
			for (Worker* x : this->workers)
			{
				x->print_details();
				cout << "" << endl;
				count++;
			}
			if (count == 0)                                       // check if there is not workers
			{
				cout << "No workers!" << endl;
			}
			count = 0;
			cout << "All pupils details: " << endl;           // print all workers
			for (Pupil* x : this->pupils)
			{
				x->print_details();
				cout << "" << endl;
				count++;
			}
			if (count == 0)                                       // check if there is not pupils
			{
				cout << "No pupils!" << endl;
			}
			count = 0;
			continue;
			
		case 7:
			count = 0;
			cout << "All outstanding workers details: " << endl;
			for (Worker* x : this->workers)                       // print all outstanding workers
			{
				if (x->check_if_excel())
				{
					x->print_details();
					cout << "" << endl;
					count++;
				}
			}
			if (count == 0)                                       // check if there is not outstanding workers
			{
				cout << "No outstanding workers :(" << endl;
			}
			count = 0;
			cout << "All outstanding pupils details: " << endl;
			for (Pupil* x : this->pupils)                        // print all outstanding pupils
			{
				if (x->check_if_excel())
				{
					x->print_details();
					cout << "" << endl;
				}
			}
			if (count == 0)                                      // check if there is not outstanding pupils
			{
				cout << "No outstanding pupils :(" << endl;
			}
			count = 0;
			continue;
			
		case 8:
			cout << "insert tutor ID number: " << endl;
			while (z) {        // while loop until input is valid
				cin.clear();
				cin.ignore();
				cin >> id;
				if (id > 0)
				{
					z = false;
				}
				else
				{
					cout << "invalid input, insert number again" << endl;
				}
			}
			z = true;

			for (Tutor* x : this->tutors)            // search the specific tutor
			{
				if (x->get_id() == id)               // find the specific tutor
				{
					z = false;
					if (x->get_ptr())                // check if he has a class
					{
						x->print_details();
						break;
					}
					else                             // if he does not have a class
					{
						cout << "tutor does not have a class" << endl;
						cout << "" << endl;
						break;
					}
				}
			}
			if (z)                                   // if tutor was not found
			{
				cout << "no tutor match this id number!" << endl;
				cout << "" << endl;
			}
			z = true;
			continue;
			
		case 9:
			for (Worker* x : this->workers)  // search the highest paid worker and put them in new wector
			{
				if (x->get_salary() > sum)   // if the new is higher then all the previous
				{
					high_paid.clear();       // clear the vector
					high_paid.push_back(x);  // push the new worker
					sum = x->get_salary();   // update the new highest sum
					continue;
				}
				else if (x->get_salary() == sum) // if they equal
				{
					high_paid.push_back(x);      // push the new one and continue
					continue;
				}
				else                             // the new one is lower
				{
					continue;
				}
			}

			if (high_paid.size() > 0)            // print all the highest paid workers
			{
				cout << "highest paid workers are: " << endl;
				for (Worker* x : high_paid)
				{
					x->print_details();
				}
			}
			else                                 // in case there are no workers yet
			{
				cout << "no workers at all!" << endl;
			}
			high_paid.clear();                   // clear vector and sum for the next action
			sum = 0;
			continue;
			
		case 10:
			cout << "Goodbye!" << endl;
			delete Manager::get_instance();
			for (Worker* x : this->workers)
			{
				delete x;
			}
			for (Pupil* x : this->pupils)
			{
				delete x;
			}
			for (Layer* x : this->Layers)
			{
				for (Class* y : x->get_classes())
				{
					delete y;
				}
				delete x;
			}
			return;
			
		}
		
		if (x < 0 || x>10)
		{
			cout << "Invalid Input." << endl;
			continue;
		}
		
	}
	
}


