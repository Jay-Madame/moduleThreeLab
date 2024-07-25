#pragma once
#include <iostream>
#include <fstream>

class Assignment
{
private:
    std::string name;
    double gradeEarned, gradePossible;
    bool completed;

public:
    Assignment(std::string n, double gEarned, double gPossible, bool isCompleted);
    Assignment(const std::string &filename);
    std::string getName() const;
    double getGradeEarned() const;
    bool isCompleted() const;
    double getGradePossible() const;
};