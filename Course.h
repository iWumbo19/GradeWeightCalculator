#pragma once
#include <vector>
#include "Assignment.h"

class Course
{
	vector<Assignment> assignments;

public:
	int get_total_weighted_grade();
	vector<string> get_assignment_types();
	Assignment get_assignment_details(string name);
	bool edit_assignment(int grade, int weight, string name);
	void add_assignment(int grade, int weight, string name);
	void remove_assignment(string name);
	bool assingments_equal_hundred();
	vector<Assignment> get_assignment_vector();


};

