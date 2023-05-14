#include "lynx.hh"
#include <concepts>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template <class T>
concept Integral = std::is_integral<T>::value;

using namespace std;

template <typename T> LynxQuery &LynxQuery::With(LynxType type, T data) {
    if constexpr (is_integral<T>::value) {
        cout << "this is an int " << data;
    } else {
        cout << "this is a string " << data;
    }
    cout << endl;
}

void LynxQuery::Reset() {
    // reset stuff
}

namespace {
vector<LynxData> s_data;
LynxQuery s_query;
}; // namespace

void Lynx::Load() {}

// add
void Lynx::Add(string title, string url) { cout << "Added \n"; }

bool Lynx::Affect() {
    // do query here

    return true;
}

// delete
template <class T> void Lynx::Remove(LynxType type, T payload) {
    s_query.With(type, payload);
    if (Affect()) {
        cout << "removed \n";
    } else {
        cout << "don't removed\n";
    }
    s_query.Reset();
}
