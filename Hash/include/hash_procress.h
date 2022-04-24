//
// Created by nanjingblue on 2022/2/21.
//

#ifndef HASH_HASH_PROCRESS_H
#define HASH_HASH_PROCRESS_H

#include <iostream>
#include <ctime>
#include "hash.h"
#include "keywords_process.h"

using namespace std;

namespace Hash {
    void readToHashTable(HashTable<string, int> &hashTable,string fileName) {
        ifstream ifs(fileName, ios::in);
        if (!ifs) {
            cerr << "open file err";
        }
        char c;
        string keyword;
        while (!ifs.eof()) {
            keyword = "";
            filterComments(ifs, c);
            // 过滤完注释开始找关键字
            if (!isAlphabet(c) && !ifs.eof()) {
                ifs.get(c);
                continue;
            }
            while (isAlphabet(c) && !ifs.eof()) {
                keyword += c;
                ifs.get(c);
            }
            // 纯字母段读取完毕 如果是关键字 则加入hashtable 否则继续往下读
            if (isKeyword(keyword)) {
                hashTable.add(keyword);
            }
        }
    }

    int getHashCompareCnt(HashTable<string, int> &hashTable) {
        hashTable.cnt = 0;
        for (int i = 0; i < keyNums; ++i) {
            hashTable.find(KeyWords[i]);
        }
        return hashTable.cnt;
    }

    double getHashCompareTime(HashTable<string, int> &hashTable) {
        clock_t start = clock();
        for (int i = 0; i < keyNums; ++i) {
            hashTable.find(KeyWords[i]);
        }
            clock_t end = clock();
            return (double)(end - start) / CLOCKS_PER_SEC;
       }
}


#endif //HASH_HASH_PROCRESS_H
