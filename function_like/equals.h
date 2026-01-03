#ifndef __EQUALS__
#define __EQUALS__

template<typename Arg1, typename Arg2, typename Result>
class __binary_func {
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result return_type;
};

template<class T, class U>
class equals : public __binary_func<T, U, bool> {
public:
    bool operator()(const T& arg1, const U& arg2) {
        return &arg1 == &arg2;
    }
};

#endif