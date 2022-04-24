//
// Created by nanjingblue on 2022/2/21.
//

#ifndef HASH_DICHOTOMOUS_METHOD_H
#define HASH_DICHOTOMOUS_METHOD_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include "hash.h"
#include "keywords_process.h"

using namespace std;


template <typename T1, typename T2>
struct BiNode {
    T1 key;
    T2 value;
    int cnt;
    bool operator>(const BiNode<T1, T2> &temp) {
        return value > temp.value;
    }
    bool operator<(const BiNode<T1, T2> &temp) {
        return value < temp.value;
    }
    bool operator==(const BiNode<T1, T2> &temp) {
        return value == temp.value;
    }
    bool operator>=(const BiNode<T1, T2> &temp) {
        return value >= temp.value;
    }
    bool operator<=(const BiNode<T1, T2> &temp) {
        return value <= temp.value;
    }
};

template <typename KeyType, typename ValType>
class BiList {
public:
    BiNode<KeyType, ValType> * data;
    int cnt;
    BiList() {
        this->data = new BiNode<std::string, int>[HASHMAXSIZE];
        this->cnt = 0;
        for (int i = 0; i < HASHMAXSIZE; ++i) {
            data[i].key = KeyWords[i];
            data[i].value = 0;
        }
    }
    void add(KeyType key);
    void toSort();
    void print();
    ValType find(KeyType key);
};

template<typename KeyType, typename ValType>
void BiList<KeyType, ValType>::add(KeyType key) {
    for (int i = 0; i < HASHMAXSIZE; ++i) {
        if (data[i].key == key)
            data[i].value++;
    }
}

template<typename KeyType, typename ValType>
void BiList<KeyType, ValType>::toSort() {
    QuickSort(data, 0,  HASHMAXSIZE - 1);
}

template<typename KeyType, typename ValType>
void BiList<KeyType, ValType>::print() {
    this->toSort();
    for (int i = 0; i < HASHMAXSIZE; ++i) {
        if (data[i].value)
            cout << "关键字：" << data[i].key << " 频度：" << data[i].value << endl;
    }
}

template<typename KeyType, typename ValType>
ValType BiList<KeyType, ValType>::find(KeyType key) {
    int lo = 0;
    int hi = HASHMAXSIZE - 1;
    while (lo <= hi) {
        this->cnt++;
        int mid = (lo + hi) / 2;
        if (data[mid].key == key) {
            return data[mid].value;
        } else if (data[mid].key < key) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}


void readToBiList(BiList<string, int> biList, string fileName) {
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
            biList.add(keyword);
        }
    }
}

int getBiListCompareCnt(BiList<string, int> &biList) {
    biList.cnt = 0;
    for (int i = 0; i < keyNums; ++i) {
        biList.find(KeyWords[i]);
    }
    return biList.cnt;
}

double getBiListCompareTime(BiList<string, int> &biList) {
    clock_t startTime = clock();
    for (int i = 0; i < keyNums; ++i) {
        biList.find(KeyWords[i]);
    }
    clock_t endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

#endif //HASH_DICHOTOMOUS_METHOD_H
