cmake_minimum_required(VERSION 3.5)
project(ponderada)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cg_interfaces REQUIRED)

include_directories(include)

add_executable(navigation src/navigation.cpp)

ament_target_dependencies(navigation
  rclcpp
  std_msgs
  nav_msgs
  geometry_msgs
  sensor_msgs
  cg_interfaces
)

install(TARGETS
  navigation
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
