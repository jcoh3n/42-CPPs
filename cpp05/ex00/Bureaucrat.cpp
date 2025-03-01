#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) { std::cout << "Bureaucrat default constructor" << std::endl; }

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Bureaucrat constructor with parameters" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade) { std::cout << "Bureaucrat copy constructor" << std::endl; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    std::cout << "Bureaucrat operator=" << std::endl;
    if (this == &other) return *this;
    grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor" << std::endl; }

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade trop haut"; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade trop bas"; }

void Bureaucrat::incrementGrade()
{
    if (grade == 1) throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150) throw GradeTooLowException();
    grade++;
}

std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}