if(UNIX)
    if(APPLE)
        set(MACOS TRUE)
    else()
        set(LINUX TRUE)
    endif()
endif()

if(WIN32)
    set(WINDOWS TRUE)
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING
    "Only do Release and Debug"
    FORCE
)
