#ifndef _PRETTY_PRINT_HPP_
#define _PRETTY_PRINT_HPP_ 
#include <iostream>
#include <utility>
#include <map>
#include <sstream>
#include <vector>

template<class S,class T>
std::ostream& operator<<(std::ostream & o, const std::pair<S,T> & p)
{
      return o << "(" << p.first << ", " << p.second << ")";
}

template<class X>
std::ostream& operator<<(std::ostream & o, const std::vector<X> & p){
    o << "[";
    for(typename std::vector<X>::const_iterator it=p.begin(); it!=p.end();++it){
        o << *it << " ";
    }
    o << "]";
    return o;
};

template<class K, class V> 
std::ostream& operator<<(std::ostream& o, const std::map<K,V> & m){
    o << "{ ";
    for(typename std::map<K,V>::const_iterator it=m.begin();it!=m.end();it++){ 
       o << "{" << it->first <<": " << it->second << "} ";
    }
    o << " }";
    return o;
};


#endif 
