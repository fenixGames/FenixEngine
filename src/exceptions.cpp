#include <stdexcept>

#include <exceptions.hpp>
#include <os.hpp>

SDLException::SDLException(const char * msg) {
	message = msg;
}

SDLException::SDLException(const std::string msg) :
	SDLException(msg.c_str()) {
}

const char *
SDLException::what() const throw()
{
	std::string msg = message + SDL_GetError();
	return msg.c_str();
}

FileSystemError::FileSystemError(const char * msg, const char * p):
	std::runtime_error(msg)
{
	path = p;
}

FileSystemError::FileSystemError(const char * msg, const std::string p) : 
	FileSystemError(msg, p.c_str()) 
{
}

FileSystemError::FileSystemError(const std::string msg, const char * path) :
	FileSystemError(msg.c_str(), path)
{
}

FileSystemError::FileSystemError(const std::string msg, const std::string path) :
	FileSystemError(msg.c_str(), path.c_str())
{
}

const char *
FileSystemError::what() const throw()
{
	std::string msg = std::runtime_error::what();
	msg += " " + path;
	return msg.c_str();
}

SDLImageException::SDLImageException(const char * msg) {
	message = msg;
}

SDLImageException::SDLImageException(const std::string msg) :
	SDLImageException(msg.c_str())
{
}

const char *
SDLImageException::what() const throw()
{
	std::string msg = message + IMG_GetError();
	return msg.c_str();
}

SDLTTFException::SDLTTFException(const char * msg) :
	SDLException(msg) {
}

SDLTTFException::SDLTTFException(const std::string msg):
	SDLException(msg){
}

const char *
SDLTTFException::what() const throw() {
	std::string msg = message + TTF_GetError();
	return msg.c_str();
}
