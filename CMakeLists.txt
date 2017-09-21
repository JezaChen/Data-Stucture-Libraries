cmake_minimum_required(VERSION 3.7)
project(DSL)

# Add the source in project root directory
aux_source_directory(. DIRSRCS)
# Add header file include directories

# Add block directories
add_subdirectory(List)
add_subdirectory(uniPRINTER)
add_subdirectory(Common)
# Target
add_executable(DSL ${DIRSRCS} "Binary Tree/BinNode.h" "Binary Tree/BinTree.h" "Binary Tree/BinTree_remove.h" "Binary Tree/BinNode_trav.h" "Binary Tree/BinNode_travPre.h" "Binary Tree/BinNode_travIn.h" "Binary Tree/BinNode_travPost.h")
include_directories(./ ./List ./uniPRINTER ./Common)
link_directories(./ ./List ./uniPRINTER ./Common)

#target_link_libraries(DSL CMM uniPrinter list)