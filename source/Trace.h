#ifndef TRACE_H_
#define TRACE_H_

#include <iostream>


#define TRACE_ERROR(e) { std::cout << "***ERROR*** : " << e << std::endl; }


inline void TRACE_DEBUG()
{
    std::cout << std::endl;
}

template<typename First, typename ... Types>
inline void TRACE_DEBUG(First first, Types ... rest)
{
    std::cout << first << " ";
    TRACE_DEBUG(rest...);
}

#endif
