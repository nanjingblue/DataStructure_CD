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
    EMPTY,  // ��
    VALID,  // ��Ч
    DELETED,   // ��ɾ��
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
    unsigned int size;  // ��ЧԪ�ظ���

    void hashInsert(KeyType key, ValType valType);
    int hashFind(KeyType key);     // ��ϣ���� ���ص���ƫ����
    int hashFunc(KeyType key);    // ��ϣ����
public:
    int cnt; // ��¼��ϣ����ʱ���жϴ���
    HashTable();
    ~HashTable();
    void add(KeyType key); // ����Ľӿ� ��� key ���������� �������򴴽�
    ValType find(KeyType key); // ����Ľӿ� ��ȡkey��Ӧ��value
    void print(); // ��ӡ hashtable ����
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
    // ��ϣ������
    if (this->size >= HASHMAXSIZE) {
        std::cerr << "Hash table is full";
        exit(-1);
    }
    int offset = hashFunc(key);
    while (true) {
        // ��ǰֵ���Բ���
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
    if (offset < 0) return -2; // �ؼ��ֵ�ƫ����һ������0
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
        std::cout << "�ؼ��֣�" << data[i].key << " " << "Ƶ�ȣ�" << data[i].value << std::endl;
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
