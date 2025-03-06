#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
private:
    std::string const name;
    bool signedForm;
    int const signGrade;
    int const execGrade;
public:
    Form(std::string name, int signGrade, int execGrade);
    Form(Form const &src);
    Form &operator=(Form const &src);
    ~Form();
    
    std::string getName() const;
    bool getSignedForm() const;
    int getSignGrade() const;
    int getExecGrade() const;
    
    void beSigned(const Bureaucrat &bureaucrat);

    class FormGradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class FormGradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif