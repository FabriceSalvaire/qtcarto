# -*- CMake -*-

####################################################################################################
#
# Include directories
#

# include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${Qt5Quick_PRIVATE_INCLUDE_DIRS})

####################################################################################################
#
# Library
#

set(qtcarto_files
  declarative_map_item.cpp
  geo_coordinate_animation.cpp
  map_gesture_area.cpp
  plugin_data.cpp
  qtcarto.cpp
)
add_library(qmlqtcartoplugin SHARED ${qtcarto_files})
# include QImage requires Qui
target_link_libraries(qmlqtcartoplugin qtcarto Qt5::Qml Qt5::Quick Qt5::Positioning)

####################################################################################################
#
# End
#
####################################################################################################
