/*
Create Counter class

which has an integer field value
when creating it should have a default value 0 or we can specify it when creating
    we can add(number) to this counter another whole number
    or we can add() without parameters just increasing the counter's value by one
    and we can get() the current value
    also we can reset() the value to the initial value
*/

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {

public:
    Counter();
    explicit Counter(int x);

    void add();
    void add(int x);
    int get();
    void reset();

private:
    int _initialValue;
    int _value;
};


#endif //COUNTER_COUNTER_H
