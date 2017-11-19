//
// Created by jeza on 17-10-10.
//

#ifndef DSL_HEAP_H
#define DSL_HEAP_H


#include <iostream>
#include <algorithm>
#include "../Common/Exception_Handler.h"
#include"PQ.h"

#define InHeap(n, i) ( ( (-1) < (i)) && ( (i) < (n) ) )
#define Parent(i) ( (i-1)>>1 )
#define LastInternal(n) Parent(n-1)
#define LChild(i) ( 1 + ( (i)<< 1) )
#define RChild(i) ( ( 1+ ( i ) )>> 1 )
#define HasParent(i) (0 < i)

#ifdef HasLChild
#define HasLChild(n, i)  InHeap(n,LChild(i))
#endif

#ifdef HasRChild
#define HasRChild(n, i)  InHeap(n,RChild(i))
#endif
using namespace std;
namespace DSLibrary
{
    template<typename E, typename COMP>
    class heap : public PQ<E, COMP>
    {
    private:
        E *_Heap;
        int capacity;
        int _size;

        int properParent(int posi)
        {
            //选择三者中优先级最高的作为父亲
            if (HasLChild(_size, posi) && HasRChild(_size, posi))
            {
                if (COMP::priority(_Heap[LChild(posi)], _Heap[posi]))
                {
                    if (COMP::priority(_Heap[RChild(posi)], _Heap[LChild(posi)]))
                        return RChild(posi);

                    else return LChild(posi);
                }
                else
                {
                    if (COMP::priority(_Heap[posi], _Heap[RChild(posi)]))
                        return posi;

                    else return RChild(posi);
                }
            }
            else if (HasLChild(_size, posi))
            {
                return (COMP::priority(_Heap[posi], _Heap[LChild(posi)]) ? posi : LChild(posi));
            }
            else if (HasRChild(_size, posi))
            {
                return (COMP::priority(_Heap[posi], _Heap[RChild(posi)]) ? posi : RChild(posi));
            }
            else return posi;
        }

    protected:
        int siftDown(int posi) //下滤
        {
            int j;
            while (posi != (j = properParent(posi)))
            {
                swap(_Heap[posi], _Heap[j]);
                posi = j;
            }
            return posi;
        }

        int siftUp(int posi) //上滤
        {
            while (HasParent(posi)) //只要posi有父亲
            {
                int p = Parent(posi);
                if (!COMP::priority(_Heap[posi], _Heap[p])) break;
                swap(_Heap[posi], _Heap[p]);
                posi = p;
            } //while
            return posi;
        }

        void heapify() //建堆
        {
            //Floyd
            for (int i = LastInternal(_size); InHeap(_size, i); i--)
                siftDown(i); //依次对内部节点下滤即可
        }

    public:
        heap(int c) : _Heap(NULL), capacity(c), _size(0)
        {}

        heap(E *elem, int s, int c) : _Heap(elem), _size(s), capacity(c)
        {
            heapify();
        }

        int size() const
        { return _size; }

        void insert(const E &elem)
        {
            if (_size == capacity)
            {
                //抛出堆满异常
                throw arrayFull_Exception("heap");
            }
            else
            {
                _Heap[_size] = elem;
                _size++;
                siftUp(_size - 1); //进行上滤
            }
        }

        E getFirst()
        {
            if (_size == 0)
            {
                throw heapEmpty_Exception();
            }
            else
            {
                return _Heap[0];
            }
        }

        E delFirst()
        {
            if (_size == 0)
            {
                throw heapEmpty_Exception();
            }
            else
            {
                E temp = _Heap[0];
                swap(_Heap[0], _Heap[_size - 1]);
                _size--;
                siftDown(0); //对根节点进行一次下滤操作
                return temp;
            }
        }

        E remove(int posi)
        {
            if (!InHeap(_size, posi))
            {
                if (posi < 0)
                    throw outOfBounds_Exception(OUT_OF_BOUNDS_STATUS::LOWER_BOUND);
                else
                    throw outOfBounds_Exception(OUT_OF_BOUNDS_STATUS::UPPER_BOUND);
            }
            else
            {
                if (posi == _size - 1)
                    _size--;
                else
                {
                    swap(_Heap[posi], _Heap[_size - 1]);
                    siftUp(posi); //上滤
                    siftDown(posi); //下滤
                }
                return _Heap[_size];
            }
        }
    };
}
#endif //DSL_HEAP_H
