#pragma once
#include <iostream>
#include <stdint.h>

struct Data
{
    char c;
    int i;
    float f;
    double d;
};


class Serializer{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    protected:
    private:
        Serializer(void);
        Serializer(const Serializer & instance);
        Serializer operator=(const Serializer & instance);
        virtual ~Serializer(void);
};
