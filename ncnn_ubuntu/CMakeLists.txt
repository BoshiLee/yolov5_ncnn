cmake_minimum_required(VERSION 3.10)

project(yolov5_ncnn)
# ncnn

set(ncnn_install_dir "/docker_mount/ncnn/build/install")
set(ncnn_DIR "${ncnn_install_dir}/lib/cmake/ncnn")
find_package(ncnn REQUIRED)
# open cv
find_package(OpenCV REQUIRED)
macro(running project)
    add_executable(${project} main.cpp src/cpp/YoloV5Net.cpp)

    if(ncnn_FOUND)
        message(STATUS "ncnn library: ${ncnn_INSTALL_PATH}")
        message(STATUS "    version: ${ncnn_VERSION}")
        message(STATUS "    libraries: ${ncnn_LIBS}")
        message(STATUS "    include path: ${ncnn_INCLUDE_DIRS}")
        target_link_libraries(${project} ncnn)
    endif()
    if(OpenCV_FOUND)
        message(STATUS "OpenCV library: ${OpenCV_INSTALL_PATH}")
        message(STATUS "    version: ${OpenCV_VERSION}")
        message(STATUS "    libraries: ${OpenCV_LIBS}")
        message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
        include_directories( ${OpenCV_INCLUDE_DIRS} )
        target_link_libraries(${project} ${OpenCV_LIBS} )
    endif()
endmacro()


running(yolov5_ncnn)

