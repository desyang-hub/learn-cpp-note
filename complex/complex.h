/**
 * @FilePath     : /cpp/complex/complex.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2025-12-27 13:00:10
 * @LastEditors  : desyang
 * @LastEditTime : 2025-12-27 13:24:52
**/
#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>

class complex {
public:
    complex(const double& real=0, const double& imag=0) :
        re(real), im(imag){

        }

    double real() const {
        return re;
    }

    friend double real(const complex& comp) {
        return comp.re;
    }

    friend double imag(const complex& comp) {
        return comp.im;
    }

    double imag() const {
        return im;
    }

    complex& operator+=(const complex& comp);

private:
    double re;
    double im;

    friend complex& __doapl(complex& ths, const complex& comp) {
        ths.im += comp.im;
        ths.im += comp.im;
        return ths;
    }
};

// complex += complex
inline complex& complex::operator+=(const complex& comp) {
        return __doapl(*this, comp);
}

// cout << complex
std::ostream& operator<<(std::ostream& os, const complex& comp) {
    return os << '(' << real(comp) << ',' << imag(comp) << 'i' << ')';
}

// complex + complex
complex operator+(const complex& c1, const complex& c2) {
    return complex{c1.real()+c2.real(), c1.imag()+c2.imag()};
}

// num + complex
complex operator+(const double& num, const complex& comp) {
    return complex{num+comp.real(), comp.imag()};
}

complex operator+(const complex& comp, const double& num) {
    return complex{num+comp.real(), comp.imag()};
}

// complex - complex
complex operator-(const complex& c1, const complex& c2) {
    return complex{c1.real()-c2.real(), c1.imag()-c2.imag()};
}

// num - complex
complex operator-(const double& num, const complex& c2) {
    return complex{num - real(c2), -imag(c2)};
}

// complex - num
complex operator-(const complex& c1, const double& num) {
    return complex{real(c1)-num, imag(c1)};
}


// +complex
complex operator+(const complex& comp) {
    return comp;
}

// -complex
complex operator-(const complex& comp) {
    return complex{-real(comp), -imag(comp)};
}

// conjugate
complex comjugate(const complex& comp) {
    return {real(comp), -imag(comp)};
}

#endif // __COMPLEX_H__