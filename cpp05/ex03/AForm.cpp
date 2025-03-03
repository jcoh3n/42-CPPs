#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), signedAForm(false), signGrade(150), execGrade(150) { std::cout << "AForm default constructor" << std::endl; }

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), signedAForm(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::AFormGradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::AFormGradeTooLowException();
    std::cout << "AForm constructor with parameters" << std::endl;
}

AForm::AForm(AForm const &src) : name(src.name), signedAForm(src.signedAForm), signGrade(src.signGrade), execGrade(src.execGrade) {}

AForm &AForm::operator=(AForm const &src)
{
    std::cout << "AForm assignation operator called" << std::endl;
    if (this != &src)
        this->signedAForm = src.signedAForm;
    return *this;
}

AForm::~AForm() { std::cout << "AForm destructor called" << std::endl; }


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


const char *AForm::AFormGradeTooHighException::what() const throw() { return "Grade trop haut pour le form !"; }

const char *AForm::AFormGradeTooLowException::what() const throw() { return "Grade trop bas pour signer/exécuter le form !"; }

const char *AForm::FormNotSignedException::what() const throw() { return "Form n'est pas signé !"; }

const char *AForm::EmptyTargetException::what() const throw() { return "Target cannot be empty"; }

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
    out << AForm.getName() << ", AForm grade required to sign " << AForm.getSignGrade()
        << ", grade required to execute " << AForm.getExecGrade()
        << ", is signed: " << (AForm.getSignedAForm() ? "yes" : "no");
    return out;
}
