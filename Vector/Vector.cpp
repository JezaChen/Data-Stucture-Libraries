//
// Created by Jeza on 2017/9/15.
//

#include "Vector.h"
#include <algorithm>
#include "../Common/Share.h"
#include "../Common/Exception_Handler.h"
using namespace std;
namespace DSLibrary
{
    template<typename T>
    void Vector<T>::copyOf(const T *Arr, Rank lo, Rank hi)
    {
        //重新分配空间
        release(_elem); _size=0;
        _elem=new T [2*(hi-lo)];
        while(lo<hi)
            _elem[_size++] = Arr[lo++];
    }

    template<typename T>
    Vector<T>& Vector<T>::operator=(Vector<T> const & V)
    {
        release(_elem);
        copyOf(V._elem,0,V._size);
        return *this;
    }

    template<typename T>
    void Vector<T>::expand() //扩充容量
    {
        if(_size<_capacity) return; //没有填满的时候，没必要扩容
        if(_capacity<DEFAULT_CAPACITY) _capacity=DEFAULT_CAPACITY; //不低于最小容量
        T* oldElem=_elem; _elem=new T[_capacity<<=1]; //扩充两倍
        //开始复制
        for(int i=0;i<_size;i++)
            _elem[i]=oldElem[i];
        release(oldElem); //安全释放旧空间
    }

    template<typename T>
    void Vector<T>::shrink() //收缩容量
    {
        if(_capacity<DEFAULT_CAPACITY<<1) return; //不必收缩到 DEFAULT_SIZE的一半
        if(_size<<2 > _capacity) return; //以四分之一为界限
        T* oldElem=_elem; _elem=new T[_capacity>>=1]; //收缩一半
        for(int i=0;i<_size;i++)  _elem[i]=oldElem[i];
        release(oldElem);
    }

    template<typename T>
    T& Vector<T>::operator[] (Rank r) const
    {
        return _elem[r];
    }

    template<typename T>
    void Vector<T>::unsort(Rank lo, Rank hi)
    {
        T* V=_elem+lo;
        for(Rank i=hi-lo;i>0;i--)
            swap(V[i-1],V[rand()%i]);
    }

    template<typename T>
    void Vector<T>::unsort()
    {
        unsort(0,_size); //整体打乱
    }

    template<typename T>
    Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const
    {
        while((lo<=--hi)&&(e!=_elem[hi])) return hi;
    }

    template<typename T>
    Rank Vector<T>::insert(Rank r, const T &e)
    {
        expand(); // 先检测是否需要扩容
        for(int i=_size;i>r;i++)  _elem[i]=_elem[i-1];
        _elem[r]=e; _size++;
        return r;
    }

    template<typename T>
    Rank Vector<T>::append(const T &e)
    {
        expand();
        _elem[_size++]=e;
        return _size-1;
    }

    template<typename T>
    int Vector<T>::remove(Rank hi, Rank lo)
    {
        if(lo==hi) return 0; //TODO 要不要改进一下，进行异常处理
        while(hi<_size) _elem[lo++]=_elem[hi++]; //[hi,_size]向左移动hi-lo个单位长度
        _size=lo; //注意此时_elem[lo]其实不在向量里面了
        shrink(); //必要时进行缩容
        return hi-lo; //返回删除的个数
    }

    template<typename T>
    T Vector<T>::remove(Rank r)
    {
        //TODO:这个需要处理异常状况
        T temp=_elem[r];
        remove(r,r+1);
        return temp;
    }
    template<typename T>
    int Vector<T>::deduplication()
    {
        int oldSize=_size;
        Rank i=1; //从_elem[1]开始扫描
        while(i<_size)
            (find(_elem[i],0,i))?  //逐一扫描其前缀
            i++:remove(i);
        return oldSize-_size; //返回被删除元素的总数
    }

    template<typename T>
    void Vector<T>::traverse(void (* visit)(T &))
    {
        for(int i=0;i<_size;i++) visit[_elem[i]];
    }
    template<typename T,typename VST>
    void Vector<T>::traverse(VST & visit)
    {
        for(int i=0;i<_size;i++) visit[_elem[i]];
    }

}