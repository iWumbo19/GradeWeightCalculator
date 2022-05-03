#include <string>
#include <iostream>
using namespace std;

class Assignment
{
	string name;
	unsigned short grade;
	unsigned short weight;

public:
	Assignment(int grade, int weight, string name);
	Assignment();

	int get_weightedgrade();
	string get_coursename();
	int get_weight();
	int get_grade();
	void set_name(string name);
	void set_grade(int grade);
	void set_weight(int weight);
};
