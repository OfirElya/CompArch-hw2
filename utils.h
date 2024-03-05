//
// Created by ofir1 on 05-Mar-24.
//

#include <vector>
#include <stdlib.h>
#include <memory>

using namespace std::unique_ptr;

#ifndef COMPARCH_HW2_UTILS_H
#define COMPARCH_HW2_UTILS_H





class Block {
private:
    int tag;
    bool dirty;
    bool valid;
    vector<int> data;

public:

    Block(int tag, int blockSize);
    ~Block();//TODO: delete properly
    Block(const Block& block)= default;
    Block &operator=(const Block& block)= default;

};


class Cache {
private:
    int sets;
    int blockSize;
    int ways;
    int cycles;
    bool writeAllocate;
    int tagSize;
    vector<vector<Block>> blocksArr;
    vector<vector<int>> lruArr;

public:

    Cache(int sets, int blockSize, int ways, int cycles, bool writeAllocate);
    ~Cache();//TODO: delete
    Cache(const Cache& cache)= default;
    Cache &operator=(const Cache& cache)= default;

    void replaceBlock(Block* block);
    void insertData(int tag, int set,int offset, int data);
    bool isDirty(const int tag, const int set);
    bool isValid(const int tag, const int set);
    int updateLRU(const int set, const int way);
    int getLRU(const int set);
    int calcTag(const int pc);
};


#endif //COMPARCH_HW2_UTILS_H
