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
#include "./../../../inc/adt/vector.h"
#include "./../../../inc/adt/list.h"
#include "./../../../inc/adt/tree.h"

namespace cclib {
    namespace common {
        namespace util {
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
            inline void printTreeValue(cclib::adt::BinarySearchTree<Comparable>& value) {
                cclib::adt::BinaryNode<Comparable>* itr = value.begin();
                std::cout << "BinarySearchTree: ";
                std::string result = "";
                preOrderTraversal(itr, result);
            }

            template<typename _K, typename _V, typename Comparable = cclib::adt::Pair<_K, _V>>
            inline std::string preOrderTraversal(cclib::adt::BinaryNode<cclib::adt::Pair<_K, _V>>*& root, std::string result) {
                if(CC_NULL == root) {
                    return result;
                }

                result += " value: " + cclib::adt::Pair<_K, _V>::to_string(root->_data);

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
            inline void printTreeValue(cclib::adt::BinarySearchTree<cclib::adt::Pair<_K, _V>>& value) {
                cclib::adt::BinaryNode<Comparable>* itr = value.begin();
                std::cout << "BinarySearchTree: ";
                std::string result = "";
                preOrderTraversal(itr, result);
            }

            template<typename Comparable>
            Comparable getMiddleValue(Comparable& first, Comparable& second, Comparable& third) {
                Comparable biggerValue = first > second ? first : second;
                Comparable maxValue = biggerValue > third ? biggerValue : second;

                Comparable smallerValue = first < second ? first : second;
                Comparable minValue = smallerValue < third ? smallerValue : second;

                return first + second + third - maxValue - minValue;
            }
        }
    }
}

#endif  //CCLIB_COMMON_UTIL_H