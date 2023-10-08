#include <iostream>
#include <math.h>
#include <vector>
#include <string>

void swap(char &a, char &b);
void substring_reversal(std::string &string, int first, int last, std::vector<std::vector<int>> operation_description,int interval_index);
std::vector<std::vector<int>> getMatrix_of_operations(int number_of_operations, std::vector<int> array_l, std::vector<int> array_r);


template<typename type>
std::vector<type> input_array(int size){
    std::vector<type> res = std::vector<type>(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> res[i];
    }
    
    return res;
}




void swap(char &a, char &b){
    char c = a;
    a = b;
    b = c;
}

std::vector<std::vector<int>> getMatrix_of_operations(int number_of_operations, std::vector<int> array_l, std::vector<int> array_r){
    std::vector<std::vector<int>> res =std::vector<std::vector<int>>(array_l.size());
    int current_operation;
    for (int i = 0; i < number_of_operations; ++i)
    {
        std::cin >> current_operation;
        for (size_t j = 0; j < res.size(); ++j)
        {
            if(current_operation >= array_l[j] && current_operation <= array_r[j]){
                res[j].push_back(current_operation);
                break;
            }
        }
        
    }
    return res;
    
}

void substring_reversal(std::string &string, int first, int last, std::vector<std::vector<int>> operation_description, int interval_index){
std::vector<int> number_of_operations_per_index = std::vector<int>((last - first)/2 + 1, 0); 
int current_operation;
    for (size_t i = 0; i < operation_description[interval_index].size(); i++)
    {
        current_operation = operation_description[interval_index][i] - 1;

            if (current_operation > (first + last)/2 )
                current_operation = last + first - operation_description[interval_index][i] + 1;
            for (int j = 0; j < (last - first)/2 + 1; ++j)
            {
                if(current_operation <=  first + j)
                    ++number_of_operations_per_index[j];
            }
            
    }

   for (size_t j = 0; j < number_of_operations_per_index.size(); ++j){
    if(number_of_operations_per_index[j] % 2 == 1){
        swap(string[first + j], string[last - j]);
    }
   }
}

int main(){

int number_of_inputs, array_size, number_of_operations, string_size;


std::cin >> number_of_inputs;
for (int i = 0; i < number_of_inputs; i++)
{
    std::cin >> string_size >> array_size;
    std::string string;
    std::cin >> string;
    std::vector<int> array_l =  input_array<int>(array_size);
    std::vector<int> array_r =  input_array<int>(array_size);
    std::cin >> number_of_operations;
    std::vector<std::vector<int>> operation_description = getMatrix_of_operations(number_of_operations,array_l,array_r);
        for (int j = 0; j < array_size; ++j)
        {
            substring_reversal(string, array_l[j] - 1, array_r[j] - 1, operation_description, j);
        }
        
    
    
    std::cout << string << '\n';
    
    
}


    return 0;
}