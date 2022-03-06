#pragma once
#include "Layer.h"
#include "Class.h"
#include "Manager.h"
#include "Secretary.h"
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

class School {
protected:
	static School* instance;
	vector <Layer*> Layers;
	int num_of_layers;
	vector <Pupil*> pupils;
	vector <Worker*> workers;
	vector <Tutor*> tutors;  // tutors vector only!

private:
	bool check_if_class(char, int);
	Class get_class(char, int);
	void create_pupil();
	void create_teacher();
	void create_tutor();
	void create_secretary();
	void create_manager();
	void remove_tutor(int);
	void create_class_for_pupil(char, int, Pupil*);
	void create_class_for_tutor(char, int, Tutor*);
	// Private constructor so that no objects can be created.
	School() 
	{
		vector <Layer*> v1;
		vector <Pupil*> v2;
		vector <Worker*> v3;
		vector <Tutor*> v4;
		num_of_layers = 0;
		this->Layers = v1;
		this->pupils = v2;
		this->workers = v3;
		this->tutors = v4;
		char a = 'a';
		for (int i = 0; i < 6; i++)
		{
			Layer *L = new Layer();
			L->set_Layer_name(a + i);
			//Layer* A = L;
			this->Layers.push_back(L);
		}
		this->num_of_layers = 6;
	}
	School(vector <Layer*> Layers1, int num_of_layers1, vector <Pupil*> pupils1, vector <Worker*> workers1, vector <Tutor*> tutors1) 
	{
		this->Layers = Layers1;
		this->num_of_layers = num_of_layers1;
		this->pupils = pupils1;
		this->workers = workers1;
		this->tutors = tutors1;
		// create 6 layers automatically when create a school.
		char a = 'a';
		for (int i = 0; i < 6; i++)
		{
			Layer *L = new Layer();
			L->set_Layer_name(a + i);
			//Layer* A = L;
			this->Layers.push_back(L);
		}
		this->num_of_layers = 6;
		/////
	}

public:

	static School* createschool(vector <Layer*> Layers1, int num_of_layers1, vector <Pupil*> pupils1, vector <Worker*> workers1, vector <Tutor*> tutors1)
	{
		if (instance != NULL)
		{
			cout << "school already exists!" << endl;
		}
		else
		{
			instance = new School(Layers1, num_of_layers1, pupils1, workers1, tutors1);
		}
		return instance;
	}

	static School* createschool()
	{
		if (instance != NULL)
		{
			cout << "school already exists!" << endl;
		}
		else
		{
			instance = new School();
		}
		return instance;
	}

	void menu();
};
