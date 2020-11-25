#include <iostream>
#include <chrono>
#include <random>
#include <ctime>

int searchArray(const int* values, int count_values, int value) {
                for(int i=0;i<count_values; i++) {
        if(values[i]>= value) {
            return i;
        }
    }
    return count_values;
}

int insertArray_old(int *values, int values_count, int value)
{
    int new_index = searchArray(values, values_count, value);
    // TODO: insert the specified value in the array
    for(int i =values_count;i>new_index;i--) {
        values[i]= values[i-1];
    }
    values[new_index] = value;
    return values_count+1;// TODO: return the new number of elements
}

int* insertArray(int *values, int *values_count, int value) {
    int *newArray = new int[*values_count+1];
    for(int i=0;i<*values_count;i++) {
        newArray[i]=values[i];
    }
    *values_count = insertArray_old(newArray,*values_count,value);
    delete values;
    return newArray;
}

void printArray(int *values ,int value_count) {
    for(int i =0; i<value_count;i++) {
        std::cout <<(i>0 ?  ", ":"")<<values[i];
    }
    std::cout<<std::endl;
}

    int main() {
        // TODO: initialize the array
        // Initialize our mersenne twister with a random seed
        std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
        // Create a reusable random number generator
        std::uniform_int_distribution<> generator(1, 1000000);

        std::chrono::time_point<std::chrono::system_clock> p1;
        p1 = std::chrono::system_clock::now();
        int *values={};
        int value_count =0;
        for(int i = 0; i < 25000; ++i) {
            int value = generator(mersenne);
            // TODO: insert the value into the array
           values= insertArray(values,&value_count,value);
        }
        std::chrono::time_point<std::chrono::system_clock> p2;
        p2 = std::chrono::system_clock::now();
        std::cout << "Duration: " <<
                  std::chrono::duration_cast<std::chrono::milliseconds>(p2 - p1).count()
                  << " milliseconds "<< std::endl;

        printArray(values ,value_count);
        return 0;
    }


