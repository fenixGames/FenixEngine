CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
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
		include/exceptions.h
		include/os.h
		include/scene.h
		include/viewport.h
		include/window.h
		include/events/event_handler.h
		include/graphics/graphic.h
		include/graphics/sprite.h
		include/graphics/text.h
		include/nodes/draggable_node.h
		include/nodes/node.h
		include/physics/geometry.h
)

IF (NOT PREFIX)
	SET(PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/build)
ENDIF (NOT PREFIX)

CONFIGURE_FILE(
	"${CMAKE_CURRENT_SOURCE_DIR}/include/cmake_params.h.in"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/cmake_params.h"
	NEWLINE_STYLE "UNIX")

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/include")
IF (WIN32)
	SET(SYSTEM_LIB_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libSDL2")
	INCLUDE_DIRECTORIES("C:/SDL2/include" "C:/SDL2-Image/include" "C:/SDL2_ttf/include")
	SET(DLL_INSTALLED_LIBS 
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/SDL2.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/SDL2_image.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/SDL2_ttf.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/libjpeg-9.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/libpng16-16.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/libtiff-5.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/libfreetype-6.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/zlib1.dll"
	)
ELSE (WIN32)
	SET(DLL_INSTALLED_LIBS "")
	SET(SYSTEM_LIB_PATHS "/lib" "/usr/lib" "/usr/local/lib")
	INCLUDE_DIRECTORIES("/usr/include" "/usr/local/include" "/usr/include/SDL2" "/usr/local/include/SDL2")

ENDIF(WIN32)

FIND_LIBRARY(SDL2_LIBRARY SDL2 PATHS ${SYSTEM_LIB_PATHS})
FIND_LIBRARY(SDL2_MAIN_LIBRARY SDL2main PATHS ${SYSTEM_LIB_PATHS})
FIND_LIBRARY(SDL2_IMAGE_LIBRARY SDL2_image PATHS ${SYSTEM_LIB_PATHS})
FIND_LIBRARY(SDL2_TTF_LIBRARY SDL2_ttf PATHS ${SYSTEM_LIB_PATHS})

SET(INSTALL_LIBDIR "${PREFIX}/lib")
SET(INSTALL_INCLUDEDIR "${PREFIX}/include")

CONFIGURE_FILE(${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)

ADD_LIBRARY(${PROJECT_NAME} ${SOURCES})

SET_TARGET_PROPERTIES(${PROJECT_NAME}
	PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION 0
		PUBLIC_HEADER "${INCLUDE_FILES}"
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARY})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_MAIN_LIBRARY})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARY})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_TTF_LIBRARY})

INSTALL(TARGETS ${PROJECT_NAME}
	LIBRARY		DESTINATION "${INSTALL_LIBDIR}"
	ARCHIVE		DESTINATION "${INSTALL_LIBDIR}"
	PUBLIC_HEADER	DESTINATION "${INSTALL_INCLUDEDIR}"
)
