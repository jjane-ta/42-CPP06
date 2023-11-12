#!/bin/sh

if [ $# != 2 ]; then return 1; fi
old=${1%.*}
new=${2%.*}

sed s/$old/$new/g $old.hpp > $new.hpp
sed s/$old/$new/g $old.cpp > $new.cpp
