#if building standalone and not specified build tests
option(BUILD_TESTS "Whether to build tests" ON)
include(FetchContent)
FetchContent_Declare( al2o3 GIT_REPOSITORY https://github.com/DeanoC/al2o3 GIT_TAG master )
FetchContent_GetProperties(al2o3)
if(NOT al2o3_POPULATED)
	FetchContent_Populate(al2o3)
	add_subdirectory(${al2o3_SOURCE_DIR} ${al2o3_BINARY_DIR})
endif()

SET_MIN_VERSIONS()
set(LibName al2o3_syoyo)
project(${LibName})

set(Interface
		tiny_exr.h
		tiny_exr.hpp
		tiny_objloader.h
		tiny_xpd.hpp
		)

set(Src
		syoyo_impl.cpp
		tiny_objloader.c
		tinyexr.cpp
		tinyexr.hpp
		tinyexr_bindings.cpp
		)

set(Deps
		al2o3_platform
		al2o3_cmath
		al2o3_vfile
		al2o3_tinystl
		al2o3_miniz
		)
ADD_LIB(${LibName} "${Interface}" "${Src}" "${Deps}")

set( Tests
		runner.cpp
		test_exr_c.cpp
		test_objloader_c.cpp
		)
set( TestDeps
		utils_simple_logmanager
		al2o3_catch2 )
ADD_LIB_TESTS(${LibName} "${Interface}" "${Tests}" "${TestDeps}")

