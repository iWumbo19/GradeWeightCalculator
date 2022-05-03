#include "Course.h"

int Course::get_total_weighted_grade()
{
	int output = 0;
	for (Assignment assignment : assignments)
	{
		output += assignment.get_weightedgrade();
	}
	return output;
}

vector<string> Course::get_assignment_types()
{
	vector<string> output;
	for (Assignment assignment : assignments)
	{
		output.push_back(assignment.get_coursename());
	}
	return vector<string>();
}

Assignment Course::get_assignment_details(string name)
{
	for (Assignment assignment : assignments)
	{
		if (assignment.get_coursename() == name) { return assignment; }
	}
	return Assignment();
}

bool Course::edit_assignment(int grade, int weight, string name)
{
	for (Assignment assignment : assignments)
	{
		if (assignment.get_coursename() == name) 
		{
			assignment.set_grade(grade); 
			assignment.set_weight(weight); 
			return true;
		}
	}
	return false;
}

bool Course::edit_assignment(int edit, string name, bool grade)
{
	for (Assignment assignment : assignments)
	{
		if (assignment.get_coursename() == name)
		{
			if (grade) { assignment.set_grade(edit); return true; }
			else { assignment.set_weight(edit); return true; }
		}
	}
	return false;
}

void Course::add_assignment(int grade, int weight, string name)
{
	assignments.push_back(Assignment(grade, weight, name));
}

void Course::remove_assignment(string name)
{
	for (int i = 0; i < assignments.size(); i++)
	{
		if (assignments[i].get_coursename() == name) { assignments.erase(assignments.begin() + i); }
	}
}

bool Course::assingments_equal_hundred()
{
	int check = 0;
	for (Assignment assignment : assignments)
	{
		check += assignment.get_weight();
	}
	if (check == 100) { return true; }
	else { return false; }
}

vector<Assignment> Course::get_assignment_vector()
{
	return assignments;
}
