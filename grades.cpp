#include "grades.h"

std::vector<Category> Grades::getCategories() const
{
    return categories;
}
void Grades::addCategory(std::string name, double weight)
{
    Category newCategory(name);
    newCategory.changeWeightOfCategory(weight);
    categories.push_back(newCategory);
}
int Grades::howManyCompletedAssignments() const
{
    int total = 0;
    for (const auto &category : categories)
    {
        total += category.assignmentsCompleted();
    }
    return total;
}
double Grades::getCurrentGrade() const
{
    double grade;
    for (const auto &category : categories)
    {
        grade += (category.currentGrade() * category.getWeightOfCategory());
    }
    return grade;
}
int Grades::howManyAssignmentsLeft() const
{
    int total = 0;
    for (const auto &category : categories)
    {
        total += category.assignmentsLeft();
    }
    return total;
}
double Grades::getProjectedGradeForLeftovers() const
{
    double grade;
    for (const auto &category : categories)
    {
        grade += (category.potentialGrade() * category.getWeightOfCategory());
    }
    return grade;
}
double Grades::getProjectedGradeForClass() const
{
    double grade;
    for (const auto &category : categories)
    {
        grade += (category.totalGrade() * category.getWeightOfCategory());
    }
    return grade;
}
std::ostream &operator<<(std::ostream &strm, const Grades &obj)
{
    std::vector<Category> tempCategories = obj.getCategories();
    int i = 1;
    for (const auto &category : tempCategories)
    { 
        strm << "Name of Category "<< i <<" : " << category.getName() <<"\n"
        << "Total Weight: " << std::fixed << std::setprecision(2) << (100*category.getWeightOfCategory()) <<"%\n";
    }
    strm<< "\nAssingments completed: " <<obj.howManyCompletedAssignments() <<"\n"
    << "Current Grade: " << obj.getCurrentGrade() << "\n"
    << "Assignments Remaining: " << obj.howManyAssignmentsLeft() << "\n"
    << "Projected Grade on Remaining Assignments: " << obj.getProjectedGradeForLeftovers() << "\n"
    << "Predicted Grade for the class: " << obj.getProjectedGradeForClass()<<"\n";
    return strm;
}