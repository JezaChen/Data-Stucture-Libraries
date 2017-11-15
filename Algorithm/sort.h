//
// Created by jeza on 17-10-23.
//

#ifndef DSL_SORT_H
#define DSL_SORT_H

#include <algorithm>
#include "Share.h"

typedef int rank;

namespace DSLibrary
{
    using std::swap;
    using std::fill;

    template<typename T, typename COMP>
    void insertSort(T *elem, int size)
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i; j > 0 && COMP::priority(elem[j], elem[i]); j--)
            {
                swap(elem[i], elem[j]);
            }
        }
    }

    template<typename T, typename COMP>
    void bubbleSort(T *elem, int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j--)
            {
                if (COMP::priority(elem[j - 1], elem[j]))
                    swap(elem[j - 1], elem[j]);
            }
        }
    }

    template<typename T, typename COMP>
    void selectSort(T *elem, int size)
    {
        for (int i = 0; i < size; i++)
        {
            int point = i;
            for (int j = i; j < size; j++)
            {
                if (COMP::priority(elem[j], elem[i]))
                {
                    point = j;
                }
            }
            swap(elem[i], elem[point]);
        }
    }


    //DEFINE MERGE SORT
    template<typename T, typename COMP>
    void mergeSort(T *elem, int size);

    template<typename T, typename COMP>
    void mergeHelp(T *elem, const int &lo, const int &hi)
    {
        if (lo + 1 == hi) return;

        int mid = (hi + lo) / 2;

        mergeHelp(elem, lo, mid);
        mergeHelp(elem, mid, hi);

        T temp[lo - hi];
        for (int i = 0; i < mid; i++) temp[i] = elem[i];
        for (int i = lo - hi + 1, j = mid; i >= mid && j < hi; i--, j++)
            temp[i] = elem[j];

        int i = 0, j = hi - 1;
        for (int k = 0; k < hi; k++)
        {
            if (COMP::priority(temp[i], temp[j]))
            {
                elem[k] = temp[i++];
            }
            else
                elem[k] = temp[j--];
        }
    }
    //END OF MERGE SORT

    //DEFINE QUICK SORT
    template<typename T, typename COMP>
    int findPartition(T *elem, const int &lo, const int &hi)
    {
        int _lo = lo, _hi = hi;
        int partition = elem[(_lo + _hi) / 2];

        swap(elem[_lo], elem[partition]);

        while (_hi - _lo > 1)
        {
            while (COMP::priority(elem[hi], elem[lo]) && _hi - _lo > 1)
            { _hi--; }
            swap(elem[_lo], elem[_hi]);
            while (COMP::priority(elem[hi], elem[lo]) && _hi - _lo > 1)
            { _lo++; }
            swap(elem[_lo], elem[_hi]);
        }

        return partition;
    }

    template<typename T, typename COMP>
    void quickSort(T *elem, const int &lo, const int &hi)
    {
        if (hi - lo <= 1) return;
        else
        {
            int p = findPartition(elem, lo, hi);
            quickSort(elem, lo, p);
            quickSort(elem, p, hi);
        }
    }

}
#endif //DSL_SORT_H
