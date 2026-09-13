#include <iostream>
#include <optional>
#include <iomanip>
#include <vector>
#include <stdexcept>

class Harmonic {
    private:
    std::size_t curr_;
    std::size_t remaining_;
    public:
    Harmonic(std::size_t start, std::size_t count)
    : curr_(start), remaining_(count) {}

    std::optional<double> next() {
        if (remaining_ <= 0) {
            return std::nullopt;
        }

        const double result = 1.0/static_cast<double>(curr_);
        ++curr_;
        --remaining_;
        return result;
    }
};

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

    Harmonic hm(1, n);

    std::vector<double> my_vector(n);

    for (auto& el : my_vector){
        if(auto val = hm.next()){
            el = *val;
        }
    }

    std::cout << std::scientific << std::setprecision(4);

    for (auto el : my_vector){
        std::cout << el << std::endl;
    }

    std::cout << "\n";
}