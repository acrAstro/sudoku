#ifndef SUDOKUSOLVER_HPP
#define SUDOKUSOLVER_HPP

#include "SudokuInput.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <array>

namespace sudoku {

class SudokuSolver {
    public:
        static void author();
        SudokuSolver(const SudokuInput& input);
        void solve();
        int count() const;

    protected:
        void placeNumber(int pos);
        bool checkValidity(int val, int x, int y);
        std::string toString();
    
    private:
        std::array<int, 81> grid_;
        int counter_;
};
} // End namespace sudoku
#endif
