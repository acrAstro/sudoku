#include "SudokuInput.hpp"

namespace sudoku {

SudokuInput::SudokuInput() : num_{0} {}
SudokuInput::~SudokuInput() {}

void SudokuInput::add(const std::string& str) {
    checkStringLength(str);
    checkNum();
}

void SudokuInput::setString(const std::string& str) {
    this->s_ = str;
}

const std::string SudokuInput::getString() const {
    return s_;
}

std::string SudokuInput::strError() {
    std::string err1 = "ERROR: input string must be length 9\n";
    std::string err2 = "Input problem data with zeros where the spaces are";
    return (err1+err2);
}

std::string SudokuInput::numError() {
    std::string err1 = "ERROR: too many rows of the puzzle!";
    return err1;
}

void SudokuInput::checkNum() {
    try {
         bool valid = (num_ <= 9);
         if (!valid) {
             throw std::invalid_argument(numError());
         }
    } catch (std::invalid_argument &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void SudokuInput::checkStringLength(const std::string& str) {
    try {
        bool valid = (str.size() == 9);
        if (valid) {
            s_.append(str);
            num_++;
        } else {
            throw std::invalid_argument(strError());
        }
    } catch (std::invalid_argument &ex) {
        std::cout << ex.what() << std::endl;
    }
}


} // End namespace sudoku
