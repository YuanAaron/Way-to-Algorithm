#include "BreadthFirstSearch.hpp"
#include <cassert>
using namespace std;

#define TEST_M_MAX MAX
#define TEST_N_MAX MAX

void AssertAdjacent(const Position & a, const Position & b)
{
    bool a1 = (a.row == b.row) and (a.col == b.col + 1);
    bool a2 = (a.row == b.row) and (a.col == b.col - 1);
    bool a3 = (a.row == b.row + 1) and (a.col == b.col);
    bool a4 = (a.row == b.row - 1) and (a.col == b.col);
    assert(a1 or a2 or a3 or a4);
}

int main()
{
    for (int i = 1; i < TEST_M_MAX; i++)
        for (int j = 1; j < TEST_N_MAX; j++) {
            Position beg(0, 0);
            Position end(i - 1, j - 1);
            vector<Position> path = BreadthFirstSearch(i, j, beg, end);
            /* 保证路径长度为 j-1+i-1+1 */
            assert(path.size() == (i - 1 + j - 1 + 1));
            /* 保证起点和终点位置 */
            assert(path[0] == beg);
            assert(path[path.size() - 1] == end);
            for (int k = 0; k < path.size() - 1; k++) {
                /* 保证路径中相邻两点在二维方格中也是相邻点 */
                AssertAdjacent(path[k], path[k+1]);
            }
        }

    return 0;
}
