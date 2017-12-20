//
// Created by jeza on 17-12-20.
//

#ifndef DSL_GRAPH_H
#define DSL_GRAPH_H

//图的ADT，仅仅提供抽象类

#define UNVISITED 0
#define VISITED 1

namespace DSLibrary
{
    class Graph
    {
    private:
        void operator = (const Graph&) {}
        Graph(const Graph&) {}
    public:
        Graph() {}
        virtual ~Graph() {}

        virtual void init(int n) = 0;
        virtual int n() = 0;
        virtual int e() = 0;

        virtual int first(int v) = 0;
        virtual int next(int v, int w) = 0;

        virtual void setEdge(int u, int v, int weight) = 0;
        virtual void delEdge(int u, int v, int weight) = 0;

        virtual bool existEdge(int u, int v) = 0;
        virtual int weight(int u, int v) = 0;

        virtual int getMak(int targetVertex) = 0;
        virtual void setMark(int targetVertex, int val) = 0;
    }
}
#endif //DSL_GRAPH_H
