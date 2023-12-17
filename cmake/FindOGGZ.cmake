find_path(OGGZ_INCLUDE_DIR NAMES oggz/oggz.h PATH_SUFFIXES include)

if(OGGZ_INCLUDE_DIR)
	set(HAVE_OGGZ_OGGZ_H 1)
endif()

if(OGGZ_USE_STATIC_LIBS)
	find_library(OGGZ_LIBRARIES NAMES "liboggz.a")
else()
	find_library(OGGZ_LIBRARIES NAMES oggz)
endif()

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(OGGZ DEFAULT_MSG OGGZ_LIBRARIES OGGZ_INCLUDE_DIR)
