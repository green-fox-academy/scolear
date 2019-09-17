#include <iostream>

void initArray(int*, int);
void getMaxAdr(int*, int);

int main()
{
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int arr[num];

    initArray(arr, num);
    
    getMaxAdr(arr, num);

    return 0;
}

void initArray(int* arr, int size)
{
    std::cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> *(arr + i);
    }
}

void getMaxAdr(int* arr, int size)
{
    int max = 0;
    int mark;
    for (int i = 0; i < size; ++i) {
        if(max < *(arr + i)){
            max = *(arr + i);
            mark = i;
        }
    }
    std::cout << "Biggest value is: " << *(arr + mark) << " at address: " << arr + mark;
}