cmake_minimum_required(VERSION 3.9)
project(PSO CXX)
set (CMAKE_CXX_STANDARD 11)

set(LIBS
        sfml-system
        sfml-window
        sfml-graphics
        sfml-network
        sfml-audio
        pthread)

set(src
        ParticleSwarmOptimization/main.cpp
        ParticleSwarmOptimization/GUI.cpp
        ParticleSwarmOptimization/Particle.cpp
        ParticleSwarmOptimization/PSO.cpp
        )


add_executable(pso ${src})
target_link_libraries(pso ${LIBS})


