#!/bin/bash
set -o noclobber

make_hpp(){
echo "#pragma once
#include <iostream>

class $1{
    public:
        virtual ~$1(void);
    protected:
    private:
        $1(void);
        $1(const $1 & instance);
        $1 operator=(const $1 & instance);
};" > $1.hpp
}

for file in $@ 
    do
        name=${file%.*}

        echo -e '#include "'$name'.hpp"' > $name.cpp
        make_hpp $name
    done

