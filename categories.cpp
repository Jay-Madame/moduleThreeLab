#include "categories.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

// Constructor
Category::Category(std::string name) : nameOfCategory(name) {}

// Adding assignments
void Category::addAssignment(Assignment newAssignment)
{
    assignments.push_back(newAssignment);
}

void Category::addAssignment(const std::string &filename)
{
    std::ifstream file(filename);

    if (file.is_open())
    {
        std::string nm;
        double gEarned, gPossible;
        bool isCom;

        while (file >> nm >> gEarned >> gPossible >> isCom)
        {
            Assignment newAssignment(nm, gEarned, gPossible, isCom);
            assignments.push_back(newAssignment);
        }

        file.close();
    }
    else
    {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

// Weight of category
void Category::changeWeightOfCategory(double numCategory)
{
    weightOfCategory = numCategory;
}

double Category::getWeightOfCategory() const
{
    return weightOfCategory;
}

// Assignments
int Category::assignmentsCompleted() const
{
    int completed = 0; // Initialize to 0
    for (int i = 0; i < assignments.size(); i++)
    {
        if (assignments[i].isCompleted())
        {
            completed++;
        }
    }
    return completed;
}

int Category::assignmentsLeft() const
{
    int left = assignments.size() - assignmentsCompleted();
    return left;
}

std::vector<Assignment> Category::unfinishedAssignments() const
{
    std::vector<Assignment> unFinAssignments;
    for (int i = 0; i < assignments.size(); i++)
    {
        if (!assignments[i].isCompleted())
        {
            unFinAssignments.push_back(assignments[i]);
        }
    }
    return unFinAssignments;
}

// Grades
double Category::totalPoints() const
{
    double pointsPossible = 0.0;
    for (const auto &assignment : assignments)
    {
        pointsPossible += assignment.getGradePossible();
    }
    return pointsPossible;
}

double Category::totalGrade() const
{
    double gradeEarned = 0.0;
    double totalPoints = 0.0;

    for (const auto &assignment : assignments)
    {
        gradeEarned += assignment.getGradeEarned();
        totalPoints += assignment.getGradePossible();
    }
    return (totalPoints > 0) ? ((gradeEarned / totalPoints) * 100) : 0;
}

double Category::currentGrade() const
{
    double gradeEarned = 0.0;
    double totalPoints = 0.0;
    for (const auto &assignment : assignments)
    {
        if (assignment.isCompleted())
        {
            gradeEarned += assignment.getGradeEarned();
            totalPoints += assignment.getGradePossible();
        }
    }
    return (totalPoints > 0) ? ((gradeEarned / totalPoints) * 100) : 0;
}

double Category::potentialGrade() const
{
    double gradeEarned = 0.0;
    double totalPoints = 0.0;
    for (const auto &assignment : assignments)
    {
        if (!assignment.isCompleted())
        {
            gradeEarned += assignment.getGradeEarned();
            totalPoints += assignment.getGradePossible();
        }
    }
    return (totalPoints > 0) ? ((gradeEarned / totalPoints) * 100) : 0;
}

// Name of category
std::string Category::getName() const
{
    return nameOfCategory;
}

// Ostream overload
std::vector<Assignment> Category::getAssignments() const
{
    return assignments;
}

std::ostream &operator<<(std::ostream &strm, const Category &obj)
{
    std::vector<Assignment> allAssignments = obj.getAssignments();
    std::vector<Assignment> unFinishedAssignmnts = obj.unfinishedAssignments();
    // actual printing
    strm << "Name of Category: " << obj.getName() << "\n";
    for (int i = 0; i < allAssignments.size(); i++)
    {
        Assignment tempValue = allAssignments[i];
        strm << (i + 1) << ". "
             << tempValue;
        if (!(tempValue.isCompleted()))
        {
            strm << "\t-\n";
        }
        else
        {
            strm << "\t" << std::fixed << std::setprecision(2) << ((tempValue.getGradeEarned() / tempValue.getGradePossible()) * 100)
                 << "% \n";
        }
    }
    strm << "Total points: " << obj.totalPoints() << "\n\n"
         << "Unfinished assignments (" << std::to_string(obj.assignmentsLeft()) << ") :\n";
    for (int i = 0; i < unFinishedAssignmnts.size(); i++)
    {
        strm << (i + 1) << ". " << unFinishedAssignmnts[i] << "\n";
    }
    strm << "Expected Score on unfinished assignments: " << std::fixed << std::setprecision(2) << (obj.potentialGrade()) << "%\n"
         << "Predicted Final Category Grade: " << std::fixed << std::setprecision(2) << obj.totalGrade() << "%\n";
    return strm;
}
