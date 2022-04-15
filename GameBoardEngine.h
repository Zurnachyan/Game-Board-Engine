#ifndef __GameBoardEngine__
#define __GameBoardEngine__

#include <iostream>
#include <vector>

template <typename T>
class Board {
    public:
        Board();
        Board(std::size_t width, std::size_t height);
        Board(const Board& ob);
        Board(const Board&& ob);
        ~Board() = default;
    public:
        Board& operator =(const Board& ob);
        Board& operator =(const Board&& ob);
    public:
        void set(std::size_t width, std::size_t height) { _width = {width}; _height = {height}; }
        int getWidth() const { return _width; }
        int getHeight() const { return _height; }
        void initializeCellsContainer(std::size_t columnIndex, std::size_t rowIndex, T elem);
    private:
        static const std::size_t defWidth = 8;
        static const std::size_t defHeight = 8;
        std::size_t _height;
        std::size_t _width;
        std::vector<std::vector<T>> _cells;
};

template<typename T>
Board<T>::Board() : _width{defWidth}, _height{defHeight}
{
    _cells.resize(_width);
    for(auto& x : _cells) {
        x.resize(_height);
    }
}

template<typename T>
Board<T>::Board(std::size_t width, std::size_t height) : _width{width}, _height{height}
{
    _cells.resize(width);
    for(auto& x : _cells) {
        x.resize(height);
    }
}

template<typename T>
Board<T>::Board(const Board<T>& ob) : _width{ob._width}, _height{ob._height},
                                   _cells{ob._cells}
{}

template<typename T>
Board<T>::Board(const Board<T>&& ob) : _width{ob._width}, _height{ob._height},
                                    _cells{ob._cells}
{}

template<typename T>
Board<T>& Board<T>::operator=(const Board<T>& ob) {
    if(this == &ob) {
        return *this;
    }
    _width = ob._width;
    _height = ob._height;
    _cells = ob._cells;

    return *this;
}

template<typename T>
Board<T>& Board<T>::operator =(const Board<T>&& ob) {
    if(this == &ob) {
        return *this;
    }
    _width = ob._width;
    _height = ob._height;
    _cells = ob._cells;

    return *this;
}

template<typename T>
void Board<T>::initializeCellsContainer(std::size_t rowIndex, std::size_t columnIndex, T elem) {
    if(rowIndex >= _height) {
        std::cout << "Invalid row index" << std::endl;
        std::abort();
    }

    if(columnIndex >= _width) {
        std::cout << "Invalid column index" << std::endl;
        std::abort();
    }

    _cells[rowIndex][columnIndex] = elem;
}

#endif