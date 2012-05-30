#ifndef _TESTUTILS_HPP_
#define _TESTUTILS_HPP_ 

#include <iostream>
#include <sstream>
#include <vector>
#include "PrettyPrint.hpp"


namespace CppUnit{
    template<class X>
    struct assertion_traits<std::vector<X>>{
        static bool equal(const std::vector<X> &a, const std::vector<X> &b){
            return std::equal(a.begin(),a.end(),b.begin());
        }
        static std::string toString(const std::vector<X> &p){
            std::ostringstream o;
            o << p;
            return o.str();
        }
    };

    template<class A, class B>
    struct assertion_traits<std::pair<A,B>>{
        static bool equal(const std::pair<A,B> &a, const std::pair<A,B> &b){
            return (a.first == b.first) & (a.second == b.second);
        }
        static std::string toString(const std::pair<A,B> &p){
            std::ostringstream o;
            o << p;
            return o.str();
        }
    };
};

#endif 

