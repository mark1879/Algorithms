//
//  zego_log.hpp
//  LinkedList
//
//  Created by MarkWu on 2019/4/5.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef zego_log_hpp
#define zego_log_hpp

#include <stdio.h>
#include <iostream>

template<typename... Args>
std::string string_format(const std::string& format, Args&&... args)
{
    size_t size = snprintf(nullptr, 0, format.c_str(), args...) + 1;
    if (size < 0)
    {
        throw std::runtime_error("Error during formatting.");
    }
    
    std::unique_ptr<char []> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args...);
    
    return std::string(buf.get(), buf.get() + size - 1);
}

template<class T>
void log_v_print(T t)
{
    std::cout << t << std::endl;
}

template<class T>
void swap_value(T& left, T& right)
{
    T temp = left;
    left = right;
    right = temp;
}

int sum(int a, int b);

#endif /* zego_log_hpp */
