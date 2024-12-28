cmake_minimum_required(VERSION 3.10)
project(LoremLite VERSION 1.0)

add_library(LoremLite STATIC src/LoremLite.cpp)

target_include_directories(LoremLite PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

target_compile_features(LoremLite PUBLIC cxx_std_17)

install(TARGETS LoremLite EXPORT LoremLiteTargets ARCHIVE DESTINATION lib)

install(DIRECTORY include/ DESTINATION include)
