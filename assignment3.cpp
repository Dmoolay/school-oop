/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/
#pragma once
#include "Manager.h"
#include "School.h"
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

int main()
{
	School* f = School::createschool();
	f->menu();
	return 0;
}