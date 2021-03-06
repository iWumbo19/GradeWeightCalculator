#include "Assignment.h"


Assignment::Assignment(int grade, int weight, string name)
{
    Assignment::grade = grade;
    Assignment::weight = weight;
    Assignment::name = name;
}

Assignment::Assignment()
{
    Assignment::name = "";
    Assignment::grade = 0;
    Assignment::weight = 0;
}

float Assignment::get_weightedgrade()
{
    float percent = Assignment::weight / 100;
    return Assignment::grade * percent;
}

string Assignment::get_coursename()
{
    return name;
}

int Assignment::get_weight()
{
    return weight;
}

int Assignment::get_grade()
{
    return grade;
}

void Assignment::set_name(string name)
{
    Assignment::name = name;
}

void Assignment::set_grade(int grade)
{
    Assignment::grade = grade;
}

void Assignment::set_weight(int weight)
{
    Assignment::weight = weight;
}
