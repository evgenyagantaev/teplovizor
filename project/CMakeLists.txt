cmake_minimum_required (VERSION 2.6)
cmake_policy(SET CMP0012 NEW)
PROJECT(project)
# Requires OpenCV
FIND_PACKAGE( OpenCV 4.2.0 REQUIRED )
MESSAGE("OpenCV version : ${OpenCV_VERSION}")
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})
ADD_EXECUTABLE( sample main.cpp current_thermo_frame.cpp marked_thermo_frame.cpp point.cpp thermo_pixel.cpp 
                brightness_to_temperature_converter.cpp rect_thermal_spot.cpp utilities.cpp temperature_range.cpp 
                thermo_pixel_vector.cpp)
TARGET_LINK_LIBRARIES( sample ${OpenCV_LIBS} )