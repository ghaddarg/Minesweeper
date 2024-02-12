#include <iostream>
#include <vector>

using namespace std;

void print_matrix(std::vector<vector<bool>> matrix)
{
    std::cout << "ORIGINAL MATRIX" << std::endl;

    std::cout << "[";
    for (std::vector<vector<bool>>::iterator it = matrix.begin(); it != matrix.end(); ++it) {
        
        std::cout << "[";
        for (std::vector<bool>::iterator itx = (*it).begin(); itx != (*it).end(); ++itx) {
            std::cout << *itx << ", ";
        }
        std::cout << "]";
        
        if (it != matrix.end() - 1)
            std::cout << std::endl;
    }
    
    std::cout << "]" << std::endl;
    std::cout << std::endl;
}

void print_solution_(std::vector<vector<int>> matrix)
{
    std::cout << "SOLUTION MATRIX" << std::endl;
    std::cout << "[";
    for (std::vector<vector<int>>::iterator it = matrix.begin(); it != matrix.end(); ++it) {
        
        std::cout << "[";
        for (std::vector<int>::iterator itx = (*it).begin(); itx != (*it).end(); ++itx) {
            std::cout << *itx << ", ";
        }
        std::cout << "]";
        
        if (it != matrix.end() - 1)
            std::cout << std::endl;
    }
    
    std::cout << "]" << std::endl;
}

int find_num_mines(std::vector<vector<bool>>::iterator sub_matrix, int idx)
{
    int mines = 0;
    for (std::vector<bool>::iterator itx = sub_matrix->begin(); itx != sub_matrix->end(); ++itx) {
        
        if ((*itx) && (itx - sub_matrix->begin() == idx))
            ++mines;
        else if ((*itx) && (itx - sub_matrix->begin() == idx + 1))
            ++mines;
        else if ((*itx) && (itx - sub_matrix->begin() == idx - 1))
            ++mines;
    }
    return mines;
}

std::vector<vector<int>> solution(std::vector<vector<bool>> matrix)
{
    size_t len_x = matrix.size(), len_y = (matrix.at(0)).size();
    std::vector<vector<int>> ret;
    
    std::cout << "x: " << len_x << std::endl;
    std::cout << "y: " << len_y << std::endl;
    
    print_matrix(matrix);
    
    for (std::vector<vector<bool>>::iterator it = matrix.begin(); it != matrix.end(); ++it) {
        
        std::vector<int> temp;
        
        for (std::vector<bool>::iterator itx = it->begin(); itx != it->end(); ++itx) {
            
            int num = 0;
            
            // Check if mine exists before
            if (itx != it->begin() && *(itx - 1))
                ++num;
            // Check if min exists after
            if (itx != (it->end() - 1) && *(itx + 1))
                ++num;
            //std::cout << num << std::endl;
            
            // Check if mine exists above  
            // Check if mine exists below
            // Check if mine exists diagonally
            int index = itx - it->begin();
            if (it != matrix.begin())
                num += find_num_mines(it - 1, index);
            if (it != matrix.end() - 1)
                num += find_num_mines(it + 1, index);
                
            temp.push_back(num);
        }
        
        ret.push_back(temp);
    }
     
    return ret;
}

int main(void)
{
    std::cout << "HELLO MINESWEEPER" << std::endl;
    /*
        matrix = [[true, false, false],
          [false, true, false],
          [false, false, false]]
    */
    std::vector<bool> v;
    std::vector<vector<bool>> matrix;
    std::vector<vector<int>> sol;

    v.push_back(true);
    v.push_back(false);
    v.push_back(false);

    matrix.push_back(v);
    v.clear();

    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    matrix.push_back(v);
    v.clear();

    v.push_back(false);
    v.push_back(false);
    v.push_back(false);

    matrix.push_back(v);
    v.clear();

    sol = solution(matrix);

    print_solution_(sol);
    std::cout << "GDBYE MINESWEEPER" << std::endl;

    return EXIT_SUCCESS;
}
