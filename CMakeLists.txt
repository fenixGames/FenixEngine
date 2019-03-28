CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
SET(PROJECT_NAME FenixEngine)

PROJECT(${PROJECT_NAME} VERSION 0.0.1)

SET(CMAKE_CXX_STANDARD 11)
SET(
	SOURCES 
		src/window.cpp
		src/exceptions.cpp
		src/scene.cpp
		src/viewport.cpp
		src/events/event_handler.cpp
		src/nodes/node.cpp
		src/physics/geometry.cpp
		src/graphics/sprite.cpp
		src/graphics/graphic.cpp
)

SET(
	INCLUDE_FILES
		include/${PROJECT_NAME}.h
		include/exceptions.h
		include/os.h
		include/scene.h
		include/viewport.h
		include/window.h
		include/event_handler.h
		include/graphic.h
		include/sprite.h
		include/text.h
		include/draggable_node.h
		include/node.h
		include/geometry.h
)
IF (NOT PREFIX)
	SET(PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/build)
ENDIF (NOT PREFIX)

CONFIGURE_FILE(
	"${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}.h.in"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}.h"
	NEWLINE_STYLE "UNIX")

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/include")
IF (WIN32)
	INCLUDE(CMake/WIN32.cmake)
ELSE (WIN32)
	INCLUDE(CMake/Unix_Linux.cmake)
ENDIF(WIN32)

SET(INSTALL_LIBDIR "${PREFIX}/lib/")
SET(INSTALL_INCLUDEDIR "${PREFIX}/include/${PROJECT_NAME}")


INSTALL(TARGETS ${PROJECT_NAME}_STATIC ${PROJECT_NAME}_SHARED 
	LIBRARY		DESTINATION "${INSTALL_LIBDIR}"
	ARCHIVE		DESTINATION "${INSTALL_LIBDIR}"
	PUBLIC_HEADER	DESTINATION "${INSTALL_INCLUDEDIR}"
)

