add_executable(main main.c)

add_library(resource resource.c)
add_library(resource_sheet resource_sheet.c)

target_include_directories(resource PUBLIC ../include)
target_include_directories(resource_sheet PUBLIC ../include)

target_link_libraries(resource_sheet PRIVATE resource)
target_link_libraries(main PRIVATE resource resource_sheet)
