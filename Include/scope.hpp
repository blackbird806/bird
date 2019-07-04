#pragma once

#include <utility>
#include "macrosUtility.h"
#include "birdConfig.hpp"

BIRD_NAMESPACE_START

// composed scope
template <class Functor>
struct scope
{
    scope(Functor&& t) : func(std::move(t)) {};

	~scope()
	{
		func();
	}

    private:

	Functor func;
};

// other techniques with simple and multiple inheritance (proof of concept)

template <typename B>
struct inherited_scope : public B
{
	template <typename T>
	inherited_scope(T&& t) : B(std::forward<T>(t))
	{

	}

	~inherited_scope()
	{
		B::operator()();
	}

};

template<typename T>
inherited_scope(T)->inherited_scope<std::decay_t<T>>;

template<typename ...B>
struct multiple_inherited_scope : public B...
{
    template <typename ...T>
	multiple_inherited_scope(T&& ... t) : B(std::forward<T>(t))...
	{

	}

	~multiple_inherited_scope()
	{
		(B::operator()(), ...);
	}
};

template<typename ...T>
multiple_inherited_scope(T...)->multiple_inherited_scope<std::decay_t<T>...>;

BIRD_NAMESPACE_END

// utility macro
#ifdef BIRD_ENABLE_NAMESPACE
    #define SCOPE(...) ::bird::scope MAKE_UNIQUE(SCOPE__) {[&](){ __VA_ARGS__; }}
#else
    #define SCOPE(...) scope MAKE_UNIQUE(SCOPE__) {[&](){ __VA_ARGS__; }}
#endif

