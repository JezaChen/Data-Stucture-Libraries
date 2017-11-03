//
// Created by jeza on 17-11-3.
//

#ifndef DSL_FIND_H
#define DSL_FIND_H

#include <cmath>
#include "../List/List.h"

namespace DSLibrary
{
    using std::abs;

    //find something in dis-ordered list
    template<typename T>
    bool find(List<T> &list, T target, int &targetPosi)
    {
        targetPosi = -1;  //init
        int posiTemp = list.currentPosi();

        list.moveToStart();
        while (list.currentPosi() != list.size())
        {
            if (list.getValue() == target)
            {
                targetPosi = list.currentPosi();
                break;
            }
        }

        list.moveToPosi(posiTemp);
        return targetPosi != -1;
    };

    template<>
    bool find(List<double> &list, double target, int& targetPosi)
    {
        targetPosi = -1;  //init
        int posiTemp = list.currentPosi();

        list.moveToStart();
        while (list.currentPosi() != list.size())
        {
            if (abs(list.getValue() - target) <= 1e-7)
            {
                targetPosi = list.currentPosi();
                break;
            }
        }

        list.moveToPosi(posiTemp);
        return targetPosi != -1;
    }

    template<>
    bool find(List<float> &list, float target, int& targetPosi)
    {
        targetPosi = -1;  //init
        int posiTemp = list.currentPosi();

        list.moveToStart();
        while (list.currentPosi() != list.size())
        {
            if (abs(list.getValue() - target) <= 1e-7)
            {
                targetPosi = list.currentPosi();
                break;
            }
        }

        list.moveToPosi(posiTemp);
        return targetPosi != -1;
    }
}
#endif //DSL_FIND_H
