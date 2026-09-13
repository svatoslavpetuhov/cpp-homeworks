#include <iostream>
#include <fstream>
#include <stdexcept>
#include <optional>

class Fibonachi{
    private:
    int const first_init_, second_init_, total_count_;
    int curr_, remaining_, next_;
    
    public:
    Fibonachi(int first, int second, int count)
    : first_init_(first), second_init_(second), total_count_(count), 
    curr_(first), next_(second), remaining_(count) {}

    void reset() {
        curr_ = first_init_;
        next_ = second_init_;
        remaining_ = total_count_;
    }

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

void write_secuence(std::ostream& os, Fibonachi& fi) {
    int i = 1;
    while (auto val = fi.next()) {
        os << i << " " << *val << "\n" ;
        ++i;
    }

    os << "\n";
}

int main(int argc, char* argv[]){
    if (argc < 2) {
        std::cerr << "не введено число" << std::endl;
        return 1;
    }

    int n = 0;

    try {
        n = std::stoi(argv[1]);
    } catch(std::exception& e) {
        std::cerr << "должно быть целое положительное число" << std::endl;
        return 1;
    }
    
    if (n <= 0){
        std::cerr << "должно быть целое положительное число" << std::endl;
        return 1;
    }

    Fibonachi fib(1, 1, n);

    write_secuence(std::cout, fib);

    return 0;
}