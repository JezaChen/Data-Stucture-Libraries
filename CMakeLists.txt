cmake_minimum_required(VERSION 3.7)
project(DSL)

# Add the source in project root directory
aux_source_directory(. DIRSRCS)
# Add header file include directories

# Add block directories
#add_subdirectory(List)
#add_subdirectory(uniPRINTER)
#add_subdirectory(Common)
# Target
add_executable(DSL ${DIRSRCS} "Binary Tree/BinNode.h" "Binary Tree/BinTree.h"
        "Binary Tree/BinTree_remove.h" "Binary Tree/BinNode_trav.h" "Binary Tree/BinNode_travPre.h" "Binary Tree/BinNode_travIn.h" "Binary Tree/BinNode_travPost.h" List/test.h Queue/test.h BST/Dictionary.h BST/BST.h BST/BSTNode.h BST/BSTHelp.cpp
        "Priority Queue/Heap.h" "Priority Queue/PQ.h" "Huffman Tree/HuffNode.h" "Huffman Tree/HuffTree.h"
        "Stack/Linked_Stack.h" Stack/test.h Algorithm/sort.h Tree/tree.h Tree/union_find.h Tree/tree_lcrs_dynamic.h Tree/tree_lcrs_array.h Tree/tree_loc.h Algorithm/find.h Tree/tree_lcrs_dynamic_tr.h Tree/tree_trav.h Tree/tree_sequential.h Tree/test.h "Binary Tree/BinNode_travLevel.h" "Binary Tree/BinNode_Implement.h" "Binary Tree/BinTree_build.h" "Binary Tree/test.h" Algorithm/sort_test.h "Hash Dict/hashdict.h" "Hash Dict/KVPair.h" "Hash Dict/test.h" "Hash Dict/hashDictFunc.h" Two-Three-Tree/TTNode.h Two-Three-Tree/TTTree.h Two-Three-Tree/TTree_Insert_Impl.h Graph/Graph.h Graph/Graphm.h)
include_directories(./ ./uniPRINTER ./Common  ./List ./Stack ./Queue )
link_directories(./ ./uniPRINTER ./Common  ./List ./Stack ./Queue )

#target_link_libraries(DSL CMM uniPrinter list)
#ADD_DEFINITIONS(-fpermissive)