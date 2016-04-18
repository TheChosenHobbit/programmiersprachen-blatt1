add_executable(helloworld helloworld.cpp)
#target_link_libraries(helloworld my_fancy_library)

add_executable(tests tests.cpp)
target_link_libraries(tests m)

# Kommentieren Sie die folgenden Zeilen für die Aufgabe `mileToKilometer` aus
#add_executable(mileToKilometer mileToKilometer.cpp)
#target_link_libraries(mileToKilometer m)
