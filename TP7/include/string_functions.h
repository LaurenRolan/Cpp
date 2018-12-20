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

bool isSufix(string in_string, string content_string)
{
    return isPrefix(in_string.rbegin(), in_string.rend(), content_string.rbegin(), content_string.rend());
}

vector<string> split(string text, string separator)
{
    vector<string> results;
    string current = "";
    string::iterator it = text.begin();
    while(it != text.end())
    {
        if(isPrefix(separator.begin(), separator.end(), it, text.end()))
        {
            it += separator.length();
            results.push_back(current);
            current = "";
        }
        else {
            current.push_back(*it);
            ++it;
        }
    }
    results.push_back(current);
    return results;
}
#endif