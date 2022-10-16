cmake_minimum_required(VERSION 3.23.3)

project(MyEvolution)

set(SFML_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1)
message(-----> ${SFML_ROOT_DIR})

set(SFML_DIR ${SFML_ROOT_DIR}/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

add_executable(${PROJECT_NAME} src/SFML_Evolution.cpp src/Creatures.cpp src/Food.cpp src/Map.cpp src/Poison.cpp src/RandMap.cpp src/Voidness.cpp src/Wall.cpp src/Step.cpp) #Пихаем исполняемые файлы через пробел

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-network sfml-graphics sfml-audio)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX .exe)