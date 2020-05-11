cmake_minimum_required(VERSION 3.14)
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
		CACHE STRING "")
endif()
project(openapi_test)

set(ALIYUN_SDK $ENV{VCPKG_ROOT}/../aliyun-openapi-cpp-sdk/)

include_directories(
	${ALIYUN_SDK}/core/include
	${ALIYUN_SDK}/alidns/include
	)

link_directories(
	${ALIYUN_SDK}/sdk_build/lib/RelWithDebInfo/
	)

add_executable(apitest openapi-sdk-test.cpp)
target_link_libraries(apitest alibabacloud-sdk-core alibabacloud-sdk-alidns)
set_target_properties(apitest PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
