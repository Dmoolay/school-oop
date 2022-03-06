#pragma once
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


template <class T> class VecAnalyser
{
	vector <T*> vec;

public:
	VecAnalyser();
	VecAnalyser(vector <T*> v1);
	~VecAnalyser();
	T get_obj_by_idx(int idx);
	void swap(int idx1, int idx2);
	void printElement(int idx);
	void printAll();
	void printMax();
};

