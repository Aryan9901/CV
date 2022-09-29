#ifndef string_helper_h
#define string_helper_h

/* include standard cpp headers */
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

/* split given string with given delimiter */
extern vector<std::string> split(const string &s, char delimiter);

#endif