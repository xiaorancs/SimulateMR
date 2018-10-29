/**
 * Author: xiaoran
 * Time: 2018-10-29
 * 
 * hash.h in SimulateMR
 * Copyright (c) 2018, xiaoran. All rights reserved.
 **/ 

#ifndef _hash_h
#define _hash_h

#include <string>
#include <cstring>

const unsigned int BIG_MOD = 1000003;

inline unsigned int hash_code(std::string&& key) {
    unsigned int value = 0;
    for(int i = 0; i < key.size(); i++) {
        value = value * 31 + (unsigned int) key[i];
        value %= BIG_MOD;
    }
    return value;
}

inline unsigned int hash_code(const char* key) {
    unsigned int value = 0;
    if(key == NULL) return value;
    while(*key != '\0'){
        value = value * 31 + (unsigned int) *key++;
        value %= BIG_MOD;
    }
    return value;
}

inline unsigned int hash_code(int key) {
    int value = 0;
    if(key < 0) value = -1 * key;
    else value = key;
    return value % BIG_MOD;
}

#endif /* _hash_h */