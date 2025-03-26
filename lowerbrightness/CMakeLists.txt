cmake_minimum_required(VERSION 3.21)
project(lowerbrightness)

find_package(KF6 REQUIRED COMPONENTS CoreAddons GuiAddons ConfigWidgets)
find_package(KWin6 REQUIRED)

add_library(lowerbrightness MODULE lowerbrightness.cpp)
target_link_libraries(lowerbrightness PRIVATE KWin6::effects)

install(TARGETS lowerbrightness DESTINATION ~/.local/lib/qt6/plugins/kwin/effects/)
install(FILES metadata.json DESTINATION ~/.local/share/kwin/effects/LowerBrightness/)
