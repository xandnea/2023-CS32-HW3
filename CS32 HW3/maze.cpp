#include <string>
#include <iostream>

using namespace std;

class Coord
{
public:
    Coord(int r, int c) : m_row(r), m_col(c) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
private:
    int m_row;
    int m_col;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {

    Coord curr(sr, sc);
    Coord end(er, ec);

    if (maze[sr][sc] == '.')
        maze[sr][sc] = 'o';

    if ((curr.r() == end.r()) && (curr.c() == end.c()))
        return true;

    if (((curr.c() + 1) < nCols - 1) && maze[curr.r()][curr.c() + 1] == '.') {              // EAST
        Coord temp(curr.r(), curr.c() + 1);
        if (pathExists(maze, nRows, nCols, curr.r(), curr.c() + 1, er, ec))
            return true;
    }

    if (((curr.r() - 1) > 0) && maze[curr.r() - 1][curr.c()] == '.') {                  // NORTH
        Coord temp(curr.r() - 1, curr.c());
        if (pathExists(maze, nRows, nCols, curr.r() - 1, curr.c(), er, ec))
            return true;
    }

    if (((curr.c() - 1) > 0) && maze[curr.r()][curr.c() - 1] == '.') {                  // WEST
        Coord temp(curr.r(), curr.c() - 1);
        if (pathExists(maze, nRows, nCols, curr.r(), curr.c() - 1, er, ec))
            return true;
    }

    if (((curr.r() + 1) < nRows - 1) && maze[curr.r() + 1][curr.c()] == '.') {              // SOUTH
        Coord temp(curr.r() + 1, curr.c());
        if (pathExists(maze, nRows, nCols, curr.r() + 1, curr.c(), er, ec))
            return true;
        
    }

    return false;
}

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X..X...X.X",
        "X.XXXX.X.X",
        "X.X.X..X.X",
        "X...X.XX.X",
        "XXX......X",
        "X.X.XXXX.X",
        "X.XXX....X",
        "X...X..X.X",
        "XXXXXXXXXX"
    };

    if (pathExists(maze, 10, 10, 5, 3, 8, 8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}