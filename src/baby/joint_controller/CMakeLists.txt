cmake_minimum_required(VERSION 2.8.3)
project(joint_controller)
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


add_executable(arm_joints src/joint_state_publisher.cpp )
add_executable(Hand_movement src/Hand_movement.cpp)
add_executable(Leg_movement src/Leg_movement.cpp)

target_link_libraries(arm_joints ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
target_link_libraries(Hand_movement ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
target_link_libraries(Leg_movement ${catkin_LIBRARIES})
    
