#include <iostream>
#include <string>
#include "hash.h"
#include "keywords_process.h"
#include "hash_procress.h"
#include "bi_procress.h"

using namespace std;

// ��ϣ����
void readToHashTable(HashTable<string, int> &hashTable, string fileName);
int getHashCompareCnt(HashTable<string, int> &hashTable);

// ���ֲ���

int main() {
    HashTable<string, int>hashTable;
    string fileName = "../include/hash.h";
    readToHashTable(hashTable, fileName);
    hashTable.print();
    cout << "��ϣ���ұȽϴ�����" << getHashCompareCnt(hashTable) << endl;

    cout << "------------" << endl;
    BiList<string, int>biList;
    readToBiList(biList, fileName);
    biList.print();
    cout << "���ֲ��ұȽϴ�����" << getBiListCompareCnt(biList) << endl;
}






