#include <iostream>
#include <optional>

class Generator{
    private:
        int current_;
        int remaining_;
    
    public:
        Generator(int start, int remain)
            : current_(start), remaining_(remain) {}

        std::optional<int> next(){
            if (remaining_ <= 0){
                return std::nullopt;
            }
            --remaining_;
            return current_++;
        }
};

int main(){
    Generator seq(1, 30);

    while (auto val = seq.next()){
        std::cout << *val << " ";
    }

    return 0;
}