#include "assignments.h"
#include "categories.h"
#include "categories.cpp"
#include "assignments.cpp"
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>

void testCategory();

int main()
{
    testCategory();
}

void testCategory()
{
    std::string name, ans;
    double pEarned, pPoss;
    bool comp;
    Category newCategory("Math");
    newCategory.addAssignment("exampleAssignment.txt");
    std::cout << "Name of assignment: ";
    std::cin >> name;
    std::cout << "Grade earned: ";
    std::cin >> pEarned;
    std::cout << "Grade possible: ";
    std::cin >> pPoss;
    std::cout << "Is it complete? (y/n): ";
    std::cin >> ans;
    if (ans == "y")
    {
        comp = true;
    }
    else
    {
        comp = false;
    }
    Assignment newAssignment(name, pEarned, pPoss, comp);
    newCategory.addAssignment(newAssignment);
    std::vector<Assignment> tempAssignments = newCategory.getAssignments();
    std::cout << newCategory;
}