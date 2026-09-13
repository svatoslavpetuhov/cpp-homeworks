#include <iostream>
#include <optional>
#include <fstream>
#include <string>

class Generator{
    private:
        int start_value_;
        int total_;

        int current_;
        int remaining_;
    
    public:
        Generator(int start, int remain)
            : current_(start),
            remaining_(remain),
            start_value_(start),
            total_(remain) {}

        std::optional<int> next(){
            if (remaining_ <= 0){
                return std::nullopt;
            }
            --remaining_;
            return current_++;
        }

        void reset(){
            current_ = start_value_;
            remaining_ = total_;
        }
};

void write_secuence(std::ostream& os, Generator& gen){
    while (auto val = gen.next()){
        os << *val << " ";
    }
    os << "\n";
}

int main(){
    Generator seq(1, 30);
    write_secuence(std::cout, seq);

    std::string text_filename = "result_text.txt";
    std::string bin_filename = "result_bin.bin";
    
    seq.reset();

    std::ofstream file_out(text_filename);

    if (!file_out.is_open()){
        std::cerr << "Файл " << text_filename << "недоступен" << std::endl;
        return 1;
    }

    write_secuence(file_out, seq);
    file_out.close();

    std::ifstream text_in(text_filename);
    std::ofstream bin_out(bin_filename);

    if ((!text_in.is_open()) || (!bin_out.is_open()) ){
        std::cerr << "Файл недоступен" << std::endl;
        return 1;
    }

    int buffer;
    while(text_in >> buffer){
        bin_out.write(reinterpret_cast<const char*> (&buffer), sizeof(buffer));
    }

    std::cout << "\n Программа выполнена успешно" << std::endl;
    return 0;
}