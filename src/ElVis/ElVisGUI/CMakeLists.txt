#SET(Project "ElVis")

# IF( NOT QT4_FOUND )
    # FIND_PACKAGE(Qt4)
# ENDIF() 
# IF( QT4_FOUND )
    # include(${QT_USE_FILE})
# ENDIF()

SET(INTERFACE_APPLICATION_SRCS
    MainWindow.cpp
)

SET(INTERFACE_APPLICATION_MOC_SRCS
	MainWindow.h
)

SET(INTERFACE_APPLICATION_UI_SRCS
	MainWindow.ui
)

##################################################
# Non-UI Code
##################################################
SET(INTERFACE_APPLICATION_NO_MOC_SRCS
)

##################################################
# Generate header out of UI code
##################################################

QT4_WRAP_UI(INTERFACE_APPLICATION_QT_UI_SRCS ${INTERFACE_APPLICATION_UI_SRCS})


##################################################
# Wrap QT code to expand all the moc code
##################################################

QT4_WRAP_CPP(INTERFACE_APPLICATION_QT_MOC_SRCS ${INTERFACE_APPLICATION_MOC_SRCS})

##################################################
# Ensure that we can find the files generated
# by the moc and ui builder
##################################################

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

SOURCE_GROUP("Moc Files" FILES ${INTERFACE_APPLICATION_QT_MOC_SRCS})
SOURCE_GROUP("UI Files" FILES ${INTERFACE_APPLICATION_UI_SRCS})
SOURCE_GROUP("UI Headers Files" FILES ${INTERFACE_APPLICATION_QT_UI_SRCS})

# Allows interoperability between boost::signals and qt signals.
add_definitions(-DQT_NO_KEYWORDS)

# SET_PROPERTY(TARGET ${Project} PROPERTY FOLDER "Core")

ADD_LIBRARY(Interface_Application STATIC
            ${INTERFACE_APPLICATION_SRCS} 
            ${INTERFACE_APPLICATION_QT_UI_SRCS}
            ${INTERFACE_APPLICATION_QT_MOC_SRCS}
            ${INTERFACE_APPLICATION_NO_MOC_SRCS} 
            ${INTERFACE_APPLICATION_MOC_SRCS})

TARGET_LINK_LIBRARIES(Interface_Application
    ${QT_LIBRARIES}
    ${QT_QTOPENGL_LIBRARY}
    ${BOOST_LIBRARY}
    Core_Application
)

# if(WIN32)
	# add_custom_command(
		# TARGET ${Project}
		# COMMAND ${CMAKE_COMMAND} -E copy ${GLEW_BUILD_PATH}/Debug/glew.dll ${CMAKE_CURRENT_BINARY_DIR}/Debug
		# COMMAND ${CMAKE_COMMAND} -E copy ${optix_DLL} ${CMAKE_CURRENT_BINARY_DIR}/Debug
		# COMMAND ${CMAKE_COMMAND} -E copy ${OptiX_INSTALL_DIR}/bin${bit_dest}/cudart64_42_9.dll ${CMAKE_CURRENT_BINARY_DIR}/Debug
	# )
# endif()