#include <vector>
#include <iostream>
#include <list>
#include <math.h>




template<typename Key, typename Value>
class Hashtable{

private:
    std::vector<std::list<std::pair<Key,Value>>> ArrayWithValue = std::vector<std::list<std::pair<Key,Value>>>();
    size_t size;
    size_t valid_size; 
    double fill_factor;
    size_t GetKey(Key key){
    return static_cast<size_t>((key) % this->size);
    }

    void resize(){

        if(fill_factor > 0.7){
            std::vector<std::list<std::pair<Key,Value>>> new_Array = std::vector<std::list<std::pair<Key,Value>>>(2*size);
            auto old_Array = ArrayWithValue;
            ArrayWithValue = new_Array;
            this->size *= 2;
            for (size_t i = 0; i < old_Array.size(); i++)
            {
                for (auto j : old_Array[i])
                {
                    inputValue(j);
                }
                
            }
        }

    }

    void Update_fill_factor(){
        fill_factor = static_cast<double>(valid_size)/static_cast<double>(size);
    }

public:
    Hashtable() 
        : size(10), valid_size(0), fill_factor(0){
            ArrayWithValue.resize(10);
        }

    Hashtable(size_t new_size) 
        : size(new_size), valid_size(0), fill_factor(0){
            ArrayWithValue.resize(new_size);
        }

    ~Hashtable(){
    }    

    size_t HashFunction(Key key);
    
    void inputValue(Key key, Value value){
    
        if(!HaveValue(key, value)){
        auto element = std::pair<Key, Value>(key, value);
        this->ArrayWithValue[GetKey(key)].push_back(element);
        ++valid_size;
        }
    
    } 

    void inputValue(std::pair<Key, Value> element){
        
        if(!HaveValue(element)){
        this->ArrayWithValue[GetKey(element.first)].push_back(element);
        ++valid_size;
        }
    
    } 

    bool HaveValue(Key key, Value value){
        
        for (std::pair<Key,Value> i : this->ArrayWithValue[GetKey(key)])
        {
            if( i.first == key && i.second == value)
                return true;
        }

        return false;        
    }

        bool HaveValue(std::pair<Key, Value> element){
        
        for (std::pair<Key,Value> i : this->ArrayWithValue[GetKey(element.first)])
        {
            if( i == element)
                return true;
        }

        return false;        
    }

    Value GetValue(Key key){
        Value result;
        for (std::pair<Key,Value> i : this->ArrayWithValue[GetKey(key)])
        {
            if( i.first == key){
                result = i.second;
                break;
            }
        }
        return result;
    }



};