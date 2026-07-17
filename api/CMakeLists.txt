include(FetchContent)

FetchContent_Declare(
    crow
    GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
    GIT_TAG v1.2.1
)

FetchContent_MakeAvailable(crow)

file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(api
    main.cpp
    ${SOURCES}
)

target_include_directories(api PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(api PRIVATE
    Crow::Crow
)

target_compile_features(api PRIVATE cxx_std_17)