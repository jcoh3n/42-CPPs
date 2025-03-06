#include "Form.hpp"


Form::Form(std::string name, int signGrade, int execGrade) : name(name), signedForm(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::FormGradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::FormGradeTooLowException();
}

Form::Form(Form const &src) : name(src.name), signedForm(src.signedForm), signGrade(src.signGrade), execGrade(src.execGrade) {}

Form &Form::operator=(Form const &src)
{
    std::cout << "Form assignation operator called" << std::endl;
    if (this != &src)
        this->signedForm = src.signedForm;
    return *this;
}

Form::~Form() {}


int Form::getSignGrade() const { return this->signGrade; }

int Form::getExecGrade() const { return this->execGrade; }

std::string Form::getName() const { return this->name; }

bool Form::getSignedForm() const { return this->signedForm; }


void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (this->signedForm)
        return;
    if (bureaucrat.getGrade() > this->signGrade)
        throw Form::FormGradeTooLowException();
    this->signedForm = true;
}


const char *Form::FormGradeTooHighException::what() const throw() { return  "Grade too high for the form!"; }

const char *Form::FormGradeTooLowException::what() const throw() { return "Grade too low to sign/execute the form!"; }


std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form Name: " << form.getName() << "\n"
        << "Status: " << (form.getSignedForm() ? "Signed" : "Not Signed") << "\n"
        << "Grade required to sign: " << form.getSignGrade() << "\n"
        << "Grade required to execute: " << form.getExecGrade() << "\n";
    return out;
}

