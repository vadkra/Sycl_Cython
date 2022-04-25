include_directories(${PROJECT_SOURCE_DIR}/include)

file( GLOB LIB_SOURCES add.cpp )
add_library( src ${LIB_SOURCES} )
add_sycl_to_target(TARGET src SOURCES add.cpp)

install(TARGETS src DESTINATION ${CMAKE_BINARY_DIR}/lib)
install(FILES ${PROJECT_SOURCE_DIR}/include/add.h DESTINATION ${CMAKE_BINARY_DIR}/include)