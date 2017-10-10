//
// Created by jeza on 17-10-10.
//

#ifndef DSL_PQ_H
#define DSL_PQ_H
namespace DSLibrary
   {

    template<typename E, typename COMP>
    struct PQ
    {
        void PQ() {}
        virtual void ~PQ() {}

        virtual void insert(const E& ) = 0;
        virtual E getFirst() = 0;
        virtual E delFirst() = 0;
    };

    }
#endif //DSL_PQ_H
