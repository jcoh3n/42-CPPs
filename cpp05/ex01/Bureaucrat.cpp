#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    if (grade < 1) throw BureaucratGradeTooHighException();
    if (grade > 150) throw BureaucratGradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade) { std::cout << "Bureaucrat copy constructor" << std::endl; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    std::cout << "Bureaucrat operator=" << std::endl;
    if (this == &other) return *this;
    grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}


const char *Bureaucrat::BureaucratGradeTooHighException::what() const throw() { return  "Grade trop haut pour le bureaucrate !"; }

const char *Bureaucrat::BureaucratGradeTooLowException::what() const throw() { return "Grade trop bas pour le bureaucrate !"; }

std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade()
{
    if (grade == 1) throw BureaucratGradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150) throw BureaucratGradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        bool signedForm = form.getSignedForm();
        form.beSigned(*this);
       if (!signedForm)
            std::cout << name << " signed " << form.getName() << std::endl;
        else
            std::cout << name << " tried to sign " << form.getName() << ", but it was already signed." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}