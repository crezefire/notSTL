set(curr_lib_name notSTL)

set(currsources
	libs/nstl/type_traits
	libs/nstl/cstddef
)

set(source_files ${source_files} ${currsources})

source_group(libs\\${curr_lib_name} FILES ${currsources})