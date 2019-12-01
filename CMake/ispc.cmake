find_program (ISPC_EXECUTABLE ispc)
if (NOT ISPC_EXECUTABLE)
    message(FATAL_ERROR "Failed to find ispc" )
endif()
#set (EXAMPLES_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

function(add_ispc_executable)
    set(options USE_COMMON_SETTINGS)
    set(oneValueArgs NAME ISPC_SRC_NAME DATA_DIR)
    set(multiValueArgs ISPC_IA_TARGETS ISPC_ARM_TARGETS ISPC_FLAGS TARGET_SOURCES LIBRARIES DATA_FILES)
    cmake_parse_arguments("ISPC_TARGET" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	#因为这个太多了，等到最后再使用全部的吧
    #set(ISPC_KNOWN_TARGETS "sse2" "sse4" "avx1-" "avx2" "avx512knl" "avx512skx" "neon")
    set(ISPC_KNOWN_TARGETS "sse2" "sse4" "avx1-" "avx2" "avx512knl" "avx512skx" "neon")
    
	set(ISPC_HEADER_NAME "${CMAKE_CURRENT_BINARY_DIR}/${ISPC_SRC_NAME}_ispc.h")
    set(ISPC_OBJ_NAME "${CMAKE_CURRENT_BINARY_DIR}/${ISPC_SRC_NAME}_ispc${CMAKE_CXX_OUTPUT_EXTENSION}")
    set(ISPC_FLAGS ${ISPC_TARGET_ISPC_FLAGS})
    if (UNIX)
        execute_process( COMMAND bash "-c" "uname -m | sed -e s/x86_64/x86/ -e s/i686/x86/ -e s/arm.*/arm/ -e s/sa110/arm/" OUTPUT_VARIABLE ARCH)
        string(STRIP ${ARCH} ARCH)
        execute_process( COMMAND getconf LONG_BIT OUTPUT_VARIABLE ARCH_BIT)
        string(STRIP ${ARCH_BIT} ARCH_BIT)
        if ("${ARCH}" STREQUAL "x86")
            if (${ARCH_BIT} EQUAL 32)
                set(ISPC_ARCH "x86")
            else()
                set(ISPC_ARCH "x86-64")
            endif()
        elseif ("${ARCH}" STREQUAL "arm")
            set(ISPC_ARCH "arm")
        elseif ("${ARCH}" STREQUAL "aarch64")
            set(ISPC_ARCH "aarch64")
        endif()
        list(APPEND ISPC_FLAGS --pic)
    else()
        set(ARCH "x86")
        if (CMAKE_SIZEOF_VOID_P EQUAL 8 )
            set(ISPC_ARCH "x86-64")
        else()
            set(ISPC_ARCH "x86")
        endif()
    endif()

    # Collect list of expected outputs
    list(APPEND ISPC_BUILD_OUTPUT ${ISPC_HEADER_NAME} ${ISPC_OBJ_NAME})
    if (ISPC_TARGET_USE_COMMON_SETTINGS)
        if ("${ARCH}" STREQUAL "x86")
            set(ISPC_TARGETS ${ISPC_TARGET_ISPC_IA_TARGETS})
            string(FIND ${ISPC_TARGET_ISPC_IA_TARGETS} "," MULTI_TARGET)
            if (${MULTI_TARGET} GREATER -1)
                foreach (ispc_target ${ISPC_KNOWN_TARGETS})
                    string(FIND ${ISPC_TARGET_ISPC_IA_TARGETS} ${ispc_target} FOUND_TARGET)
                    if (${FOUND_TARGET} GREATER -1)
                        set(OUTPUT_TARGET ${ispc_target})
                        if (${ispc_target} STREQUAL "avx1-")
                            set(OUTPUT_TARGET "avx")
                        endif()
                        list(APPEND ISPC_BUILD_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${ISPC_SRC_NAME}_ispc_${OUTPUT_TARGET}.h"
                                    "${CMAKE_CURRENT_BINARY_DIR}/${ISPC_SRC_NAME}_ispc_${OUTPUT_TARGET}${CMAKE_CXX_OUTPUT_EXTENSION}")
                    endif()
                endforeach()
            endif()
        elseif ("${ARCH}" STREQUAL "arm" OR "${ARCH}" STREQUAL "aarch64")
            set(ISPC_TARGETS ${ISPC_TARGET_ISPC_ARM_TARGETS})
        else()
            message(FATAL_ERROR "Unknown architecture ${ARCH}")
        endif()
    else()
        if ("${ARCH}" STREQUAL "x86")
            set(ISPC_TARGETS ${ISPC_TARGET_ISPC_IA_TARGETS})
        elseif ("${ARCH}" STREQUAL "arm" OR "${ARCH}" STREQUAL "aarch64")
            set(ISPC_TARGETS ${ISPC_TARGET_ISPC_ARM_TARGETS})
        else()
            message(FATAL_ERROR "Unknown architecture ${ARCH}")
        endif()

    endif()
    # ISPC command
    add_custom_command(OUTPUT ${ISPC_BUILD_OUTPUT}
        COMMAND ${ISPC_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/${ISPC_SRC_NAME}.ispc ${ISPC_FLAGS} --target=${ISPC_TARGETS} --arch=${ISPC_ARCH}
                                   -h ${ISPC_HEADER_NAME} -o ${ISPC_OBJ_NAME}
        VERBATIM
        DEPENDS ${ISPC_EXECUTABLE}
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${ISPC_SRC_NAME}.ispc")

    # To show ispc source in VS solution:
    if (WIN32)
        set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/${ISPC_SRC_NAME}.ispc" PROPERTIES HEADER_FILE_ONLY TRUE)
    endif()

    add_executable(${ISPC_TARGET_NAME} ${ISPC_BUILD_OUTPUT} "${CMAKE_CURRENT_SOURCE_DIR}/${ISPC_SRC_NAME}.ispc")
    #message("THE ISPC_BUILD_OUTPUT" "${ISPC_BUILD_OUTPUT} ")
	target_sources(${ISPC_TARGET_NAME} PRIVATE ${ISPC_TARGET_TARGET_SOURCES})
    target_include_directories(${ISPC_TARGET_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
    # Compile options
    if (UNIX)
        if (${ARCH_BIT} EQUAL 32)
            target_compile_options(${ISPC_TARGET_NAME} PRIVATE -m32)
        else()
            target_compile_options(${ISPC_TARGET_NAME} PRIVATE -m64)
        endif()
        target_compile_options(${ISPC_TARGET_NAME} PRIVATE -fpie)
    else()
        target_compile_options(${ISPC_TARGET_NAME} PRIVATE /fp:fast /Oi)
    endif()

    # Common settings
    if (ISPC_TARGET_USE_COMMON_SETTINGS)
        #target_sources(${ISPC_TARGET_NAME} PRIVATE ${EXAMPLES_ROOT}/tasksys.cpp)
        #target_sources(${ISPC_TARGET_NAME} PRIVATE ${EXAMPLES_ROOT}/timing.h)
        if (UNIX)
            target_compile_options(${ISPC_TARGET_NAME} PRIVATE -O2)
            target_link_libraries(${ISPC_TARGET_NAME} pthread m stdc++)
        endif()
    endif()

    # Link libraries
    if (ISPC_TARGET_LIBRARIES)
        target_link_libraries(${ISPC_TARGET_NAME} ${ISPC_TARGET_LIBRARIES})
    endif()

    #set_target_properties(${ISPC_TARGET_NAME} PROPERTIES FOLDER "IspcTarget")

    #if(MSVC)
    #    # Group ISPC files inside Visual Studio
    #    source_group("ISPC" FILES "${CMAKE_CURRENT_SOURCE_DIR}/${ISPC_SRC_NAME}.ispc")
    #endif()

    # Install example
    # We do not need to include examples binaries to the package
    
	#if (NOT ISPC_PREPARE_PACKAGE)
    #    install(TARGETS ${ISPC_TARGET_NAME} RUNTIME DESTINATION examples/${ISPC_TARGET_NAME})
    #    if (ISPC_TARGET_DATA_FILES)
    #        install(FILES ${ISPC_TARGET_DATA_FILES}
    #                DESTINATION examples/${ISPC_TARGET_NAME})
    #    endif()
    #
    #     if (ISPC_TARGET_DATA_DIR)
    #           install(DIRECTORY ${ISPC_TARGET_DATA_DIR}
    #                  DESTINATION examples/${ISPC_TARGET_NAME})
    #     endif()
    #endif()

endfunction()


function(add_ispc_library)
    set(options USE_COMMON_SETTINGS)
    set(oneValueArgs NAME ISPC_SRC_NAME DATA_DIR)
    set(multiValueArgs ISPC_IA_TARGETS ISPC_ARM_TARGETS ISPC_FLAGS TARGET_SOURCES LIBRARIES DATA_FILES)
    cmake_parse_arguments("ISPC_TARGET" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	#因为这个太多了，等到最后再使用全部的吧
    #set(ISPC_KNOWN_TARGETS "sse2" "sse4" "avx1-" "avx2" "avx512knl" "avx512skx" "neon")
    set(ISPC_KNOWN_TARGETS "sse2" "sse4" "avx1-" "avx2" "avx512knl" "avx512skx" "neon")
    
	set(ISPC_HEADER_NAME "${CMAKE_CURRENT_BINARY_DIR}/${ISPC_SRC_NAME}_ispc.h")
    set(ISPC_OBJ_NAME "${CMAKE_CURRENT_BINARY_DIR}/${ISPC_SRC_NAME}_ispc${CMAKE_CXX_OUTPUT_EXTENSION}")
    set(ISPC_FLAGS ${ISPC_TARGET_ISPC_FLAGS})
    if (UNIX)
        execute_process( COMMAND bash "-c" "uname -m | sed -e s/x86_64/x86/ -e s/i686/x86/ -e s/arm.*/arm/ -e s/sa110/arm/" OUTPUT_VARIABLE ARCH)
        string(STRIP ${ARCH} ARCH)
        execute_process( COMMAND getconf LONG_BIT OUTPUT_VARIABLE ARCH_BIT)
        string(STRIP ${ARCH_BIT} ARCH_BIT)
        if ("${ARCH}" STREQUAL "x86")
            if (${ARCH_BIT} EQUAL 32)
                set(ISPC_ARCH "x86")
            else()
                set(ISPC_ARCH "x86-64")
            endif()
        elseif ("${ARCH}" STREQUAL "arm")
            set(ISPC_ARCH "arm")
        elseif ("${ARCH}" STREQUAL "aarch64")
            set(ISPC_ARCH "aarch64")
        endif()
        list(APPEND ISPC_FLAGS --pic)
    else()
        set(ARCH "x86")
        if (CMAKE_SIZEOF_VOID_P EQUAL 8 )
            set(ISPC_ARCH "x86-64")
        else()
            set(ISPC_ARCH "x86")
        endif()
    endif()

    # Collect list of expected outputs
    list(APPEND ISPC_BUILD_OUTPUT ${ISPC_HEADER_NAME} ${ISPC_OBJ_NAME})
    if (ISPC_TARGET_USE_COMMON_SETTINGS)
        if ("${ARCH}" STREQUAL "x86")
            set(ISPC_TARGETS ${ISPC_TARGET_ISPC_IA_TARGETS})
            string(FIND ${ISPC_TARGET_ISPC_IA_TARGETS} "," MULTI_TARGET)
            if (${MULTI_TARGET} GREATER -1)
                foreach (ispc_target ${ISPC_KNOWN_TARGETS})
                    string(FIND ${ISPC_TARGET_ISPC_IA_TARGETS} ${ispc_target} FOUND_TARGET)
                    if (${FOUND_TARGET} GREATER -1)
                        set(OUTPUT_TARGET ${ispc_target})
                        if (${ispc_target} STREQUAL "avx1-")
                            set(OUTPUT_TARGET "avx")
                        endif()
                        list(APPEND ISPC_BUILD_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${ISPC_SRC_NAME}_ispc_${OUTPUT_TARGET}.h"
                                    "${CMAKE_CURRENT_BINARY_DIR}/${ISPC_SRC_NAME}_ispc_${OUTPUT_TARGET}${CMAKE_CXX_OUTPUT_EXTENSION}")
                    endif()
                endforeach()
            endif()
        elseif ("${ARCH}" STREQUAL "arm" OR "${ARCH}" STREQUAL "aarch64")
            set(ISPC_TARGETS ${ISPC_TARGET_ISPC_ARM_TARGETS})
        else()
            message(FATAL_ERROR "Unknown architecture ${ARCH}")
        endif()
    else()
        if ("${ARCH}" STREQUAL "x86")
            set(ISPC_TARGETS ${ISPC_TARGET_ISPC_IA_TARGETS})
        elseif ("${ARCH}" STREQUAL "arm" OR "${ARCH}" STREQUAL "aarch64")
            set(ISPC_TARGETS ${ISPC_TARGET_ISPC_ARM_TARGETS})
        else()
            message(FATAL_ERROR "Unknown architecture ${ARCH}")
        endif()

    endif()
    # ISPC command
    add_custom_command(OUTPUT ${ISPC_BUILD_OUTPUT}
        COMMAND ${ISPC_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/${ISPC_SRC_NAME}.ispc ${ISPC_FLAGS} --target=${ISPC_TARGETS} --arch=${ISPC_ARCH}
                                   -h ${ISPC_HEADER_NAME} -o ${ISPC_OBJ_NAME}
        VERBATIM
        DEPENDS ${ISPC_EXECUTABLE}
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${ISPC_SRC_NAME}.ispc")

    # To show ispc source in VS solution:
    if (WIN32)
        set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/${ISPC_SRC_NAME}.ispc" PROPERTIES HEADER_FILE_ONLY TRUE)
    endif()

    add_library(${ISPC_TARGET_NAME} ${ISPC_BUILD_OUTPUT} "${CMAKE_CURRENT_SOURCE_DIR}/${ISPC_SRC_NAME}.ispc")
    SET_TARGET_PROPERTIES(${ISPC_TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
	if(ISPC_TARGET_TARGET_SOURCES)
		target_sources(${ISPC_TARGET_NAME} PRIVATE ${ISPC_TARGET_TARGET_SOURCES})
    endif()

	include_directories(${CMAKE_CURRENT_BINARY_DIR})
	#target_include_directories(${ISPC_TARGET_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
    # Compile options
    if (UNIX)
        if (${ARCH_BIT} EQUAL 32)
            target_compile_options(${ISPC_TARGET_NAME} PRIVATE -m32)
        else()
            target_compile_options(${ISPC_TARGET_NAME} PRIVATE -m64)
        endif()
        target_compile_options(${ISPC_TARGET_NAME} PRIVATE -fpie)
    else()
        target_compile_options(${ISPC_TARGET_NAME} PRIVATE /fp:fast /Oi)
    endif()

    # Common settings
    if (ISPC_TARGET_USE_COMMON_SETTINGS)
        #target_sources(${ISPC_TARGET_NAME} PRIVATE ${EXAMPLES_ROOT}/tasksys.cpp)
        #target_sources(${ISPC_TARGET_NAME} PRIVATE ${EXAMPLES_ROOT}/timing.h)
        if (UNIX)
            target_compile_options(${ISPC_TARGET_NAME} PRIVATE -O2)
            target_link_libraries(${ISPC_TARGET_NAME} pthread m stdc++)
        endif()
    endif()

    # Link libraries
    if (ISPC_TARGET_LIBRARIES)
        target_link_libraries(${ISPC_TARGET_NAME} ${ISPC_TARGET_LIBRARIES})
    endif()

    #set_target_properties(${ISPC_TARGET_NAME} PROPERTIES FOLDER "IspcTarget")

    #if(MSVC)
    #    # Group ISPC files inside Visual Studio
    #    source_group("ISPC" FILES "${CMAKE_CURRENT_SOURCE_DIR}/${ISPC_SRC_NAME}.ispc")
    #endif()

    # Install example
    # We do not need to include examples binaries to the package
    
	#if (NOT ISPC_PREPARE_PACKAGE)
    #    install(TARGETS ${ISPC_TARGET_NAME} RUNTIME DESTINATION examples/${ISPC_TARGET_NAME})
    #    if (ISPC_TARGET_DATA_FILES)
    #        install(FILES ${ISPC_TARGET_DATA_FILES}
    #                DESTINATION examples/${ISPC_TARGET_NAME})
    #    endif()
    #
    #     if (ISPC_TARGET_DATA_DIR)
    #           install(DIRECTORY ${ISPC_TARGET_DATA_DIR}
    #                  DESTINATION examples/${ISPC_TARGET_NAME})
    #     endif()
    #endif()

endfunction()


