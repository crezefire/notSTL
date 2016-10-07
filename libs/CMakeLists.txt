#Sourced files should use add_sub for a separate project
#add_subdirectory(libs/sample-lib/ sample-lib)
include(libs/nstl/CMakeLists.txt)
include(libs/nstl-configs/CMakeLists.txt)

# set(additional_libs
	# ${additional_libs}
	# sample-lib
# )

set(additional_includes
	${additional_includes}
	libs/
)

set(linker_includes
	${linker_includes}
)