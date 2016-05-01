cmake_minimum_required(VERSION 2.6)
project(duel_gravity)

add_executable(duel_gravity main.cpp worldengine.cpp corps.cpp corpsfix.cpp event_engine.cpp g_engine.cpp vaisseaux.cpp planete.cpp gravity_engine.cpp texture_engine.cpp)


install(TARGETS duel_gravity RUNTIME DESTINATION bin)

target_link_libraries(
     duel_gravity
     -lsfml-graphics
     -lsfml-window
     -lsfml-system
     -lsfml-audio
     -lBox2D)