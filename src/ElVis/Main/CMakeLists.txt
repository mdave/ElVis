###########################################
# Set ElVis main sources
###########################################

SET(MAIN_SRCS
  main.cpp
)

ADD_EXECUTABLE(${APPLICATION_NAME} ${MAIN_SRCS})

TARGET_LINK_LIBRARIES(${APPLICATION_NAME} 
  ${SCI_BOOST_LIBRARY}
  ${QT_LIBRARIES}
  ${QT_QTOPENGL_LIBRARY}
  Interface_Application
)