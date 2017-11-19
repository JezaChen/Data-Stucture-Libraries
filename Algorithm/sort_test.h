//
// Created by jeza on 17-11-18.
//
#ifndef DSL_SORT_TEST_H
#define DSL_SORT_TEST_H

#include <cstdlib>
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include "sys/time.h"
#include "sort.h"

using namespace DSLibrary;

void test_AlgorithmTure();
void AlgorithmRunningTimeTest();

//timeval结构定义
struct TimeVal{
    long tv_sec; //秒
    long tv_usec; //微秒
};
//timezone 结构定义
struct TimeZone{
    int tz_minuteswest; /*和Greenwich 时间差了多少分钟*/
    int tz_dsttime; /*日光节约时间的状态*/
};

void sort_test_I()
{
    //检验正确性
    // int n;
    // cin >> n;
    //int num[n];
    // for (int i = 0; i < n; i++)
    //    cin >> num[i];

    //quickSort<int,COMPARE_LESS<int> >(num, 0, n - 1);
    //mergeSort<int,COMPARE_LESS<int> >(num, n);
    //bubbleSort<int,COMPARE_LESS<int> >(num,n);
    //insertSort<int,COMPARE_LESS<int> >(num,n);
    //selectSort<int,COMPARE_LESS<int> >(num,n);
    //IntegerRadixSort(num, n, 8, 4);
    // quickSort_with_InsertSort<int, COMPARE_LESS<int> >(num, 0, n - 1);
    //quickSort_Ave<int,COMPARE_LESS<int> >(num, 0, n - 1);
    // for (int i = 0; i < n; i++)
    //     cout << num[i] << ' ';
    // cout << endl;
    //test_AlgorithmTure();
    AlgorithmRunningTimeTest();
}

bool isAlgorithmTure_Less(int num[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (num[i] > num[i + 1]) return false;
    }
    return true;
}

void randomArray(int num[], int k)
{
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < k; i++)
    {
        num[i] = rand() % k;
    }
}

void test_AlgorithmTure()
{
    int k = 10;
    int dig = 2;
    int *num;
    while (k <= 1000000)
    {
        num = new int[k];
        /*randomArray(num, k);
        quickSort<int, COMPARE_LESS<int> >(num, 0, k - 1);
        cout << "quickSort Normal Edition: ";
        if (isAlgorithmTure_Less(num, k)) cout << "true." << endl;
        else cout << "false." << endl;

        randomArray(num, k);
        mergeSort<int, COMPARE_LESS<int> >(num, k);
        cout << "mergeSort: ";
        if (isAlgorithmTure_Less(num, k)) cout << "true." << endl;
        else cout << "false." << endl;

        randomArray(num, k);
        bubbleSort<int, COMPARE_LESS<int> >(num, k);
        cout << "bubbleSort: ";
        if (isAlgorithmTure_Less(num, k)) cout << "true." << endl;
        else cout << "false." << endl;

        randomArray(num, k);
        insertSort<int, COMPARE_LESS<int> >(num, 0, k - 1);
        cout << "insertSort: ";
        if (isAlgorithmTure_Less(num, k)) cout << "true." << endl;
        else cout << "false." << endl;

        randomArray(num, k);
        selectSort<int, COMPARE_LESS<int> >(num, k);
        cout << "selectSort: ";
        if (isAlgorithmTure_Less(num, k)) cout << "true." << endl;
        else cout << "false." << endl;

        randomArray(num, k);
        IntegerRadixSort(num, k, 8, dig + 1);
        cout << "IntegerRadixSort: ";
        if (isAlgorithmTure_Less(num, k)) cout << "true." << endl;
        else cout << "false." << endl;

        randomArray(num, k);
        quickSort_with_InsertSort<int, COMPARE_LESS<int> >(num, 0, k - 1);
        cout << "quickSort with InsertSort: ";
        if (isAlgorithmTure_Less(num, k)) cout << "true." << endl;
        else cout << "false." << endl;

        randomArray(num, k);
        quickSort_I<int, COMPARE_LESS<int> >(num, 0, k - 1);
        cout << "quickSort I: ";
        if (isAlgorithmTure_Less(num, k)) cout << "true." << endl;
        else cout << "false." << endl;
*/
        randomArray(num, k);
        quickSort_Ave<int, COMPARE_LESS<int> >(num, 0, k - 1);
        cout << "quickSort Average Edition: ";
        if (isAlgorithmTure_Less(num, k)) cout << "true." << endl;
        else
        {
            cout << "false." << endl;
            for (int i = 0; i < k; i++)
                cout << num[i] << ' ';
            cout << endl;
        }

        k *= 10;
        dig++;
        delete[] num;
    }
}

