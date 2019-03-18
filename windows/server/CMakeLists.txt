# CMakeList.txt: client 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
project ("server")

AUX_SOURCE_DIRECTORY(. DIR_LIB_SRC)
ADD_EXECUTABLE(server ${DIR_LIB_SRC})

include_directories("../lib")
TARGET_LINK_LIBRARIES(server SocketLib)
# TODO: 如有需要，请添加测试并安装目标。