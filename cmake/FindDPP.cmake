set(DPP_LIB WHERE_IS_INSTALL_DPP)
set(DPP_INCLUDE WHERE_IS_INSTALL_DPP)

find_path(DPP_INCLUDE NAMES dpp/dpp.h HINTS ${DPP_INCLUDE})

find_library(DPP_LIB NAMES dpp HINTS ${DPP_LIB})

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(DPP DEFAULT_MSG DPP_LIB DPP_INCLUDE)
