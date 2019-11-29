#pragma once 

#define CONCATENATE_DETAIL(x, y) x##y
#define CONCATENATE(x, y) CONCATENATE_DETAIL(x, y)
#define MAKE_UNIQUE_NAME(x) CONCATENATE(x, __COUNTER__)
