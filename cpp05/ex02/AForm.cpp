#include "AForm.hpp"

AForm::AForm() : name("default"), signedAForm(false), signGrade(150), execGrade(150) {}

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), signedAForm(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::AFormGradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::AFormGradeTooLowException();
}

AForm::AForm(AForm const &src) : name(src.name), signedAForm(src.signedAForm), signGrade(src.signGrade), execGrade(src.execGrade) {}

AForm &AForm::operator=(AForm const &src)
{
    std::cout << "AForm assignation operator called" << std::endl;
    if (this != &src)
        this->signedAForm = src.signedAForm;
    return *this;
}

AForm::~AForm() {}


int AForm::getSignGrade() const { return this->signGrade; }

int AForm::getExecGrade() const { return this->execGrade; }

std::string AForm::getName() const { return this->name; }

bool AForm::getSignedAForm() const { return this->signedAForm; }


void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw AForm::AFormGradeTooLowException();
    this->signedAForm = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->signedAForm)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->execGrade)
        throw AForm::AFormGradeTooLowException();
}


const char *AForm::AFormGradeTooHighException::what() const throw() { return "Grade is too high for the form!"; }

const char *AForm::AFormGradeTooLowException::what() const throw() { return "Grade is too low to sign/execute the form!"; }

const char *AForm::FormNotSignedException::what() const throw() { return "The form is not signed!"; }


std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form Name: " << form.getName() << "\n"
        << "Status: " << (form.getSignedAForm() ? "Signed" : "Not Signed") << "\n"
        << "Grade required to sign: " << form.getSignGrade() << "\n"
        << "Grade required to execute: " << form.getExecGrade() << "\n";
    return out;
}

