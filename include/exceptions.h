/**
 * Errors handling through exceptions.
 */
#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <stdexcept>
#include <string>

class SDLException : public std::exception {
protected:
	std::string message;
public:
	SDLException(const char * msg);
	SDLException(const std::string);
	virtual const char * what() const throw();
};

class FileSystemError : public std::runtime_error {
protected:
	std::string path;
public:
	FileSystemError(const char *, const char *);
	FileSystemError(const std::string, const char *);
	FileSystemError(const char *, const std::string);
	FileSystemError(const std::string, const std::string);

	virtual const char * what() const throw();
};

class SDLImageException : public std::exception {
protected:
	std::string message;
public:
	SDLImageException(const char *);
	SDLImageException(const std::string);

	virtual const char * what() const throw();
};

class SDLTTFException : public SDLException {
public:
	SDLTTFException(const char *);
	SDLTTFException(const std::string);

	virtual const char * what() const throw();
};
#endif