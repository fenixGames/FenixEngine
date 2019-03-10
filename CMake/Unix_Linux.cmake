

SET(DLL_INSTALLED_LIBS "")
	SET(SYSTEM_LIB_PATHS "/lib" "/usr/lib" "/usr/local/lib")
	INCLUDE_DIRECTORIES("/usr/include" "/usr/local/include" "/usr/include/SDL2" "/usr/local/include/SDL2")

CONFIGURE_FILE(${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)


ADD_LIBRARY(objlib OBJECT ${SOURCES})
ADD_LIBRARY(${PROJECT_NAME}_SHARED SHARED $<TARGET_OBJECTS:objlib>)
ADD_LIBRARY(${PROJECT_NAME}_STATIC STATIC $<TARGET_OBJECTS:objlib>)
SET_PROPERTY(TARGET objlib PROPERTY POSITION_INDEPENDENT_CODE 1)

SET_TARGET_PROPERTIES(${PROJECT_NAME}_SHARED
	PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION 0
		PUBLIC_HEADER "${INCLUDE_FILES}"
		OUTPUT_NAME ${PROJECT_NAME}
)
SET_TARGET_PROPERTIES(${PROJECT_NAME}_STATIC
	PROPERTIES
		OUTPUT_NAME ${PROJECT_NAME}
)


FIND_LIBRARY(SDL2_LIBRARY SDL2 PATHS ${SYSTEM_LIB_PATHS})
FIND_LIBRARY(SDL2_MAIN_LIBRARY SDL2main PATHS ${SYSTEM_LIB_PATHS})
FIND_LIBRARY(SDL2_IMAGE_LIBRARY SDL2_image PATHS ${SYSTEM_LIB_PATHS})
FIND_LIBRARY(SDL2_TTF_LIBRARY SDL2_ttf PATHS ${SYSTEM_LIB_PATHS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}_SHARED ${SDL2_LIBRARY})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}_SHARED ${SDL2_MAIN_LIBRARY})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}_SHARED ${SDL2_IMAGE_LIBRARY})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}_SHARED ${SDL2_TTF_LIBRARY})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}_STATIC ${SDL2_LIBRARY})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}_STATIC ${SDL2_MAIN_LIBRARY})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}_STATIC ${SDL2_IMAGE_LIBRARY})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}_STATIC ${SDL2_TTF_LIBRARY})
