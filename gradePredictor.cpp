#include "assignments.h"
#include "categories.h"
#include "categories.cpp"
#include "assignments.cpp"
#include "grades.h"
#include "grades.cpp"
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>

void testCategory();
void testGrades();

int main()
{
    // testCategory();
    testGrades();
}

void testCategory()
{
    std::string name, ans;
    double pEarned, pPoss;
    bool comp, valid;
    std::cout << "Please provide a name for this assignment: ";
    std::cin >> name;
    Category newCategory(name);
    name = "";
    valid = true;
    while (valid)
    {
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
        ans = "";
        std::cout << "Would you like to add another assignment? (y/n)";
        std::cin >> ans;
        if (ans == "y")
        {
            valid = true;
        }
        else
        {
            valid = false;
        }
    }
    std::vector<Assignment> tempAssignments = newCategory.getAssignments();
    std::cout << "\n"
              << newCategory;
}

void testGrades()
{
    std::string ans, name;
    bool comp, valid, validOut;
    double pPoss, pEarned, weightOfCategory;
    int index = 0;
    Grades math;
    std::vector<Category> mathSem1;
    math.addCategory("Homework", 30);
    mathSem1 = math.getCategories();
    mathSem1[0].addAssignment("exampleAssignment.txt");
    Assignment newAssignment("14.1", 89.00, 100, 0);
    mathSem1[0].addAssignment(newAssignment);
    valid = true;
    validOut = true;
    while (validOut)
    {
        index++;
        std::cout << "Enter a category name: ";
        std::cin >> ans;
        std::cout << "Enter category weight as a whole number (40% -> 40): ";
        std::cin >> weightOfCategory;
        math.addCategory(ans, weightOfCategory);
        mathSem1 = math.getCategories();
        while (valid)
        {
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
            mathSem1[index].addAssignment(newAssignment);
            ans = "";
            std::cout << "Would you like to add another assignment? (y/n) ";
            std::cin >> ans;
            if (ans == "y")
            {
                valid = true;
            }
            else
            {
                valid = false;
            }
        }
        std::cout << "Would you like to add another category? (y/n) ";
        std::cin >> ans;
        if (ans == "y")
        {
            validOut = true;
        }
        else
        {
            validOut = false;
        }
        std::cout << "\n"
                  << math;
    }
}