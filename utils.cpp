//
// Created by ofir1 on 05-Mar-24.
//
#include "utils.h"

int Cache::calcTag(const int pc){
    return ( (pc >> (32 - this->tagSize)) );
}

//bool Cache::isValid(const int tag, const int set) {
//
//}

void Cache::updateLRU(const int set, const int way) {
    int wayCnt = lruArr[set][way];
    lruArr[set][way] = this->ways;
    for(int i =0;i<this->ways; i++){
        if(i == way)
            continue;
        if( (lruArr[set][i] > wayCnt)
            lruArr[set][i]--;
    }
}

int Cache::getLRU(const int set){
    for(int i =0;i<this->ways;i++){
        if(lruArr[set][i] == 0)
            return i;
    }
}

void Cache::replaceBlock(Block *block) {

}