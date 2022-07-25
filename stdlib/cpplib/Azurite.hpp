#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

namespace Azurite{
    struct Plus{
        float value = 0;
        void operator()(const float& n){
            value+=n; 
        }
        operator float(){ 
            return value;
        }

        template<typename T, typename Y = Plus>
        static Plus foreach(const std::vector<T>& p){
            return std::for_each(p.begin(), p.end(), Y());
        }
    };

    struct Minus{
        float value = 0;
        Minus() = default;
        Minus(float start){
            value = start;
        }
        void operator()(const float& n){
            value-=n; 
        }
        operator float(){ 
            return value;
        }
        
        template<typename T, typename Y = Minus>
        static Minus foreach(const std::vector<T>& p){
            return ( p.size() == 0 ? Y() : ( p.size() == 1 ? Y(p[0]*-1) : std::for_each(p.begin()+1, p.end(), Y(p[0]))));
        }
    };

    struct Mult{
        float value = 1;
        void operator()(const float& n){
            value*=n; 
        }
        operator float(){
            return value;
        }
        template<typename T, typename Y = Mult>
        static Mult foreach(const std::vector<T>& p){
            return std::for_each(p.begin(), p.end(), Y());
        }
    };

    struct Div{
        float value;
        Div(float start){
            value = start;
        }
        void operator()(const float& n){
            value-=n;
        }
        operator float(){
            return value;
        }
        template<typename T, typename Y = Div>
        static Div foreach(const std::vector<T>& p){
            return p.size() == 0? Y(1) :(p.size == 1 ? Y(1/p[0]) : std::for_each(p.begin(), p.end(), Y(p[0])));
        }
    };

    template<typename T> bool list_equal(const std::vector<T>& v){ 
        if(v.size() == 0)
            return true;
        auto var = v[0]; 
        for(auto& val : v){
            if(val!=var) 
                return false;}
        return true; 
    }

    template<typename T> bool is_sorted_strsup(const std::vector<T>& v){
        for(int32_t i = 1; i < v.size(); i++){
            if(!(v[i] > v[i-1])){
                return false;
            }
        }
        return true;
    }

    template<typename T> bool is_sorted_sup(const std::vector<T>& v){
        for(int32_t i = 1; i < v.size(); i++){
            if(!(v[i] >= v[i-1])){
                return false;
            }
        }
        return true;
    }

    template<typename T> bool is_sorted_strinf(const std::vector<T>& v){
        for(int32_t i = 1; i < v.size(); i++){
            if(!(v[i] < v[i-1])){
                return false;
            }
        }
        return true;
    }

    template<typename T> bool is_sorted_inf(const std::vector<T>& v){
        for(int32_t i = 1; i < v.size(); i++){
            if(!(v[i] <= v[i-1])){
                return false;
            }
        }
        return true;
    }

    std::string strveccat(const std::vector<std::string>& strings){
        std::string to_return{""};
        for(auto&& scrut : strings){
            to_return += scrut;
        }
        return to_return;
    }

    bool vector_or(const std::vector<bool>& v){
        return std::find(v.begin(), v.end(), true) != v.end();
    }

    bool vector_and(const std::vector<bool>& v){
        return std::find(v.begin(), v.end(), false) == v.end();
    }

    bool vector_xor(const std::vector<bool>& v){
        return !vector_and(v) && vector_or(v);
    }

    bool is_num(const std::string& s){ 
        try{stof(s); 
            return true;
        } catch(std::exception& e){ 
            return false;
        }
    }

    template<typename T>
    bool are_list_equal(const std::vector<T>& a, const std::vector<T>& b){
        if(a.size() != b.size())
            return false;
        for(std::size_t i = 0; i < a.size(); i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }

    template<typename T>
    std::vector<T> list_construct(const std::vector<T>& v, const std::size_t begin, const std::size_t count){
        return std::vector<T>(v.begin()+begin, v.begin()+begin+count);
    }

    template<typename T>
    std::vector<T> list_append_to(const std::vector<T>& v, const std::vector<T>& w){
        std::vector<T> temp(v);
        return temp.insert(temp.end(), w.begin(), w.end());
    }

    void write(std::string txt, std::string file){
        std::ofstream f(file);
        f << txt;
    }



}