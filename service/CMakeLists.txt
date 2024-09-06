cmake_minimum_required(VERSION 3.9)

SET(ITMSVC_SRC
  main.cpp
)

add_executable(itmsvc ${ITMSVC_SRC})
target_include_directories(itmsvc PRIVATE
  ${itminclude}
)

# Use C++14
set_property(TARGET itmsvc PROPERTY CXX_STANDARD 14)

target_link_libraries(itmsvc itmlib)

#
# Use UNICODE in windows
#
if(WIN32)
  ADD_DEFINITIONS(-DUNICODE)
  ADD_DEFINITIONS(-D_UNICODE)
  target_link_libraries(itmsvc version)
endif(WIN32)