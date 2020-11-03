#include <iostream>
#include <cmath>

/*

Решение кв. ур. через дискриминант: 
    D = b^2 - 4*a*c
    Где: a != 0

Если D > 0, вычисляются корни

            -b + sqrt(D)
    x1 = ----------------------
                2a

            -b - sqrt(D)
    x2 = ----------------------
                2a

a, b, c - ограничены диапазонами

*/

long readRangeLimitedValue(std::string valueName, std::string errRetryText, long minLim, long maxLim) {
    long userValue{};
   
    for (;;) {        
        std::cout << "Enter '" <<  valueName << "' argument in range ["<< minLim<< "..."<< maxLim << "]: ";
        std::cin >> userValue;

        if ( (userValue >= minLim) && (userValue <= maxLim) ) {
            return userValue;
        } else {
            std::cout << errRetryText << std::endl;
        }                
    }            
}

long readRangeLimitedNonZeroValue(std::string valueName, std::string errRetryText, long minLim, long maxLim) {    
    constexpr auto ZERO{0};
    long userValue{};    

    for (;;) {        
        std::cout << "Enter '" <<  valueName << "' argument in range ["<< minLim<< "..."<< maxLim << "], not equal to ZERO: ";
        std::cin >> userValue;

        if ( (userValue >= minLim) && (userValue <= maxLim) && (userValue != ZERO)) {
            return userValue;
        } else {
            std::cout << errRetryText << std::endl;
        }                
    }                   
}

int main(int argc, char const *argv[])
{
    constexpr auto ERR_MSG_OUT_OF_RANGE{"ERROR! Entered value is out of range"};
    
    constexpr auto FORMULA_CONST_FOUR{4};
    constexpr auto FORMULA_CONST_TWO{2};            
    
    constexpr auto FORMULA_A_MIN_LIM{1};
    constexpr auto FORMULA_A_MAX_LIM{15};

    constexpr auto FORMULA_B_MIN_LIM{1};
    constexpr auto FORMULA_B_MAX_LIM{15};

    constexpr auto FORMULA_C_MIN_LIM{200};
    constexpr auto FORMULA_C_MAX_LIM{400};    

    auto a = readRangeLimitedNonZeroValue("A", ERR_MSG_OUT_OF_RANGE, FORMULA_A_MIN_LIM, FORMULA_A_MAX_LIM);
    auto b = readRangeLimitedValue("B", ERR_MSG_OUT_OF_RANGE, FORMULA_B_MIN_LIM, FORMULA_B_MAX_LIM);
    auto c = readRangeLimitedValue("С", ERR_MSG_OUT_OF_RANGE, FORMULA_C_MIN_LIM, FORMULA_C_MAX_LIM);

    // D = b^2 - 4*a*c
    long long d = (b^2) - FORMULA_CONST_FOUR * a * c;

    if (d != 0) {
        // x1 = -b + sqrt(D) / 2a
        // x2 = -b - sqrt(D) / 2a                
        long long divider = FORMULA_CONST_TWO * a;

        if (divider == 0) {
            std::cout << "ERROR! Unable to calculate roots. Division by ZERO.";
            return 1;
        }

        long x1 = (-b) + sqrt(d) / divider;
        long x2 = (-b) - sqrt(d) / divider;
        std::cout << "Roots are:" << std::endl 
            << "\tx1 = " << x1 << std::endl
            << "\tx2 = " << x2 << std::endl;


    } else {
        std::cout << "There is no roots. D is equal to ZERO" << std::endl;
    }
    
    return 0;
}
