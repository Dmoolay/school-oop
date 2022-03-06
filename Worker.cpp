#include "Worker.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

//int basis = 25;
int Worker::basis = 25;
Worker::Worker():Person()  // default constructor
{
	this->m_seniority = 0;
	this->t_seniority = 0;
}

Worker::Worker(string fn, string ln, int ID, float m, float t):Person(fn, ln, ID)
{
	//  constructor
	this->m_seniority = m;
	this->t_seniority = t;
}


Worker::~Worker()
{
	//
}

/*
float Worker::get_salary()
{
	return 0.0f;
}


void Worker::print_details()
{
	cout << "worker name: " << this->get_fname() << " " << this->get_lname() << endl;
	cout << "seniority: " << endl;
	cout << "managerial seniority: " << this->m_seniority << endl;
	cout << "teaching seniority: " << this->t_seniority << endl;
	cout << "" << endl;
}
*/