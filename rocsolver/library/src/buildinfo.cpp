/* ************************************************************************
 * Copyright (c) 2018-2020 Advanced Micro Devices, Inc.
 * ************************************************************************ */

#include "rocblas.hpp"
#include "rocsolver.h"
#include <cstring>

#define TO_STR2(x) #x
#define TO_STR(x) TO_STR2(x)
#define VERSION_STRING                                                               \
    (TO_STR(ROCSOLVER_VERSION_MAJOR) "." TO_STR(ROCSOLVER_VERSION_MINOR) "." TO_STR( \
        ROCSOLVER_VERSION_PATCH) "." TO_STR(ROCSOLVER_VERSION_TWEAK))

/*******************************************************************************
 *! \brief   loads char* buf with the rocsolver library version. size_t len
     is the maximum length of char* buf.
 ******************************************************************************/

extern "C" rocblas_status rocsolver_get_version_string(char* buf, size_t len)
{
    static constexpr char v[] = VERSION_STRING;
    if(!buf)
        return rocblas_status_invalid_pointer;

    if(len < sizeof(v))
        return rocblas_status_invalid_size;

    memcpy(buf, v, sizeof(v));

    return rocblas_status_success;
}
