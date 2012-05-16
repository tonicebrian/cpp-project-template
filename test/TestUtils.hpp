#ifndef _TESTUTILS_HPP_
#define _TESTUTILS_HPP_ 

#include <iostream>

template<class S,class T>
std::ostream & operator<<(std::ostream & o, const std::pair<S,T> & p)
{
      return o << "(" << p.first << ", " << p.second << ")";
}

#endif 

