// binary_search.h
#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H




#include <iostream>
#include <string>
#include <algorithm> // For std::sort

template <class T>


int BinarySearch(T ptr, int Lo, int Hi, std::string data)
{
    int Mid;
    if (Lo <= Hi)
    {
	Mid = (Lo + Hi) / 2;
	if (ptr[Mid] > data)
	    return BinarySearch(ptr, Lo, Mid - 1, data);
	else if (ptr[Mid] < data)
	    return BinarySearch(ptr, Mid + 1, Hi, data);
	else
	    return Mid;
    }
    return -1;
}
/*int BinarySearch(T ptr, int Lo, int Hi, std::string data)
{
    if (Lo <= Hi)
    {
        int Mid = Lo + (Hi - Lo) / 2; // Avoids overflow compared to (Lo + Hi) / 2
        if (ptr[Mid] > data)
            return BinarySearch(ptr, Lo, Mid - 1, data);
        else if (ptr[Mid] < data)
            return BinarySearch(ptr, Mid + 1, Hi, data);
        else
            return Mid;
    }
    return -1;
}*/




#endif // BINARYSEARCH_HPP
