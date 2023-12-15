find_path(DPP_INCLUDE_DIR NAMES dpp/dpp.h HINTS ${DPP_ROOT_DIR})

find_library(DPP_LIBRARIES NAMES dpp "libdpp.a" HINTS ${DPP_ROOT_DIR})

message(STATUS "DPP_INCLUDE_DIR: ${DPP_INCLUDE_DIR}")
message(STATUS "DPP_LIBRARIES: ${DPP_LIBRARIES}")

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(DPP DEFAULT_MSG DPP_LIBRARIES DPP_INCLUDE_DIR)
