#ifndef SUDOKUINPUT_HPP
#define SUDOKUINPUT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
namespace sudoku {
class SudokuInput {
    public:
        SudokuInput();
            
        ~SudokuInput();

        void setString(const std::string& str);

        void add(const std::string& str);
        const std::string getString() const;
    private:
        std::string strError();
    
        std::string numError();

        void checkNum();
        void checkStringLength(const std::string& str);
        std::string s_;
        int num_;
};
} // End namespace sudoku

#endif
