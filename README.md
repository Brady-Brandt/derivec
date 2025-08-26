# Derivec
Derivec is a header-only library that can be used to print out structs and unions on linux. 
It was created to provide a quick way to debug programs by allowing the user to print a a struct/union and its members without defining a new function.

## Requirements
- 64-bit Linux
- Compile with debug symbols
- Dwarf Version 5 Debug Symbols (Current default for clang and gcc on Linux)
- Dwarf 32-bit (Should be the default if your application is less than 2 GB)

## Things to Note
- Only structs or unions can be passed to derivec_debug (Passing the wrong type or pointer is undefined)
- Struct member arrays do not work yet (Only the first element will get printed)
- char* are treated as strings and will be printed as strings if not null
- Pointer types (except char*) will be printed as a pointer. They will not be dereferenced
- If a char* exists within a union it will be printed as a pointer

## Example
```c
#include <stdint.h>
#include <stdbool.h>
#define DERIVEC_IMPLEMENTATION
#include "derivec.h"

typedef enum {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;

typedef struct{
    int day;
    Month month;
} Birthday;

typedef struct {
    char* name;
    char* breed;
    int age; 
} Dog;

typedef struct{
    char* first_name;
    char* last_name;
    uint32_t age;
    double weight;
    bool isMale;
    Birthday bday;
    Dog pet;
} Person;



int main(int argc, char** argv){
    //pass the path to the executable to derivec_init
    //easiest to just use the first arg of argv
    if(!derivec_init(argv[0])) return 1;
 
    Person person;
    person.first_name = "John";
    person.last_name = "Doe";
    person.age = 25;
    person.weight = 140;
    person.isMale = true;
    person.bday.month = JUNE;
    person.bday.day = 1;
    person.pet = (Dog){"Max", "Golden Retriever", 5};

    //pass in the type and a pointer to the struct
    derivec_debug(Person, &person);

    derivec_terminate();
}
```

### Output
```sh
Person {
    first_name: John
    last_name: Doe
    age: 25
    weight: 140.000000
    isMale: true
    bday: Birthday {
        day: 1
        month: JUNE
    }
    pet:  Dog {
        name: Max
        breed: Golden Retriever
        age: 5
    }
 }
```
