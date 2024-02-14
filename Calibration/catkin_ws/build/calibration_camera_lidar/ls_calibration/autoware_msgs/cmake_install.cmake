# Install script for directory: /home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/kai/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autoware_msgs/msg" TYPE FILE FILES
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ControlCommandStamped.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/CloudCluster.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/CloudClusterArray.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ColorSet.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ControlCommand.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/DetectedObject.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/DetectedObjectArray.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ExtractedPosition.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ImageLaneObjects.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ImageObjects.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/LaneArray.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/PointsImage.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ScanImage.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/Signals.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/TunedResult.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ValueSet.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/Centroids.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/DTLane.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/GeometricRectangle.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ICPStat.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ImageObj.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ImageObjRanged.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ImageObjTracked.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ImageRect.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ImageRectRanged.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/Lane.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/NDTStat.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ObjLabel.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ObjPose.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/ProjectionMatrix.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/VscanTracked.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/VscanTrackedArray.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/Waypoint.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/WaypointState.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/VehicleCmd.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/VehicleStatus.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/TrafficLightResult.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/TrafficLightResultArray.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/AccelCmd.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/AdjustXY.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/BrakeCmd.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/IndicatorCmd.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/LampCmd.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/SteerCmd.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/TrafficLight.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/StateCmd.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/State.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/SyncTimeMonitor.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/SyncTimeDiff.msg"
    "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/msg/RemoteCmd.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autoware_msgs/cmake" TYPE FILE FILES "/home/kai/catkin_ws/build/calibration_camera_lidar/ls_calibration/autoware_msgs/catkin_generated/installspace/autoware_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/kai/catkin_ws/devel/include/autoware_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/kai/catkin_ws/devel/share/roseus/ros/autoware_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/kai/catkin_ws/devel/share/common-lisp/ros/autoware_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/kai/catkin_ws/devel/share/gennodejs/ros/autoware_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/kai/catkin_ws/devel/lib/python2.7/dist-packages/autoware_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/kai/catkin_ws/devel/lib/python2.7/dist-packages/autoware_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/kai/catkin_ws/build/calibration_camera_lidar/ls_calibration/autoware_msgs/catkin_generated/installspace/autoware_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autoware_msgs/cmake" TYPE FILE FILES "/home/kai/catkin_ws/build/calibration_camera_lidar/ls_calibration/autoware_msgs/catkin_generated/installspace/autoware_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autoware_msgs/cmake" TYPE FILE FILES
    "/home/kai/catkin_ws/build/calibration_camera_lidar/ls_calibration/autoware_msgs/catkin_generated/installspace/autoware_msgsConfig.cmake"
    "/home/kai/catkin_ws/build/calibration_camera_lidar/ls_calibration/autoware_msgs/catkin_generated/installspace/autoware_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autoware_msgs" TYPE FILE FILES "/home/kai/catkin_ws/src/calibration_camera_lidar/ls_calibration/autoware_msgs/package.xml")
endif()

