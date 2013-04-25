SET(Project "ElVis")

IF( NOT QT4_FOUND )
    FIND_PACKAGE(Qt4)
ENDIF() 

IF( QT4_FOUND )
    include(${QT_USE_FILE})
ENDIF()

SET(QT_UI_FILES
	MainWindow.ui
)

SET(QT_QOBJECT_HEADERS
    Breakpoints.h
    CameraPropertyManager.h
    ColorMapEditorWidget.h
    ColorMapRect.h
    ColorMapWidget.h
    ColorPropertyManager.h
    ContourDockWidget.h
    DebugSettingsDockWidget.h
    ElementFaceRenderingDockWidget.h
    ElVisUI.h
    IsosurfaceDockWidget.h
    LightingDockWidget.h
	MainWindow.h
    ModelInspectorWidget.h
    ObjectInspectorUI.h
    PlanePropertyManager.h
    PointPropertyManager.h
    Property.hpp
    RenderSettingsDockWidget.h
    SampleOntoNrrdDockWidget.h
    SceneItemsDockWidget.h
    SceneViewWidget.h
    VectorPropertyManager.h
    ViewSettingsUI.h
    VolumeRenderingSettingsWidget.h
)

SET(Headers
	ApplicationState.h
)

SET(Sources
    ApplicationState.cpp    
    Breakpoints.cpp
    ColorMapEditorWidget.cpp
    ColorMapRect.cpp
    ColorMapWidget.cpp
    ContourDockWidget.cpp
    DebugSettingsDockWidget.cpp
    ElementFaceRenderingDockWidget.cpp
    ElVisUI.cpp
    IsosurfaceDockWidget.cpp
    LightingDockWidget.cpp
    main.cpp
    MainWindow.cpp
	ModelInspectorWidget.cpp
    ObjectInspectorUI.cpp
    RenderSettingsDockWidget.cpp
    SampleOntoNrrdDockWidget.cpp
    SceneItemsDockWidget.cpp
    SceneViewWidget.cpp
    ViewSettingsUI.cpp
    VolumeRenderingSettingsWidget.cpp
)

SET(QT_STYLES ElVis.qss)

QT_WRAP_CPP(${Project} QT_PROCESSED_MOC_SOURCE ${QT_QOBJECT_HEADERS})
QT4_WRAP_UI(QT_PROCESSED_UI_HEADERS ${QT_UI_FILES})
#QT4_ADD_RESOURCES(QT_RESOURCES ${RESOURCES})

SOURCE_GROUP("Moc Files" FILES ${QT_PROCESSED_MOC_SOURCE})
SOURCE_GROUP("UI Headers Files" FILES ${QT_PROCESSED_UI_HEADERS})
SOURCE_GROUP("UI Files" FILES ${QT_UI_FILES})
SOURCE_GROUP("UI Styles" FILES ${QT_STYLES})

message(STATUS "${QT_RESOURCES}")

# Allows interoperability between boost::signals and qt signals.
add_definitions(-DQT_NO_KEYWORDS)

ADD_ELVIS_EXECUTABLE(${Project} 
    ${Sources} 
    ${Headers}
    ${QT_QOBJECT_HEADERS}
    ${QT_PROCESSED_UI_HEADERS}
    ${QT_PROCESSED_MOC_SOURCE}
	${QT_STYLES}
)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

SET_PROPERTY(TARGET ${Project} PROPERTY FOLDER "Core")

TARGET_LINK_LIBRARIES(${Project}
    ${QT_LIBRARIES}
    ${QT_QTOPENGL_LIBRARY}
    ${BOOST_LIBRARY}
    ElVisCore
    QtPropertyBrowser
    glew
    ${PNG_LIBRARY}
    ${ZLIB_LIBRARY}
    TinyXML
)

INSTALL(FILES ElVis.qss
    DESTINATION ${ELVIS_BIN_DIR}
)

if(WIN32)
	add_custom_command(
		TARGET ${Project}
		COMMAND ${CMAKE_COMMAND} -E copy ${CORE_BUILD_PATH}/Debug/ElVisCore.dll ${CMAKE_CURRENT_BINARY_DIR}/Debug
		COMMAND ${CMAKE_COMMAND} -E copy ${GLEW_BUILD_PATH}/Debug/glew.dll ${CMAKE_CURRENT_BINARY_DIR}/Debug
		COMMAND ${CMAKE_COMMAND} -E copy ${optix_DLL} ${CMAKE_CURRENT_BINARY_DIR}/Debug
		COMMAND ${CMAKE_COMMAND} -E copy ${OptiX_INSTALL_DIR}/bin${bit_dest}/cudart64_42_9.dll ${CMAKE_CURRENT_BINARY_DIR}/Debug
	)
endif()