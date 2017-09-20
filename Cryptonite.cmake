include(TargetArch)

# Set target architectures
target_architecture(CMAKE_TARGET_ARCHITECTURES)
list(LENGTH CMAKE_TARGET_ARCHITECTURES cmake_target_arch_len)
if(NOT "${cmake_target_arch_len}" STREQUAL "1")
    set(CMAKE_TARGET_ARCHITECTURE_UNIVERSAL TRUE)
    set(CMAKE_TARGET_ARCHITECTURE_CODE "universal")
else()
    set(CMAKE_TARGET_ARCHITECTURE_UNIVERSAL FALSE)
    set(CMAKE_TARGET_ARCHITECTURE_CODE "${CMAKE_TARGET_ARCHITECTURES}")
endif()