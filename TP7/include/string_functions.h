/* Author: Lauren Rolan
 * File: string_functions.h
 */
#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <iostream> //Debug
#include <vector>
#include <cstring>

using namespace std;

template <typename T>
bool isPrefix(T begA, T endA, T begB, T endB)
{
    while(begA != endA && begB != endB)
    {
        if(*begA == *begB)
        {
            ++begA;
            ++begB;
        }
        else {
            return false;
        }
    }
    return true;
}

bool isSufix(string in_string, string content_string);

vector<string> split(string text, string separator);

#endif