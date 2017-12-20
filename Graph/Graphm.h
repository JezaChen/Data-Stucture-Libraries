//
// Created by jeza on 17-12-20.
//
//图的邻接矩阵表现形式
#ifndef DSL_GRAPHM_H
#define DSL_GRAPHM_H
#include "Graph.h"

class Graphm : public Graph
{
private:
    int numVertex, numEdge;
    int** Matrix;
    int* mark;
public:
    Graphm(int numV) : numVertex(numV) {}
    ~Graphm()
    {
        if(Matrix)
        {
            for(int i=0; i<numVertex; i++)
                delete[] Matrix[i];
            delete[] Matrix;
        }
        if(mark)
        {
            delete[] mark;
        }
           
    }

    void init(int n)
    {
        numVertex = n;
        numEdge = 0;

        mark = new int[n];

        for(int i=0; i<n; i++)
            mark[i] = UNVISITED;

        for(int i=0; i<n; i++)
            Matrix[i] = new int[n];

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                Matrix[i][j] = 0;
    }

    int n() 
    {
        return numVertex;
    }

    int e()
    {
        return numEdge;
    }

    int first(int u)
    {
        for(int i=0; i<numVertex; i++)
            if(Matrix[u][i] != 0)
                return i;
        
        return numVertex; //如果不存在，就返回结点的个数
    }

    int next(int v, int w)
    {
        for(int i = w+1; i<numVertex; i++)
            if(Matrix[v][i] != 0)
                return i;
        return numVertex;
    }

    void setEdge(int u, int v, int weight)
    {
        if(weight < 0)
        {
            //TODO
        }
        if(Matrix[u][v] == 0)
            numEdge++;
        Matrix[u][v] = weight;
    }

    void delEdge(int u, int v)
    {
        if(Matrix[u][v] != 0)
            numEdge--;
        Matrix[u][v] = 0;
    }

    bool existEdge(int u, int v)
    {
        return Matrix[u][v] != 0;
    }

    int weight(int u, int v)
    {
        return Matrix[u][v];
    }

    int getMark(int targetVertex)
    {
        return mark[targetVertex];
    }

    void setMark(int targetVertex, int val)
    {
        mark[targetVertex] = val;
    }
}
#endif //DSL_GRAPHM_H
