//
// Created by jeza on 17-11-4.
//

/*********************************
 * Sequential Tree Implementation*
 ********** 树的顺序表示法************
 **********************************/
#ifndef DSL_TREE_SEQUENTIAL_H
#define DSL_TREE_SEQUENTIAL_H

#include <cstdio>
#include <iostream>
#include <string>
#include "tree.h"
#include "../Binary Tree/BinTree.h"
#include "tree_lcrs_dynamic_tr.h"
#include "tree_lcrs_dynamic.h"
#include "tree_loc.h"

namespace DSLibrary
{
    //template<typename T>
    class SequentialTreeImpl_Printer
    {
        /***********************
         * 下面都是直接打印的********
         * @param root***********
         ***********************/
    public:
        //用于二叉树的顺序表示法
        static void Slash_Printer(BinNodePosi(char)root)
        {
            if (!root)
            {
                cout << '/';
                return;
            }
            else
                cout << root->data;

            Slash_Printer(root->lc);
            Slash_Printer(root->rc);
        }

        static void Slash_And_Point_Printer(BinNodePosi(char)root)
        {
            if (!root)
            {
                cout << '/';
                return;
            }
            if (HasChild(*root))
            {
                cout << root->data << '\'';
                Slash_And_Point_Printer(root->lc);
                Slash_And_Point_Printer(root->rc);
            }
            else
            {
                cout << root->data;
            }
        }

        //用于树的顺序表示法
        static void Bracket_Printer(GTNodePosi(char)root)
        {
            cout << root->data();

            GTNodePosi(char)child = root->leftMostChild();
            while (child)
            {
                Bracket_Printer(child);
                child = child->rightSibling();
            }

            cout << ")";
        }


        /**********************
         * 下面的接口是把结果储存在字符串中
         * @param root 输入子树的根节点
         * @param str 输出字符串
         ***********************/
        static void Slash_Printer_I(BinNodePosi(char)root, string &str)
        {
            if (!root)
            {
                str.append("/");
                return;
            }
            else
                str.append(1, root->data);

            Slash_Printer_I(root->lc, str);
            Slash_Printer_I(root->rc, str);
        }

        static void Slash_And_Point_Printer_I(BinNodePosi(char)root, string &str)
        {
            if (!root)
            {
                str.append("/");
                return;
            }
            if (HasChild(*root))
            {
                str.append(1, root->data);
                str.append("\'");
                Slash_And_Point_Printer_I(root->lc, str);
                Slash_And_Point_Printer_I(root->rc, str);
            }
            else
            {
                str.append(1, root->data);
            }
        }

        static void Bracket_Printer_I(GTNodePosi(char)root, string &str)
        {
            str.append(1, root->data());

            GTNodePosi(char)child = root->leftMostChild();
            while (child)
            {
                Bracket_Printer_I(child, str);
                child = child->rightSibling();
            }

            str.append(")");
        }
    };

    //template<typename T>
    class SequentialTreeImplementation
    {
    public:
        static string SlashImplementation(BinTree<char> *bintree)
        {
            BinNodePosi(char)root = bintree->root();
            string res;

            SequentialTreeImpl_Printer::Slash_Printer_I(root, res);
            return res;
        }

        static string SlashAndPointerImplementation(BinTree<char> *bintree)
        {
            BinNodePosi(char)root = bintree->root();
            string res;

            SequentialTreeImpl_Printer::Slash_And_Point_Printer_I(root, res);
            return res;
        }

        static string BracketImplementation(GeneralTree<char> *gtree)
        {
            GTNodePosi(char)root = gtree->root();
            string res;

            SequentialTreeImpl_Printer::Bracket_Printer_I(root, res);
            return res;
        }
    };

    //template<typename T>
    //当前仅支持字符型的树结点
    class SequentialTreeImplementation_Rebuild //重建树接口类
    {
    public:
        static BinTree<char> *SlashImplementation_Rebuild(const string &str)
        {
            if (str.empty()) return nullptr;
            else
            {
                BinTree<char> *res = new BinTree<char>;
                res->insertAsRoot(str[0]);

                int pos = 1;
                SlashImplRebuild_Help(res, res->root(), true, str, pos);
                SlashImplRebuild_Help(res, res->root(), false, str, ++pos);
                return res;
            }
        }

        static BinTree<char> *SlashAndPointImplementation_Rebuild(const string &str)
        {
            if (str.empty()) return nullptr;
            else
            {
                BinTree<char> *res = new BinTree<char>;
                res->insertAsRoot(str[0]);
                if (str.size() > 1)
                {
                    int pos = 2;
                    SlashAndPointerImplRebuild_Help(res, res->root(), true, str, pos);
                    SlashAndPointerImplRebuild_Help(res, res->root(), false, str, ++pos);
                }
                return res;
            }
        }

