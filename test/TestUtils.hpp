#ifndef _TESTUTILS_HPP_
#define _TESTUTILS_HPP_ 

#include <iostream>
#include <utility>
#include <map>
#include <sstream>


template<class S,class T>
std::ostream& operator<<(std::ostream & o, const std::pair<S,T> & p)
{
      return o << "(" << p.first << ", " << p.second << ")";
}

template<class K, class V> 
std::ostream& operator<<(std::ostream& o, const std::map<K,V> & m){
    o << "{ ";
    for(auto it=m.begin();it!=m.end();it++){ 
       o << "{" << it->first <<": " << it->second << "} ";
    }
    o << " }";
    return o;
}


#endif 

