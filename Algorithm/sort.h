//
// Created by jeza on 17-10-23.
//

#ifndef DSL_SORT_H
#define DSL_SORT_H

#include <algorithm>
#include "Share.h"
#include "../Stack/Linked_Stack.h"
#include "../List/List.h"
#include "../List/AList.h"
#include "../Priority Queue/Heap.h"

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
            for (int j = i; j > 0 && COMP::priority(elem[j], elem[j - 1]); j--)
            {
                swap(elem[j], elem[j - 1]);
            }
        }
    }

    template<typename T, typename COMP>
    void insertSort(T *elem, int lo, int hi)
    {
        for (int i = lo + 1; i <= hi; i++)
        {
            for (int j = i; j > lo && COMP::priority(elem[j], elem[j - 1]); j--)
                swap(elem[j], elem[j - 1]);
        }
    };

    template<typename T, typename COMP>
    void bubbleSort(T *elem, int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j--)
            {
                if (COMP::priority(elem[j], elem[j - 1]))
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
                if (COMP::priority(elem[j], elem[point]))
                {
                    point = j;
                }
            }
            swap(elem[i], elem[point]);
        }
    }


    //DEFINE MERGE SORT

    template<typename T, typename COMP>
    void mergeSortI(T elem[], T temp[], int lo, int hi)
    {
        if (lo == hi) return;
        int mid = (lo + hi) / 2;
        mergeSortI<T, COMP>(elem, temp, lo, mid);
        mergeSortI<T, COMP>(elem, temp, mid + 1, hi);

        for (int i = lo; i <= hi; i++)
            temp[i] = elem[i];

        int i1 = lo, i2 = mid + 1;
        for (int k = lo; k <= hi; k++)
        {
            if (i1 == mid + 1)
                elem[k] = temp[i2++];
            else if (i2 == hi + 1)
                elem[k] = temp[i1++];
            else
            {
                if (COMP::priority(temp[i1], temp[i2]))
                    elem[k] = temp[i1++];
                else elem[k] = temp[i2++];
            }
        }
    };

    template<typename T, typename COMP>
    void mergeSortII(T elem[], T temp[], int lo, int hi)
    {
        if (lo == hi) return;
        int mid = (lo + hi) / 2;
        mergeSortII<T, COMP>(elem, temp, lo, mid);
        mergeSortII<T, COMP>(elem, temp, mid + 1, hi);

        for (int i = lo; i <= mid; i++)
            temp[i] = elem[i];
        //reverse
        for (int j = 1; j <= hi - mid; j++)
            temp[hi - j + 1] = elem[mid + j];
        for (int i = lo, j = hi, k = lo; k <= hi; k++)
        {
            if (COMP::priority(temp[i], temp[j]))
                elem[k] = temp[i++];
            else
                elem[k] = temp[j--];
        }
    };

    template<typename T, typename COMP>
    void mergeSort(Alist<T> &elem)
    {
        if (elem.size() == 1) return;

        int mid = (elem.size() - 1) / 2;
        Alist<T> leftHalf(elem, 0, mid);
        Alist<T> rightHalf(elem, mid + 1, elem.size() - 1);

        mergeSort(leftHalf);
        mergeSort(rightHalf);

        leftHalf.moveToStart();
        rightHalf.moveToStart();
        elem.moveToStart();

        for (int k = 0; k < elem.size(); k++)
        {
            if (leftHalf.currentPosi() == leftHalf.size())
            {
                elem[k] = rightHalf.getValue();
                rightHalf.next();
            }
            else if (rightHalf.currentPosi() == rightHalf.size())
            {
                elem[k] = leftHalf.getValue();
                leftHalf.next();
            }
            else
            {
                if (COMP::priority(leftHalf.getValue(), rightHalf.getValue()))
                {
                    elem[k] = leftHalf.getValue();
                    leftHalf.next();
                }
                else
                {
                    elem[k] = rightHalf.getValue();
                    rightHalf.next();
                }
            }
        }
    };

    template<typename T, typename COMP>
    void mergeSort(Single_Linked::Llist<T> &elem)
    {
        if (elem.size() == 1) return;

        int mid = (elem.size() - 1) / 2;
        Single_Linked::Llist<T> leftHalf(elem, 0, mid);
        Single_Linked::Llist<T> rightHalf(elem, mid + 1, elem.size() - 1);

        mergeSort(leftHalf);
        mergeSort(rightHalf);

        leftHalf.moveToStart();
        rightHalf.moveToStart();
        elem.moveToStart();

        for (int k = 0; k < elem.size(); k++)
        {
            if (leftHalf.currentPosi() == leftHalf.size())
            {
                elem[k] = rightHalf.getValue();
                rightHalf.next();
            }
            else if (rightHalf.currentPosi() == rightHalf.size())
            {
                elem[k] = leftHalf.getValue();
                leftHalf.next();
            }
            else
            {
                if (COMP::priority(leftHalf.getValue(), rightHalf.getValue()))
                {
                    elem[k] = leftHalf.getValue();
                    leftHalf.next();
                }
                else
                {
                    elem[k] = rightHalf.getValue();
                    rightHalf.next();
                }
            }
        }
    };

    template<typename T, typename COMP>
    void mergeSort(Double_Linked::Llist<T> &elem)
    {
        if (elem.size() == 1) return;

        int mid = (elem.size() - 1) / 2;
        Double_Linked::Llist<T> leftHalf(elem, 0, mid);
        Double_Linked::Llist<T> rightHalf(elem, mid + 1, elem.size() - 1);

        mergeSort<T, COMP>(leftHalf);
        mergeSort<T, COMP>(rightHalf);

        leftHalf.moveToStart();
        rightHalf.moveToStart();
        elem.moveToStart();

        for (int k = 0; k < elem.size(); k++)
        {
            if (leftHalf.currentPosi() == leftHalf.size())
            {
                elem[k] = rightHalf.getValue();
                rightHalf.next();
            }
            else if (rightHalf.currentPosi() == rightHalf.size())
            {
                elem[k] = leftHalf.getValue();
                leftHalf.next();
            }
            else
            {
                if (COMP::priority(leftHalf.getValue(), rightHalf.getValue()))
                {
                    elem[k] = leftHalf.getValue();
                    leftHalf.next();
                }
                else
                {
                    elem[k] = rightHalf.getValue();
                    rightHalf.next();
                }
            }
        }
    };

    template<typename T, typename COMP>
    void mergeSort(T elem[], int size)
    {
        T temp[size];
        mergeSortI<T, COMP>(elem, temp, 0, size - 1);
    };

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
    inline int partition(T A[], int lo, int hi, const T &pivot)
    {
        while (lo < hi)
        {
            while ((lo < hi) && COMP::priority(A[++lo], pivot));
            while ((lo < hi) && (COMP::priority(pivot, A[--hi])));
            swap(A[lo], A[hi]);
        };
        return lo;
    };

    template<typename T, typename COMP>
    inline int partition_Ave(T A[], int lo, int hi, const double &ave)
    {
        while (lo < hi)
        {
            while (lo < hi && (COMPARE_LESS<double>::priority((double) A[lo], ave) || abs(A[lo] - ave) <= 1e-6))
            {
                lo++;
            }
            while (lo < hi && (COMPARE_LESS<double>::priority(ave, (double) A[hi]) || abs(A[hi] - ave) <= 1e-6))
            {
                hi--;
            }
            if (lo <= hi)
                swap(A[lo], A[hi]);
            else break;
        }
        return hi;
    };

    template<typename T>
    inline int findPivot(const T A[], int lo, int hi)
    {
        return (lo + hi) / 2;
    };

    template<typename T>
    inline double findPivot_Average(const T A[], int lo, int hi)
    {
        long long sum = 0;
        // if (hi < lo) return sum;
        for (int i = lo; i <= hi; i++)
            sum += A[i];
        return (double) sum / (hi - lo + 1);
    };

    template<typename T, typename COMP>
    void quickSort(T A[], int lo, int hi)
    {
        if (lo >= hi) return;
        int pivotIndex = findPivot(A, lo, hi);
        swap(A[pivotIndex], A[hi]);

        int k = partition<T, COMP>(A, lo - 1, hi, A[hi]);
        swap(A[k], A[hi]);

        quickSort<T, COMP>(A, lo, k - 1);
        quickSort<T, COMP>(A, k + 1, hi);
    };

    template<typename T, typename COMP>
    void quickSort_Ave(T A[], int lo, int hi)
    {
        if (lo >= hi) return;

        double pivot = findPivot_Average(A, lo, hi);
        int k = partition_Ave<T, COMP>(A, lo, hi, pivot);

        if (lo <= k && k <= hi) //论文错了...
        {
            quickSort_Ave<T, COMP>(A, lo, k - 1);
            quickSort_Ave<T, COMP>(A, k, hi);
        }
    };

    template<typename T, typename COMP = COMPARE_LESS<int> >
    void quickSort_I(T A[], int lo, int hi) //快速排序迭代实现
    {
        Single_Linked::LStack<int> S_lo, S_hi;
        S_lo.push(lo);
        S_hi.push(hi);
        while (!S_lo.empty())
        {
            lo = S_lo.pop();
            hi = S_hi.pop();

            int pivotIndex = findPivot(A, lo, hi);
            //int pivotIndex = findPivot_Average(A, lo, hi);
            swap(A[pivotIndex], A[hi]);

            int k = partition<T, COMP>(A, lo - 1, hi, A[hi]);
            swap(A[k], A[hi]);

            if (k + 1 < hi)
            {
                S_lo.push(k + 1);
                S_hi.push(hi);
            }
            if (lo < k - 1)
            {
                S_lo.push(lo);
                S_hi.push(k - 1);
            }
        }
    }

    template<typename T, typename COMP>
    void quickSort_with_InsertSort(T A[], int lo, int hi)
    {
        if (hi - lo + 1 <= 8)
        {
            insertSort<T, COMP>(A, lo, hi);
            return;
        }
        int pivotIndex = findPivot(A, lo, hi);
        swap(A[pivotIndex], A[hi]);

        int k = partition<T, COMP>(A, lo - 1, hi, A[hi]);
        swap(A[k], A[hi]);

        quickSort_with_InsertSort<T, COMP>(A, lo, k - 1);
        quickSort_with_InsertSort<T, COMP>(A, k + 1, hi);
    };
    //END OF QUICKSORT

    //DEFIND HEAPSORT
    template<typename T, typename COMP>
    void heapSort(T elem[], int elemSize)
    {
        T *temp = new T[elemSize];
        Array_Implement<T>::arrayCopy(temp, elem, elemSize,0 , elemSize - 1);

        heap<T, COMP> Heap(temp, elemSize, elemSize + 2);
        for (int i = 0; i < elemSize; i++)
            elem[i] = Heap.delFirst();
    };
    //END OF HEAPSORT

    //DEFINE RADIXSORT
    template<typename T, class getKey>
    void radix(T A[], T B[], int n, int digits, int r, int cnt[])
    {
        for (int i = 0, rtoi = 1; i < digits; i++, rtoi *= r)
        {
            for (int j = 0; j < r; j++)
                cnt[j] = 0;
            for (int j = 0; j < n; j++)
                cnt[(getKey::key(A[j]) / rtoi) % r]++;
            for (int j = 1; j < r; j++)
                cnt[j] += cnt[j - 1];
            for (int j = n - 1; j >= 0; j--)
                B[--cnt[(getKey::key(A[j]) / rtoi) % r]] = A[j];
            for (int j = 0; j < n; j++)
                A[j] = B[j];
        }
    };

    void IntegerRadixSort(int A[], int size, int rtoi, int digits)
    {
        int B[size];
        int cnt[rtoi];
        //KeyGetter getter;
        radix<int, KeyGetter>(A, B, size, digits, rtoi, cnt);
    }
}
#endif //DSL_SORT_H
