find_package(BLAS)

if(BLAS_FOUND)
    add_definitions(-DUSEBLAS)
endif(BLAS_FOUND)


add_library(lac MyMatrix.cpp)

if(BLAS_FOUND)
    target_link_libraries(lac cblas)
endif(BLAS_FOUND)


install (TARGETS lac DESTINATION bin)
install (FILES MyMatrix.h DESTINATION include)
