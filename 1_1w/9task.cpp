#include <iostream>
#include <optional>
#include <iomanip>
#include <array>

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

int main(){
    constexpr std::size_t ARRAY_SIZE = 10;
    Harmonic hm(1, ARRAY_SIZE);

    std::array<double, ARRAY_SIZE> my_array = {};

    for (auto& el : my_array){
        if(auto val = hm.next()){
            el = *val;
        }
    }

    std::cout << std::scientific << std::setprecision(4);

    for (auto el : my_array){
        std::cout << el << std::endl;
    }

    std::cout << "\n";
}