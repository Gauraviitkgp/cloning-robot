cmake_minimum_required(VERSION 2.8.3)
project(balancer)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED
 catkin REQUIRED COMPONENTS
    roscpp
    rospy
    std_msgs
    geometry_msgs
    sensor_msgs
    message_generation
  )
find_package(OpenCV)


catkin_package()

include_directories(${catkin_INCLUDE_DIRS}
	${OpenCV_INCLUDE_DIRS}
	)

install(DIRECTORY src
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})


add_executable(balance src/balance.cpp )

target_link_libraries(balance ${catkin_LIBRARIES})
