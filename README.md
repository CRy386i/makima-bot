# Makima-bot for discord. ¯\_(ツ)_/¯

## Descriptino

This is simple bot for own use.

## How to install

Following the DPP's [manual for configuring CMake projects](https://dpp.dev/buildcmake.html).

Require create FindDPP.cmake file, inside the "cmake" directory.

Here's what you should use for you cases:
```
set(DPP_LIB WHERE_IS_INSTALL_DPP)
set(DPP_INCLUDE WHERE_IS_INSTALL_DPP)

find_path(DPP_INCLUDE_DIR NAMES dpp/dpp.h HINTS ${WHERE_IS_INSTALL_DPP})
 
find_library(DPP_LIBRARIES NAMES dpp "libdpp.a" HINTS ${WHERE_IS_INSTALL_DPP})
 
include(FindPackageHandleStandardArgs)
 
find_package_handle_standard_args(DPP DEFAULT_MSG DPP_LIBRARIES DPP_INCLUDE_DIR)
```
