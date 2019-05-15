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
#include <iostream>

using namespace std;

namespace cclib {
    namespace common {
        namespace util {
            template<typename Comparable>
            inline void printVectorValue(vector<Comparable> value) {
                string retString = "vector:";
                for(int i = 0; i < value.size(); i++) {
                    retString += " value[" + to_string(i) + "]: " + to_string(value[i]);
                }
                cout << retString << endl;
            };

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