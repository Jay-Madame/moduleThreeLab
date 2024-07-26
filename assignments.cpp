#include "assignments.h"
#include <iostream>
#include <fstream>

Assignment::Assignment(std::string n, double gEarned, double gPossible, bool isCompleted) {}
Assignment::Assignment(const std::string &filename)
{
    std::ifstream file(filename);

    if (file.is_open())
    {
        std::string nm;
        double gEarned, gPossible;
        bool isCom;
        while (file >> nm >> gEarned >> gPossible >> isCom)
        {
            Assignment(nm, gEarned, gPossible, isCom);
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}
std::string Assignment::getName() const
{
    return name;
}
double Assignment::getGradeEarned() const
{
    return gradeEarned;
}
bool Assignment::isCompleted() const
{
    return complete;
}
double Assignment::getGradePossible() const
{
    return gradePossible;
}

std::ostream &operator<<(std::ostream &strm, const Assignment &obj)
{
    strm << "Assignment name " << obj.getName() << std::endl;
    return strm;
}