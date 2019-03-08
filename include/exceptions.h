/**
 * Errors handling through exceptions.
 */
#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <stdexcept>
#include <string>

/** Extends a standard exception with SDL error messages.
 */
class SDLException : public std::exception {
protected:
	std::string message; // <* The message of the exception.
public:
	/** Initializes the exception with a message.
	 * \param msg The message of the exception.
	 */
	SDLException(const char * msg);

	/** Initializes the exception with a message.
	 * \param msg The message of the exception.
	 */
	SDLException(const std::string msg);

	/** Appends the SDL error to the message and returns it.
	 * \return The final message of the exception.
	 */
	virtual const char * what() const throw();
};

/** Prints a FileSystem error to the user.
 */
class FileSystemError : public std::runtime_error {
protected:
	std::string path;
public:
	/** Initializes the exception with a message and a path.
	 * \param msg The message of the exception.
	 * \param path The path of the FileSystem that caused the exception.
	 */
	FileSystemError(const char * msg, const char * path);

	/** Initializes the exception with a message and a path.
	 * \param msg The message of the exception.
	 * \param path The path of the FileSystem that caused the exception.
	 */
	FileSystemError(const std::string msg, const char * path);

	/** Initializes the exception with a message and a path.
	 * \param msg The message of the exception.
	 * \param path The path of the FileSystem that caused the exception.
	 */
	FileSystemError(const char * msg, const std::string path);

	/** Initializes the exception with a message and a path.
	 * \param msg The message of the exception.
	 * \param path The path of the FileSystem that caused the exception.
	 */
	FileSystemError(const std::string msg, const std::string path);

	/** Appends the path of the item that caused the exception and returns it.
	 * \return The message with the path appended.
	 */
	virtual const char * what() const throw();
};

/** Exception related to SDL_image.
 */
class SDLImageException : public std::exception {
protected:
	std::string message; // <* The message to print,
public:
	/** Initializes the exception with a message.
	 * \param msg The message of the exception.
	 */
	SDLImageException(const char * msg);

	/** Initializes the exception with a message.
	 * \param msg The message of the exception.
	 */
	SDLImageException(const std::string msg);

	/** Appends the SDL_image error to the message of the exception.\
	 * \return The message of the exception with the SDL_image error.
	 */
	virtual const char * what() const throw();
};

/** Exception related to SDL_ttf.
 */
class SDLTTFException : public SDLException {
public:
	/** Initializes the exception with a message.
	 * \param msg The message of the exception.
	 */
	SDLTTFException(const char * msg);

	/** Initializes the exception with a message.
	 * \param msg The message of the exception.
	 */
	SDLTTFException(const std::string msg);

	/** Appends the SDL_ttf error to the message of the exception.\
	 * \return The message of the exception with the SDL_ttf error.
	 */
	virtual const char * what() const throw();
};
#endif
