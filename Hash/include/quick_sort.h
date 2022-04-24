//
// Created by nanjingblue on 2022/2/13.
//

#ifndef SORT_QUICK_SORT_H
#define SORT_QUICK_SORT_H
// 快速排序
template<typename T>
int Partition(T r[], int i, int j) {
    T temp = r[i];
    while (i < j) {
        while (i < j && r[j] >= temp)
            j--;
        if (i < j)
            r[i++] = r[j];
        while (i < j && r[i] <= temp)
            i++;
        if (i < j)
            r[j--] = r[i];
    }
    r[i] = temp;
    return i;
}

template<typename T>
void QuickSort(T r[], int i, int j) {
    if (i < j) {
        int p = Partition(r, i, j);
        QuickSort(r, i, p - 1);
        QuickSort(r, p + 1, j);
    }
}


#endif //SORT_QUICK_SORT_H
