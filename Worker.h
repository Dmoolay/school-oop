#pragma once
#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

class Worker :public Person
{
protected:
	float t_seniority;
	float m_seniority;
	static int basis;

public:
	Worker();
	Worker(string, string, int, float, float);
	virtual ~Worker();

	// abstract function that will not in this class.
	virtual float get_salary()=0;
	virtual void print_details()=0;

	// get and set function.
	void set_t_seniority(float A) { this->t_seniority = A; }
	void set_m_seniority(float A) { this->m_seniority = A; }
	
	float get_t_seniority() { return this->t_seniority; }
	float get_m_seniority() { return this->m_seniority; }
};