void AlgorithmRunningTimeTest()
{
    ofstream output;
    output.open("/home/jeza/timeTest.log", ios::out | ios::app);
    output << "///////////////TEST///////////////" << endl;

    int k = 10;
    int dig = 2;
    int *num;

    struct timeval t1,t2;
    double timeuse;
    double ave;

    cout<<"Running..."<<endl;
    while (k <= 1000000)
    {
        output << "The size of testing array: " << k << endl;

        num = new int[k];

        ave = 0;
        output << "quickSort Normal Edition: "<<endl;
        for (int i = 0; i < 10; i++)
        {
            output<<"Test "<<i+1<<':';

            randomArray(num, k);

            gettimeofday(&t1,NULL);
            quickSort<int, COMPARE_LESS<int> >(num, 0, k - 1);
            gettimeofday(&t2,NULL);
            timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;

            ave += timeuse/10;
            output<<fixed<<setprecision(6)<<timeuse<<" ms"<<endl;
        }
        output<<"Average: "<<ave<<"ms"<<endl;

        ave = 0;
        output << "MergeSort: "<<endl;
        for (int i = 0; i < 10; i++)
        {
            output<<"Test "<<i+1<<':';

            randomArray(num, k);

            gettimeofday(&t1,NULL);
            mergeSort<int, COMPARE_LESS<int> >(num, k);
            gettimeofday(&t2,NULL);
            timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;

            ave += timeuse/10;
            output<<fixed<<setprecision(6)<<timeuse<<" ms"<<endl;
        }
        output<<"Average: "<<ave<<"ms"<<endl;

        /*ave = 0;
        output << "HeapSort: "<<endl;
        for (int i = 0; i < 10; i++)
        {
            output<<"Test "<<i+1<<':';

            randomArray(num, k);

            gettimeofday(&t1,NULL);
            heapSort<int, COMPARE_LESS<int> >(num, k);
            gettimeofday(&t2,NULL);
            timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;

            ave += timeuse/10;
            output<<fixed<<setprecision(6)<<timeuse<<" ms"<<endl;
        }
        output<<"Average: "<<ave<<"ms"<<endl;
*/

        /*ave = 0;
        output << "BubbleSort: "<<endl;
        for (int i = 0; i < 10; i++)
        {
            output<<"Test "<<i+1<<':';

            randomArray(num, k);

            gettimeofday(&t1,NULL);
            bubbleSort<int, COMPARE_LESS<int> >(num, k);
            gettimeofday(&t2,NULL);
            timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;

            ave += timeuse/10;
            output<<fixed<<setprecision(6)<<timeuse<<" ms"<<endl;
        }
        output<<"Average: "<<ave<<"ms"<<endl;

        ave = 0;
        output << "InsertSort: "<<endl;
        for (int i = 0; i < 10; i++)
        {
            output<<"Test "<<i+1<<':';

            randomArray(num, k);

            gettimeofday(&t1,NULL);
            insertSort<int, COMPARE_LESS<int> >(num, k);
            gettimeofday(&t2,NULL);
            timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;

            ave += timeuse/10;
            output<<fixed<<setprecision(6)<<timeuse<<" ms"<<endl;
        }
        output<<"Average: "<<ave<<"ms"<<endl;

        ave = 0;
        output << "SelectSort: "<<endl;
        for (int i = 0; i < 10; i++)
        {
            output<<"Test "<<i+1<<':';

            randomArray(num, k);

            gettimeofday(&t1,NULL);
            selectSort<int, COMPARE_LESS<int> >(num, k);
            gettimeofday(&t2,NULL);
            timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;

            ave += timeuse/10;
            output<<fixed<<setprecision(6)<<timeuse<<" ms"<<endl;
        }
        output<<"Average: "<<ave<<"ms"<<endl;
*/
        ave = 0;
        output << "IntegerRadixSort: "<<endl;
        for (int i = 0; i < 10; i++)
        {
            output<<"Test "<<i+1<<':';

            randomArray(num, k);

            gettimeofday(&t1,NULL);
            IntegerRadixSort(num, k, 8, dig);
            gettimeofday(&t2,NULL);
            timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;

            ave += timeuse/10;
            output<<fixed<<setprecision(6)<<timeuse<<" ms"<<endl;
        }
        output<<"Average: "<<ave<<"ms"<<endl;

        ave = 0;
        output << "QuickSort with InsertSort: "<<endl;
        for (int i = 0; i < 10; i++)
        {
            output<<"Test "<<i+1<<':';

            randomArray(num, k);

            gettimeofday(&t1,NULL);
            quickSort_with_InsertSort<int, COMPARE_LESS<int> >(num, 0, k-1);
            gettimeofday(&t2,NULL);
            timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;

            ave += timeuse/10;
            output<<fixed<<setprecision(6)<<timeuse<<" ms"<<endl;
        }
        output<<"Average: "<<ave<<"ms"<<endl;

        ave = 0;
        output << "QuickSort I: "<<endl;
        for (int i = 0; i < 10; i++)
        {
            output<<"Test "<<i+1<<':';

            randomArray(num, k);

            gettimeofday(&t1,NULL);
            quickSort_I<int, COMPARE_LESS<int> >(num, 0, k-1);
            gettimeofday(&t2,NULL);
            timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;

            ave += timeuse/10;
            output<<fixed<<setprecision(6)<<timeuse<<" ms"<<endl;
        }
        output<<"Average: "<<ave<<"ms"<<endl;

        ave = 0;
        output << "QuickSort Average Edition: "<<endl;
        for (int i = 0; i < 10; i++)
        {
            output<<"Test "<<i+1<<':';

            randomArray(num, k);

            gettimeofday(&t1,NULL);
            quickSort_Ave<int, COMPARE_LESS<int> >(num, 0, k-1);
            gettimeofday(&t2,NULL);
            timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;

            ave += timeuse/10;
            output<<fixed<<setprecision(6)<<timeuse<<" ms"<<endl;
        }
        output<<"Average: "<<ave<<"ms"<<endl;


        k *= 4;
        dig++;
        delete[] num;
    }

    output.close();
    cout<<"Completed."<<endl;
}

#endif //DSL_SORT_TEST_H
