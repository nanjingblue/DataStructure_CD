#include <iostream>
#include <string>
#include "hash.h"
#include "keywords_process.h"
#include "hash_procress.h"
#include "bi_procress.h"

using namespace std;

// 哈希部分
void readToHashTable(HashTable<string, int> &hashTable, string fileName);
int getHashCompareCnt(HashTable<string, int> &hashTable);

// 二分部分

int main() {
    HashTable<string, int>hashTable;
    string fileName = "../include/hash.h";
    readToHashTable(hashTable, fileName);
    hashTable.print();
    cout << "哈希查找比较次数：" << getHashCompareCnt(hashTable) << endl;

    cout << "------------" << endl;
    BiList<string, int>biList;
    readToBiList(biList, fileName);
    biList.print();
    cout << "二分查找比较次数：" << getBiListCompareCnt(biList) << endl;
}






