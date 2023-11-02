#include <iostream>
#include <math.h>
#include <vector>


int binary_find_degree(int value, int min_degree, int max_degree){
if( value == 0)
    return -1;
int result = (max_degree + min_degree)/2;
if( (int)(pow(2, result)) > value)
    result = binary_find_degree(value,min_degree, result);
else if((int)(pow(2, result + 1)) < value)
    result = binary_find_degree(value,result,max_degree);
return result;
}



int Bitwise_And(int number_i, int number_j){
    int max_degree_i, max_degree_j, result = 0;
    max_degree_i = binary_find_degree(number_i, 0, 30);
    max_degree_j = binary_find_degree(number_j, 0, 30);
    while(number_i != 0 || number_j != 0){
        if(max_degree_i == max_degree_j){
            result += pow(2, max_degree_i);
            number_i -= pow(2, max_degree_i);
            number_j -= pow(2, max_degree_j);
        } else if(max_degree_i > max_degree_j){
            number_i -= pow(2, max_degree_i);
            max_degree_i = binary_find_degree(number_i, 0, 30);
        } else{
            number_j -= pow(2, max_degree_j);
            max_degree_j = binary_find_degree(number_j, 0, 30);
        }
    }
    return result;
}


int Bitwise_Excluding_Or(int number_i, int number_j){
    int max_degree_i, max_degree_j, result = 0;
    max_degree_i = binary_find_degree(number_i, 0, 30);
    max_degree_j = binary_find_degree(number_j, 0, 30);
    while(number_i != 0 || number_j != 0){
        if(max_degree_i == max_degree_j){
            number_i -= pow(2, max_degree_i);
            number_j -= pow(2, max_degree_j);
        } else if(max_degree_i > max_degree_j){
            result += pow(2, max_degree_i);
            number_i -= pow(2, max_degree_i);
            max_degree_i = binary_find_degree(number_i, 0, 30);
        } else{
            result += pow(2, max_degree_j);
            number_j -= pow(2, max_degree_j);
            max_degree_j = binary_find_degree(number_j, 0, 30);
        }
    }
    return result;
}


int Task_Answer(std::vector<int> &arr){
int result = 0;
for (size_t i = 0; i < arr.size() - 1; ++i)
{
    for (size_t j = i + 1; j < arr.size(); ++j)
    {
        if(Bitwise_And(arr[i], arr[j]) >= Bitwise_Excluding_Or(arr[i], arr[j]))
            ++result;
    }
    
}

return result;
}

int main(){
size_t number_of_inputs, ArraySize;
std::vector<int> array;
std::cin >> number_of_inputs;
for (size_t i = 0; i < number_of_inputs; ++i)
{
    std::cin >> ArraySize;
    array.resize(ArraySize);
    for (size_t j = 0; j < ArraySize; ++j)
    {
        std::cin >> array[j];
    }

    std::cout << Task_Answer(array) <<'\n';
    
}


    return 0;
}