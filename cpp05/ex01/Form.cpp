#include "Form.hpp"

Form::Form() : name("default"), signedForm(false), signGrade(150), execGrade(150) { std::cout << "Form default constructor" << std::endl; }

Form::Form(std::string name, int signGrade, int execGrade) : name(name), signedForm(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::FormGradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::FormGradeTooLowException();
    std::cout << "Form constructor with parameters" << std::endl;
}

Form::Form(Form const &src) : name(src.name), signedForm(src.signedForm), signGrade(src.signGrade), execGrade(src.execGrade) {}

Form &Form::operator=(Form const &src)
{
    std::cout << "Form assignation operator called" << std::endl;
    if (this != &src)
        this->signedForm = src.signedForm;
    return *this;
}

Form::~Form() { std::cout << "Form destructor called" << std::endl; }


int Form::getSignGrade() const { return this->signGrade; }

int Form::getExecGrade() const { return this->execGrade; }

std::string Form::getName() const { return this->name; }

bool Form::getSignedForm() const { return this->signedForm; }


void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw Form::FormGradeTooLowException();
    this->signedForm = true;
}


const char *Form::FormGradeTooHighException::what() const throw() { return  "Grade trop haut pour le formulaire !"; }

const char *Form::FormGradeTooLowException::what() const throw() { return "Grade trop bas pour signer/exécuter le formulaire !"; }


std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << ", form grade required to sign " << form.getSignGrade()
        << ", grade required to execute " << form.getExecGrade()
        << ", is signed: " << (form.getSignedForm() ? "yes" : "no");
    return out;
}

