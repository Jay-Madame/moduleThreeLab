#include "grades.h"
#include "categories.h"
#include <iomanip>
#include <vector>

std::vector<Category> Grades::getCategories() const {
    return categories;
}

void Grades::addCategory(std::string name, double weight) {
    Category newCategory(name);
    newCategory.changeWeightOfCategory(weight);
    categories.push_back(newCategory);
}

int Grades::howManyCompletedAssignments() const {
    int total = 0;
    for (const auto &category : categories) {
        total += category.assignmentsCompleted();
    }
    return total;
}

double Grades::getCurrentGrade() const {
    double totalWeightedGrade = 0.0;
    double totalWeight = 0.0;
    for (const auto &category : categories) {
        double categoryGrade = category.currentGrade();
        double weight = category.getWeightOfCategory();
        totalWeightedGrade += categoryGrade * weight;
        totalWeight += weight;
    }
    return (totalWeight > 0) ? (totalWeightedGrade / totalWeight) : 0.0;
}

int Grades::howManyAssignmentsLeft() const {
    int total = 0;
    for (const auto &category : categories) {
        total += category.assignmentsLeft();
    }
    return total;
}

double Grades::getProjectedGradeForLeftovers() const {
    double totalWeightedPotential = 0.0;
    double totalWeight = 0.0;
    for (const auto &category : categories) {
        double potentialGrade = category.potentialGrade();
        double weight = category.getWeightOfCategory();
        totalWeightedPotential += potentialGrade * weight;
        totalWeight += weight;
    }
    return (totalWeight > 0) ? (totalWeightedPotential / totalWeight) : 0.0;
}

double Grades::getProjectedGradeForClass() const {
    double totalWeightedGrade = 0.0;
    for (const auto &category : categories) {
        totalWeightedGrade += category.totalGrade() * category.getWeightOfCategory();
    }
    return totalWeightedGrade;
}

std::ostream &operator<<(std::ostream &strm, const Grades &obj) {
    const auto &categories = obj.getCategories();
    int i = 1;
    for (const auto &category : categories) {
        strm << "Name of Category " << i++ << ": " << category.getName() << "\n"
             << "Total Weight: " << std::fixed << std::setprecision(2)
             << (100 * category.getWeightOfCategory()) << "%\n";
    }
    strm << "\nAssignments completed: " << obj.howManyCompletedAssignments() << "\n"
         << "Current Grade: " << std::fixed << std::setprecision(2) << obj.getCurrentGrade() << "\n"
         << "Assignments Remaining: " << obj.howManyAssignmentsLeft() << "\n"
         << "Projected Grade on Remaining Assignments: " << std::fixed << std::setprecision(2)
         << obj.getProjectedGradeForLeftovers() << "\n"
         << "Predicted Grade for the class: " << std::fixed << std::setprecision(2)
         << obj.getProjectedGradeForClass() << "\n";
    return strm;
}