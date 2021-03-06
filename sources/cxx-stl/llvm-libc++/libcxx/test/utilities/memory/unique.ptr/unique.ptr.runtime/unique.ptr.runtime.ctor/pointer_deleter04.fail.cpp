//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// unique_ptr

// Test unique_ptr(pointer, deleter) ctor

// unique_ptr<T, const D&>(pointer, D()) should not compile

#include <memory>
#include <cassert>

struct A
{
    static int count;
    A() {++count;}
    A(const A&) {++count;}
    ~A() {--count;}
};

int A::count = 0;

class Deleter
{
    int state_;

public:

    Deleter() : state_(5) {}

    int state() const {return state_;}
    void set_state(int s) {state_ = s;}

    void operator()(A* p) const {delete [] p;}
};

int main()
{
    {
    A* p = new A[3];
    assert(A::count == 3);
    std::unique_ptr<A[], const Deleter&> s(p, Deleter());
    assert(s.get() == p);
    assert(s.get_deleter().state() == 5);
    }
    assert(A::count == 0);
}
