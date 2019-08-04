/*********************************************************************
 * cclib-common
 *
 * Copyright (c) 2019 cclib-common contributors:
 *   - hello_chenchen <https://github.com/hello-chenchen>
 *
 * MIT License <https://github.com/cc-libraries/cclib-common/blob/master/LICENSE>
 * See https://github.com/cc-libraries/cclib-common for the latest update to this file
 *
 * author: hello_chenchen <https://github.com/hello-chenchen>
 **********************************************************************************/
#ifndef CCLIB_COMMON_UTIL_H
#define CCLIB_COMMON_UTIL_H

#include <vector>
#include <string>
#include <iostream>
#include "./../../../inc/adt/vector.h"
#include "./../../../inc/adt/list.h"
#include "./../../../inc/adt/tree.h"
#include "./../../../inc/adt/pair.h"

namespace cclib {
    namespace common {
        namespace util {
            template<typename Comparable>
            inline void printArrayValue(Comparable* value, size_t size) {
                std::string retString = "array:";
                for(int i = 0; i < size; i++) {
                    retString = " value[" + std::to_string(i) + "]: " + std::to_string(*(value + i));
                }

                std::cout << retString << std::endl;
            }

            template<typename Comparable>
            inline void printVectorValue(std::vector<Comparable>& value) {
                std::string retString = "vector:";
                for(int i = 0; i < value.size(); i++) {
                    retString += " value[" + std::to_string(i) + "]: " + std::to_string(value[i]);
                }
                std::cout << retString << std::endl;
            };

            template<typename Comparable>
            inline void printVectorValue(cclib::adt::Vector<Comparable>& value) {
                std::string retString = "Vector:";
                for(int i = 0; i < value.size(); i++) {
                    retString += " value[" + std::to_string(i) + "]: " + std::to_string(value[i]);
                }
                std::cout << retString << std::endl;
            };

            template<typename Comparable>
            inline void printListValue(cclib::adt::List<Comparable>& value) {
                typename cclib::adt::List<Comparable>::iterator itr = value.begin();
                std::string retString = "List:";
                for(int i = 0; i < value.size(); i++) {
                    retString += " value[" + std::to_string(i) + "]: " + std::to_string(*itr);
                    itr++;
                }
                std::cout << retString << std::endl;
            }

            template<typename Comparable>
            inline std::string preOrderTraversal(cclib::adt::BinaryNode<Comparable>*& root, std::string result) {
                if(CC_NULL == root) {
                    return result;
                }

                result += " value: " + std::to_string(root->_data);

                if(CC_NULL != root->_leftChild) {
                    return result += preOrderTraversal(root->_leftChild, result);
                }
                if(CC_NULL != root->_rightChild) {
                    return result += preOrderTraversal(root->_rightChild, result);
                }

                std::cout << result << std::endl;
                return result;
            }

            template<typename Comparable>
            inline void printBinarySearchTreeValue(cclib::adt::BinarySearchTree<Comparable>& value) {
                cclib::adt::BinaryNode<Comparable>* itr = value.begin();
                std::cout << "BinarySearchTree:";
                std::string result = "";
                preOrderTraversal(itr, result);
            }

            template<typename Comparable>
            inline void printTreeValue(cclib::adt::RedBlackTree<Comparable>& value) {
                typename cclib::adt::RedBlackTree<Comparable>::iterator itr = value.begin();

                std::string retString = "Tree:";
                for(int i = 0; i < value.size(); i++) {
                    retString += " value[" + std::to_string(i) + "]: " + std::to_string(*itr);
                    itr++;
                }
                std::cout << retString << std::endl;
            }

            template<typename _K, typename _V, typename Comparable = cclib::adt::Pair<_K, _V>>
            inline std::string preOrderTraversal(cclib::adt::BinaryNode<cclib::adt::Pair<_K, _V>>*& root, std::string result) {
                if(CC_NULL == root) {
                    return result;
                }

                result += " Pair:" + cclib::adt::Pair<_K, _V>::to_string(root->_data);

                if(CC_NULL != root->_leftChild) {
                    return result += preOrderTraversal(root->_leftChild, result);
                }
                if(CC_NULL != root->_rightChild) {
                    return result += preOrderTraversal(root->_rightChild, result);
                }

                std::cout << result << std::endl;
                return result;
            }

            template<typename _K, typename _V, typename Comparable = cclib::adt::Pair<_K, _V>>
            inline void printBinarySearchTreeValue(cclib::adt::BinarySearchTree<cclib::adt::Pair<_K, _V>>& value) {
                cclib::adt::BinaryNode<Comparable>* itr = value.begin();
                std::cout << "BinarySearchTree:";
                std::string result = "";
                preOrderTraversal(itr, result);
            }

            template<typename _K, typename _V, typename Comparable = cclib::adt::Pair<_K, _V>>
            inline void printTreeValue(cclib::adt::RedBlackTree<cclib::adt::Pair<_K, _V>>& value) {
                typename cclib::adt::RedBlackTree<Comparable>::iterator itr = value.begin();
                std::string retString = "Tree:";
                for(int i = 0; i < value.size(); i++) {
                    retString += " value[" + std::to_string(i) + "]: " + cclib::adt::Pair<_K, _V>::to_string(*itr);
                    ++itr;
                }
                std::cout << retString << std::endl;
            }

            template<typename Comparable>
            Comparable getMiddleValue(Comparable& first, Comparable& second, Comparable& third) {
                Comparable biggerValue = first > second ? first : second;
                Comparable maxValue = biggerValue > third ? biggerValue : second;

                Comparable smallerValue = first < second ? first : second;
                Comparable minValue = smallerValue < third ? smallerValue : second;

                return first + second + third - maxValue - minValue;
            }

            template<typename Comparable>
            void swap(Comparable& value1, Comparable& value2) {
                Comparable temp = value1;
                value1 = value2;
                value2 = temp;
            }

            template<typename Comparable>
            void swap(Comparable* value1, Comparable* value2) {
                Comparable temp = *value1;
                *value1 = *value2;
                *value2 = temp;
            }

            template<typename T>
            int pow(T x, unsigned int n) {
                if(0 == n) {
                    if(T() == x) {
                        return -1;
                    }

                    return 1;
                }

                for(int i = 1; i < n; i++) {
                    x *= x;
                }

                return x;
            }

            int spliteIntDigit(int value, int index) {
                int divValue = value / pow(10, index-1);
                return divValue % 10;
            }

            int spliteIntDigitNA(int value, int index) {
                int divValue = value / pow(10, index-1);
                return 0 == divValue ? -1 : divValue % 10;
            }
        }
    }
}

#endif  //CCLIB_COMMON_UTIL_H