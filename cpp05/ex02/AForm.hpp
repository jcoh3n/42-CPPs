#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
private:
    std::string const name;
    bool signedAForm;
    int const signGrade;
    int const execGrade;
public:
    AForm();
    AForm(std::string name, int signGrade, int execGrade);
    AForm(AForm const &src);
    AForm &operator=(AForm const &src);
    virtual ~AForm();
    
    std::string getName() const;
    bool getSignedAForm() const;
    int getSignGrade() const;
    int getExecGrade() const;
    
    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const;

    class AFormGradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class AFormGradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif