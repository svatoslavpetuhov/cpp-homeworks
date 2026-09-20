#include <iostream>
#include <fstream>
#include <stdexcept>
#include <optional>
#include <array>
#include <algorithm>
#include <iterator>

class Fibonachi{
    private:
    int const first_init_, second_init_, total_count_;
    int curr_, remaining_, next_;
    
    public:
    Fibonachi(int first, int second, int count)
    : first_init_(first), second_init_(second), total_count_(count), 
    curr_(first), next_(second), remaining_(count) {}

    std::optional<int> next() {
        if (remaining_ <= 0){
            return std::nullopt;
        }
        const int result = curr_;
        const int new_next = next_ + curr_;
        curr_ = next_;
        next_ = new_next;

        --remaining_;

        return result;
    }
};

int main(){
    constexpr std::size_t ARRAY_SIZE = 10;

    Fibonachi fib(1, 1, ARRAY_SIZE);
    std::array<int, ARRAY_SIZE> my_array = {};

    for(auto& el : my_array) {
        if(auto val = fib.next()){
            el = *val;
        }
    }
    
    std::copy(my_array.begin(), my_array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n \n" << std::endl;
    std::cout << "The program has been successfully completed" << std::endl;

    return 0;
}