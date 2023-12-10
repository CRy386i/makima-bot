set(DPP_LIB WHERE_IS_INSTALL_DPP)
set(DPP_INCLUDE WHERE_IS_INSTALL_DPP)

find_path(DPP_INCLUDE_DIR NAMES dpp/dpp.h HINTS ${DDP_INCLUDE})

find_library(DPP_LIBRARIES NAMES dpp "libdpp.so" HINTS ${DDP_LIB})

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(DPP DEFAULT_MSG DPP_LIB DPP_INCLUDE)
