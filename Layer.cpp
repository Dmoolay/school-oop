/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/
#include "Layer.h"
#include "Class.h"
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

Layer::Layer()  // default constructor
{
	vector<Class*> v;
	this->Layer_name = '-';
	this->Layer_size = 0;
	this->classes = v;
}

Layer::Layer(char L_name, int L_size, vector<Class*> v) // constructor
{
	this->Layer_name = L_name;
	this->Layer_size = L_size;
	this->classes = v;
}

Layer::~Layer()
{
	//
}

Class Layer::get_class(int number)  // get a specific class
{
	try
	{
		if (number >= this->Layer_size || number < 0)
		{
			throw  number;
		}
		int j = 0;
		for (auto i = this->classes.begin(); i != this->classes.end() && j < this->Layer_size; i++, j++)
		{
			if (j == number)
			{
				return **i;
			}
		}
	}
	catch (int number)
	{
		cout << "invalid input!" << endl;
	}

}
