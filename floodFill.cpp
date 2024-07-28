// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and color.
// You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel,
// plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel
// plus any pixels connected 4-directionally to those pixels (also with the same color), and so on.
// Replace the color of all of the aforementioned pixels with color.
#include <iostream>
#include <vector>
// #define delRow [] { -1, 0, 1, 0 }
// #define delCol [] { 0, 1, 0, -1 }
const int delRow[] = {-1, 0, 1, 0};
const int delCol[] = {0, 1, 0, -1};
using namespace std;
// dfs = depth-first search, this is a method for floodFill
void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans,
         int preColor, int newColor, const int delRow[], const int delCol[])
{
    ans[row][col] = newColor;

    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            image[nrow][ncol] == preColor && ans[nrow][ncol] != newColor)
        {
            dfs(nrow, ncol, image, ans, preColor, newColor, delRow, delCol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int preColor = image[sr][sc];
    vector<vector<int>> ans = image;
    dfs(sr, sc, image, ans, preColor, newColor, delRow, delCol);
    return ans;
}

void printMatrix(vector<vector<int>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << ",";
        }
        cout << "]\n";
    }
}

int main()
{
    vector<vector<int>> a = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    printMatrix(a);
    cout << '\n';
    a = floodFill(a, 1, 1, 2);
    printMatrix(a);
    return 0;
}
