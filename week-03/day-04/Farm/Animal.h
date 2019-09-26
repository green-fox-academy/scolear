#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H

class Animal {
public:
    Animal();
    Animal(int hunger, int thirst);

    void eat();
    void drink();
    void play();

    int getThirst() const;

    int getHunger() const;

private:
    int _hunger;
    int _thirst;
};


#endif //ANIMAL_ANIMAL_H
