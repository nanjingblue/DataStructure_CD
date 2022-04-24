//
// Created by nanjingblue on 2022/2/18.
//

#ifndef HASH_HASH_H
#define HASH_HASH_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include "quick_sort.h"

#define HASHMAXSIZE 41

typedef enum {
    EMPTY,  // 空
    VALID,  // 有效
    DELETED,   // 被删除
} State;

template <typename T1, typename T2>
struct HashNode{
    T1 key;
    T2 value;
    State stat;
    bool operator>(const HashNode<T1, T2> &temp) {
        return value > temp.value;
    }
    bool operator<(const HashNode<T1, T2> &temp) {
        return value < temp.value;
    }
    bool operator==(const HashNode<T1, T2> &temp) {
        return value == temp.value;
    }
    bool operator>=(const HashNode<T1, T2> &temp) {
        return value >= temp.value;
    }
    bool operator<=(const HashNode<T1, T2> &temp) {
        return value <= temp.value;
    }
};

template <typename KeyType, typename ValType>
class HashTable {
public:
    HashNode<KeyType, ValType> *data;
private:
    unsigned int size;  // 有效元素个数

    void hashInsert(KeyType key, ValType valType);
    int hashFind(KeyType key);     // 哈希查找 返回的是偏移量
    int hashFunc(KeyType key);    // 哈希函数
public:
    int cnt; // 记录哈希查找时的判断次数
    HashTable();
    ~HashTable();
    void add(KeyType key); // 对外的接口 如果 key 存在则自增 不存在则创建
    ValType find(KeyType key); // 对外的接口 获取key对应的value
    void print(); // 打印 hashtable 详情
    void hashSort();
};

template<typename T1, typename T2>
HashTable<T1, T2>::HashTable() {
    data = new HashNode<T1, T2>[HASHMAXSIZE];
    if (!data) {
        std::cerr << "Memory allocation failure";
        exit(-1);
    }
    size = 0;
    cnt = 0;
    for (int i = 0; i < HASHMAXSIZE; ++i) {
        data[i].stat = EMPTY;
        data[i].value = 0;
    }
}

template<typename KeyType, typename ValType>
HashTable<KeyType, ValType>::~HashTable() {
    delete[] data;
}

template<typename KeyType, typename ValType>
int HashTable<KeyType, ValType>::hashFunc(KeyType key) {
    return (((key[0] - 'a') * 100) + (key[key.length() - 1] - 'a')) % 41;
}

template<typename KeyType, typename ValType>
void HashTable<KeyType, ValType>::hashInsert(KeyType key, ValType val) {
    // 哈希表已满
    if (this->size >= HASHMAXSIZE) {
        std::cerr << "Hash table is full";
        exit(-1);
    }
    int offset = hashFunc(key);
    while (true) {
        // 当前值可以插入
        if (this->data[offset].stat != VALID) {
            this->data[offset].stat = VALID;
            this->data[offset].key = key;
            this->data[offset].value = val;
            this->size++;
            return;
        } else {
            ++offset;
            if (offset >= HASHMAXSIZE)
                offset = 0;
        }
    }
}

template<typename KeyType, typename ValType>
int HashTable<KeyType, ValType>::hashFind(KeyType key) {
    if (this->size == 0) {
        return -1;
    }
    int offset = hashFunc(key);
    if (offset < 0) return -2; // 关键字的偏移量一定大于0
    while (true) {
        this->cnt++;
        if (this->data[offset].key == key && this->data[offset].stat == VALID) {
            return offset;
        } else if(this->data[offset].stat != VALID) {
            return -1;
        } else {
            offset++;
            if (offset >= HASHMAXSIZE)
                offset = 0;
        }
    }
}

template<typename KeyType, typename ValType>
void HashTable<KeyType, ValType>::print() {
    this->hashSort();
    for (int i = 0; i < HASHMAXSIZE; ++i) {
        if (data[i].stat != VALID) continue;
        std::cout << "关键字：" << data[i].key << " " << "频度：" << data[i].value << std::endl;
    }
}

template<typename KeyType, typename ValType>
void HashTable<KeyType, ValType>::add(KeyType key) {
    int offset = hashFind(key);
    if (offset >= 0) {
        this->data[offset].value++;
    } else {
        this->hashInsert(key, 1);
    }
}

template<typename KeyType, typename ValType>
ValType HashTable<KeyType, ValType>::find(KeyType key) {
    int offset = hashFind(key);
    if (offset >= 0) {
        return data[offset].value;
    } else {
        return -1;
    }
}

template<typename KeyType, typename ValType>
void HashTable<KeyType, ValType>::hashSort() {
    QuickSort(data, 0, HASHMAXSIZE - 1);
}


#endif //HASH_HASH_H
