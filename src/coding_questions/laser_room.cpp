// may mobility
// autonomy engineer
// on hackerearth (timed take home)

#include <iostream>
#include <unordered_map>
#include <vector>

constexpr int GRID_SIZE{8};

void parseInput(const int& num, std::pair<int, int>& hero,
                std::unordered_map<int, int>& cannons_row,
                std::unordered_map<int, int>& cannons_col);

bool checkBounds(std::pair<int, int> state);

bool isBlockSafe(std::pair<int, int>& hero,
                 std::unordered_map<int, int>& cannons_row,
                 std::unordered_map<int, int>& cannons_col);

bool isHeroDoomed(std::pair<int, int>& hero,
                  std::unordered_map<int, int>& cannons_row,
                  std::unordered_map<int, int>& cannons_col);

// Over the algorithm is:
// Time complexity: O(1)
// Space complexity: O(1)
int main()
{
    int num{0};
    std::pair<int, int> hero{0, 0};
    std::unordered_map<int, int> cannons_row;
    std::unordered_map<int, int> cannons_col;

    // parseInput(num, hero, cannons_row, cannons_col);

    // cannons_row[1]++;
    // cannons_col[1]++;

    // cannons_row[0]++;
    // cannons_col[5]++;

    if (isBlockSafe(hero, cannons_row, cannons_col))
    {
        std::cout << "safe\n";
    }
    else
    {
        if (!isHeroDoomed(hero, cannons_row, cannons_col))
        {
            std::cout << "escaped\n";
        }
        else
        {
            std::cout << "doomed\n";
        }
    }

    return 0;
}

void parseInput(const int& num, std::pair<int, int>& hero,
                std::unordered_map<int, int>& cannons_row,
                std::unordered_map<int, int>& cannons_col)
{
    std::cin >> hero.first;
    std::cin >> hero.second;

    for (int i = 0; i < num - 1; i++)
    {
        int row{0};
        int col{0};
        std::cin >> row;
        std::cin >> col;
        cannons_row[row]++;
        cannons_col[col]++;
    }
}

bool checkBounds(std::pair<int, int> state)
{
    if (state.first < 0 || state.second < 0)
    {
        return false;
    }

    if (state.first >= GRID_SIZE || state.second >= GRID_SIZE)
    {
        return false;
    }
    return true;
}

// Time complexity: O(1); since unordered map's find function has O(1) time
// complexity.
// Space complexity: O(1); no space used.
bool isBlockSafe(std::pair<int, int>& hero,
                 std::unordered_map<int, int>& cannons_row,
                 std::unordered_map<int, int>& cannons_col)
{
    if (cannons_row.find(hero.first) == cannons_row.end() &&
        cannons_col.find(hero.second) == cannons_col.end())
    {
        return true;
    }
    return false;
}

// Time complexity: O(1); since the search space will always be immediate
// adjacent connected spaces.
// Space complexity: O(1); since only a pair is stored.
bool isHeroDoomed(std::pair<int, int>& hero,
                  std::unordered_map<int, int>& cannons_row,
                  std::unordered_map<int, int>& cannons_col)
{
    std::pair<int, int> safeMove;

    for (int r = -1; r < 2; r++)
    {
        for (int c = -1; c < 2; c++)
        {
            safeMove.first = hero.first + r;
            safeMove.second = hero.second + c;
            std::cout << "(" << safeMove.first << ", ";
            std::cout << safeMove.second << ") ";
            std::cout << (checkBounds(safeMove) &&
                          isBlockSafe(safeMove, cannons_row, cannons_col))
                      << '\n';

            // Hero is not doomed
            if (checkBounds(safeMove) &&
                isBlockSafe(safeMove, cannons_row, cannons_col))
            {
                return false;
            }
        }
    }

    // Hero is doomed
    return true;
}
