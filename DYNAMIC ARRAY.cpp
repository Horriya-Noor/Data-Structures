#include <iostream>

int main() {
    int *ptr = new int[10];
    float *marks = new float[3];
    char *name = new char[20];
  
    delete[] ptr;
    delete[] marks;
    delete[] name;

    return 0;
}