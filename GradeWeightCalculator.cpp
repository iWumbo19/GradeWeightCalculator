// GradeWeightCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Course.h"

Course course;
bool runprogram = true;

void clear()
{
#if defined _WIN32
	system("cls");
	//clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
	//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
	system("clear");
#endif
}

void main_banner()
{
	puts("What would you like to do? (Type number)");
	puts("1. See current assignment types, grades, and weights");
	puts("2. Add an assignment type");
	puts("3. Remove an assignment type");
	puts("4. Edit an assignment type");
	puts("5. Check assignment weight total");
	puts("6. Calculate weighted grades based on current assignment types");
	puts("0. Terminate program");
}

void initialize()
{
	puts("Welcome to the Grade Calculator");
}

int ask_for_selection()
{
	int i;
	while (true)
	{
		cin >> i;
		if (!cin)
		{
			cout << "Not recognized. Please enter the number of the action you wish to take" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}
	return i;
}

void print_assignments()
{
	string sp = "    ";
	cout << "Name    Grade   Weight" << endl;
	for (Assignment assignment : course.get_assignment_vector())
	{
		cout << assignment.get_coursename() << sp << assignment.get_grade() << sp << sp << assignment.get_weight() << endl;
	}
}

void add_assignment()
{
	string name;
	int grade;
	int weight;

	puts("What is the name of the course:");
	cin >> name;
	
	while (true)
	{
		puts("What is your current grade:");
		cin >> grade;
		if (!cin)
		{
			cout << "Not recognized. Please enter a number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}

	while (true)
	{
		puts("What is the weight of those assignments: ('25' = 25%)");
		cin >> weight;
		if (!cin)
		{
			cout << "Not recognized. Please enter a number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}

	course.add_assignment(grade, weight, name);
	cout << name << " was added to assignments" << endl;
}

void remove_assignment()
{
	string name;
	puts("Which assignment type do you wish to remove:");
	cin >> name;
	for (Assignment assignment : course.get_assignment_vector())
	{
		if (assignment.get_coursename() == name) { course.remove_assignment(name); return; }
	}
	puts("No course with that name found (Case sensitive)");
}

void edit_assignment()
{
	string name;
	int grade;
	int weight;

	puts("What is the name of the course you wish to edit");
	cin >> name;

	while (true)
	{
		puts("What is your current grade:");
		cin >> grade;
		if (!cin)
		{
			cout << "Not recognized. Please enter a number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}

	while (true)
	{
		puts("What is the weight of those assignments: ('25' = 25%)");
		cin >> weight;
		if (!cin)
		{
			cout << "Not recognized. Please enter a number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}

	course.edit_assignment(grade, weight, name);
	cout << name << " was edited successfully" << endl;

}

void check_assignment_weight()
{
	if (!course.assingments_equal_hundred()) { puts("Current weight's don't equal 100. Scores will not be processed"); }
	else { puts("Weights equal 100%. Ready to Process!"); }
}

void calculate_weighted_grade()
{
		cout << "You have a " << course.get_total_weighted_grade() << " in this course" << endl;
}

void main_menu()
{	
	while (runprogram)
	{
		main_banner();
		int selection = ask_for_selection();
		clear();
		switch (selection)
		{
		case 1:
			print_assignments();
			break;
		case 2:
			add_assignment();
			break;
		case 3:
			remove_assignment();
			break;
		case 4:
			edit_assignment();
			break;
		case 5:
			check_assignment_weight();
			break;
		case 6:
			calculate_weighted_grade();
			break;
		case 0:
			runprogram = false;
			break;
		default:
			puts("Not a recognized selection");
			break;
		}
	}
}

int main()
{
	initialize();
	main_menu();
	return 0;
}



