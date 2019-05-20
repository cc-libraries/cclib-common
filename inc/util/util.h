/*********************************************************************
 * cclib-common
 *
 * Copyright (c) 2019 cc-algorithm contributors:
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
                cclib::adt::List<Comparable>::iterator itr = value.begin();
                std::string retString = "List:";
                for(int i = 0; i < value.size(); i++) {
                    retString += " value[" + std::to_string(i) + "]: " + std::to_string(*itr);
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
        }
    }
}

#endif  //CCLIB_COMMON_UTIL_H