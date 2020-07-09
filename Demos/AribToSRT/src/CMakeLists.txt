file(GLOB AribToSRT_src *.h *.cpp)

include_directories(../include)
link_directories(../lib)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ../bin)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ../bin)

add_executable (AribToSRT ${AribToSRT_src})

target_link_libraries(AribToSRT mg_AribEngine_r mg_BaseTypes_r mg_CaptionsInterface_r mg_Core_r mg_Engine_r mg_IO_r mg_Memory_r mg_SRTEngine_r mg_TransportStreamEngine_r)