        static GeneralTree<char> *BracketImplementation_Rebuild(const string &str)
        {
            if (str.empty()) return nullptr;
            else
            {
                //GeneralTree<char> *res = new TRLibrary::leftChildRightSibling_Tree<char>; //以此为例
                GeneralTree<char> *res = new leftChildRightSibling_Tree<char>;
                //GeneralTree<char> *res = new TRLibrary::listOfChildren_Tree<char>;

                res->insertAsRoot(str[0], nullptr, nullptr);
                int pos = 1;
                BracketImplRebuild_Help(res, res->root(), true, str, pos);

                return res;
            }
        }


    private:
        static void SlashImplRebuild_Help
                (BinTree<char> *bintree,
                 BinNodePosi(char)curr,
                 bool currPosiIsLeft,
                 const string &str,
                 int &currPosiInString)
        {
            if (currPosiInString >= str.size()) return; //已经完成任务
            if (str[currPosiInString] == '/')
            {
                return;
            }
            else
            {
                if (currPosiIsLeft)
                {
                    bintree->insertAsLc(curr, str[currPosiInString]);
                    SlashImplRebuild_Help(bintree, curr->lc, true, str, ++currPosiInString);
                    SlashImplRebuild_Help(bintree, curr->lc, false, str, ++currPosiInString);
                }
                else
                {
                    bintree->insertAsRc(curr, str[currPosiInString]);
                    SlashImplRebuild_Help(bintree, curr->rc, true, str, ++currPosiInString);
                    SlashImplRebuild_Help(bintree, curr->rc, false, str, ++currPosiInString);
                }
            }
        }

        static void SlashAndPointerImplRebuild_Help
                (BinTree<char> *bintree,
                 BinNodePosi(char)curr,
                 bool currPosiIsLeft,
                 const string &str,
                 int &currPosiInString)
        {
            if (currPosiInString >= str.size()) return;
            if (str[currPosiInString] == '/')
            {
                return;
            }
            else
            {
                if (currPosiIsLeft)
                {
                    if (currPosiInString + 1 < str.length() &&
                        str[currPosiInString + 1] == '\'') //it is an internal node
                    {
                        bintree->insertAsLc(curr, str[currPosiInString]);
                        currPosiInString++;

                        SlashAndPointerImplRebuild_Help(bintree, curr->lc, true, str, ++currPosiInString);
                        SlashAndPointerImplRebuild_Help(bintree, curr->lc, false, str, ++currPosiInString);
                    }
                    else //it is a leaf node
                    {
                        bintree->insertAsLc(curr, str[currPosiInString]);
                    }
                }
                else //currPosi is right
                {
                    if (currPosiInString + 1 < str.length() &&
                        str[currPosiInString + 1] == '\'') //it is an internal node
                    {
                        bintree->insertAsRc(curr, str[currPosiInString]);
                        currPosiInString++;

                        SlashAndPointerImplRebuild_Help(bintree, curr->rc, true, str, ++currPosiInString);
                        SlashAndPointerImplRebuild_Help(bintree, curr->rc, false, str, ++currPosiInString);
                    }
                    else //it is a leaf node
                    {
                        bintree->insertAsRc(curr, str[currPosiInString]);
                    }
                }
            }
        }

        static void BracketImplRebuild_Help
                (GeneralTree<char> *gtree,
                 GTNodePosi(char)curr,
                 bool currPosiIsParent,
                 const string &str,
                 int &currPosiInString)
        {
            if (currPosiInString >= str.size()) return;
            if (str[currPosiInString] == ')') return;
            if (currPosiIsParent)
            {
                gtree->insertAsFirstChild(curr, str[currPosiInString]);
                //先处理孩子
                BracketImplRebuild_Help(gtree, curr->leftMostChild(), true, str, ++currPosiInString);
                //再处理右兄弟
                BracketImplRebuild_Help(gtree, curr->leftMostChild(), false, str, ++currPosiInString);
            }
            else
            {
                gtree->insertAsRightSibling(curr, str[currPosiInString]);
                //先处理孩子
                BracketImplRebuild_Help(gtree, curr->rightSibling(), true, str, ++currPosiInString);
                //再处理右兄弟
                BracketImplRebuild_Help(gtree, curr->rightSibling(), false, str, ++currPosiInString);

            }
        }
    };
}

#endif //DSL_TREE_SEQUENTIAL_H
