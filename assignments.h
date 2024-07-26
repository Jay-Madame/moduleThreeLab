#pragma once
#include <iostream>
#include <fstream>

class Assignment
{
private:
    std::string name;
    double gradeEarned, gradePossible;
    bool complete;

public:
    Assignment(std::string n, double gEarned, double gPossible, bool isCompleted);
    std::string getName() const;
    double getGradeEarned() const;
    bool isCompleted() const;
    double getGradePossible() const;
    friend std::ostream &operator<<(std::ostream &strm, const Assignment &obj);
};