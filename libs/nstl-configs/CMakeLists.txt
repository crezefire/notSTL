set(curr_lib_name notSTL-configs)

set(currsources
	libs/nstl-configs/Compiler.h
	libs/nstl-configs/LibConfig.h
	libs/nstl-configs/Platform.h
)

set(source_files ${source_files} ${currsources})

source_group(libs\\${curr_lib_name} FILES ${currsources})