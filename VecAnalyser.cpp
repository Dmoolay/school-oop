#include "VecAnalyser.h"

template<class T>
inline VecAnalyser<T>::VecAnalyser()
{
	vector <Pupil*> v1;
	this->vec = v1;
}

template<class T>
inline VecAnalyser<T>::VecAnalyser(vector<T*> v1)
{
	this->vec = v1;
}

template<class T>
inline VecAnalyser<T>::~VecAnalyser()
{}

template<class T>
inline T VecAnalyser<T>::get_obj_by_idx(int idx)
{
	try
	{
		if (idx >= this->vec.size())
		{
			throw idx;
		}
		int j = 0;
		for (T* x : this->vec)
		{
			if (j == idx)
			{
				return x;
			}
			j++;
		}
	}
	catch (int idx)
	{
		cout << "invalid input!" << endl;
	}
}

template<class T>
inline void VecAnalyser<T>::swap(int idx1, int idx2)
{
	try
	{
		T* tmp1;

		if (idx1 >= this->vec.size() || idx1 < 0 || idx2 >= this->vec.size() || idx2 < 0)
		{
			throw idx1;
		}
		int j = 0;
		tmp1 = this->vec[idx1];
		this->vec[idx1] = this->vec[idx2];
		this->vec[idx2] = tmp1;
	}
	catch (int idx1)
	{
		cout << "invalid input!" << endl;
	}
}


template<class T>
inline void VecAnalyser<T>::printElement(int idx)
{
	try
	{
		if (idx >= this->vec.size() || idx < 0)
		{
			throw idx;
		}
		int j = 0;
		for (T* x : this->vec)
		{
			if (j == idx)
			{
				x->print_details();
			}
			j++;
		}
	}
	catch (int idx)
	{
		cout << "invalid input!" << endl;
	}
}

template<class T>
inline void VecAnalyser<T>::printAll()
{
	if (this->vec.size() > 0)
	{
		for (T* x : this->vec)
		{
			x->print_details();
		}
	}
	else
	{
		cout << "there are no people!" << endl;
	}

	
}

template<class T>
inline void VecAnalyser<T>::printMax()
{
	T* tmp = this->vec.begin();
	int z = 0, count = 0;
	float sum = 0;
	vector <T*> vec2;
	try
	{
		if (!(tmp->t_seniority))
		{
			throw z;
		}
		for (T* x : this->vec)
		{
			count++;
			if (x->get_average() > sum)   // if the new is higher then all the previous
			{
				vec2.clear();       // clear the vector
				vec2.push_back(x);  // push the new worker
				sum = x->get_average();   // update the new highest sum
				continue;
			}
			else if (x->get_average() == sum) // if they equal
			{
				vec2.push_back(x);      // push the new one and continue
				continue;
			}
			else                             // the new one is lower
			{
				continue;
			}
		}
	}
	catch (int z)
	{
		for (T* x : this->vec)
		{
			count++;
			if (x->get_salary() > sum)   // if the new is higher then all the previous
			{
				vec2.clear();       // clear the vector
				vec2.push_back(x);  // push the new worker
				sum = x->get_salary();   // update the new highest sum
				continue;
			}
			else if (x->get_salary() == sum) // if they equal
			{
				vec2.push_back(x);      // push the new one and continue
				continue;
			}
			else                             // the new one is lower
			{
				continue;
			}
		}
	}

	if (count > 0)
	{
		for (T* x : this->vec2)
		{
			cout << x->print_details() << endl;
		}
	}
	else
	{
		cout << "there are no people!" << endl;
	}
	
}
