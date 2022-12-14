#ifndef CPP_ARCADE_ERRORS_HPP
#define CPP_ARCADE_ERRORS_HPP

#include <string>
class Error : public std::exception 
{
    private:
        std::string	_message;
    public:
        Error(std::string const &message) : _message(message) 
        {};
        virtual ~Error() throw() 
        {};
        const char *what() const throw() 
        { 
            return this->_message.c_str(); 
        };
};

class DynLoaderError : public Error
{
    public:
        DynLoaderError(std::string const &message) : Error(message) 
        {};
        virtual ~DynLoaderError() throw() 
        {};
};


#endif
