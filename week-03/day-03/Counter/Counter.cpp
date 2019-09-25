#include "Counter.h"

Counter::Counter() {
    _initialValue = 0;
    _value = _initialValue;
}

Counter::Counter(int x) {
    _initialValue = x;
    _value = x;
}

void Counter::add() {
    _value++;
}

void Counter::add(int x) {
    _value += x;
}

int Counter::get() {
    return _value;
}

void Counter::reset() {
    _value = _initialValue;
}