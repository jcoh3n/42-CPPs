#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
private:
    std::string const name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    
    void incrementGrade();
    void decrementGrade();
    
    void signForm(AForm &form);
    void executeForm(AForm const &form);
    
    class BureaucratGradeTooHighException : public std::exception 
    {
    public:
        virtual const char *what() const throw();
    };
    
    class BureaucratGradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif