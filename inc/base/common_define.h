/*********************************************************************
 * cclib-common
 *
 * Copyright (c) 2019 cclib-common contributors:
 *   - hello_chenchen <https://github.com/hello-chenchen>
 *
 * MIT License <https://github.com/cc-libraries/cclib-common/blob/master/LICENSE>
 * See https://github.com/cc-libraries/cclib-common for the latest update to this file
 *
 * author: hello_chenchen <https://github.com/hello-chenchen>
 **********************************************************************************/
#ifndef CCLIB_COMMON_DEFINE_H
#define CCLIB_COMMON_DEFINE_H

#define CC_NULL 0
#define CC_SUCCESS 1
#define CC_FAILED 0
#define CC_INVALID -1
#define CC_INIT 0

// Definitions of common types
#ifdef _CC_DEF_64
    typedef unsigned long long int cc_size_t;
#else
    typedef unsigned int     cc_size_t;
#endif //_CC_DEF_64

#define IS_POINT_NULL_POINT(point) \
if(CC_NULL == point) {\
    return CC_NULL;\
}\

#define IS_POINT_NULL_INT(point) \
if(CC_NULL == point) {\
    return CC_FAILED;\
}\

#define IS_POINT_NULL_UINT(point) \
if(CC_NULL == point) {\
    return CC_FAILED;\
}\

#define MAX_VALUE(a, b) a > b ? a : b;

#define MIN_VALUE(a, b) a < b ? a : b;

#endif //CCLIB_COMMON_DEFINE_H