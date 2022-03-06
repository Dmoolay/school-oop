/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/
#include "AdministrationPersonal.h"

// absract class, not using any functions

AdministrationPersonal::AdministrationPersonal():Worker()
{
	this->office_number = "-";
}

AdministrationPersonal::AdministrationPersonal(string fn, string ln, int ID, float m, float t, string office_n):Worker(fn, ln, ID, m, t)
{
	this->office_number = office_n;
}

AdministrationPersonal::~AdministrationPersonal()
{
	//
}
