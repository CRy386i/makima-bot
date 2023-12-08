find_path(DPP_INCLUDE_DIR NAMES dpp/dpp.h HINTS /home/cry386i/local/include)

find_library(DPP_LIBRARIES NAMES dpp "libdpp.so" HINTS /home/cry386i/local/lib64)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(DPP DEFAULT_MSG DPP_LIBRARIES DPP_INCLUDE_DIR)
