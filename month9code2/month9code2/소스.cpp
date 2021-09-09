#include <string>
#include <vector>
#include <iostream>
using namespace std;

void fplus(int& n)
{
    n++;
}
void fminus(int& n)
{
    n--;
}

vector<int> solution(vector<string> grid) {
    int rowsize = grid.size() + grid.size();
    int colsize = grid[0].length() + grid[0].length();

    int** arr = new int* [rowsize + 1];
    for (int i = 0; i < rowsize + 1; i++)
        arr[i] = new int[colsize + 1]{ 0, };
    int fir = 0;
    int sec = 0;
    for (int i = 1; i < rowsize + 1; i += 2)
    {
        for (int j = 1; j < colsize + 1; j += 2)
        {
            arr[i][j] = grid[fir][sec];
            sec++;
        }
        fir++;
        sec = 0;
    }
    
    vector<int> answer;
    for (int rownum = 1; rownum < rowsize; rownum += 2)
    {
        for (int colnum = 1; colnum < colsize; colnum += 2)
        {
            for (int directnum = 1; directnum <= 4; directnum++)
            {
                int row = rownum;
                int col = colnum;
                int direct = directnum;
                answer.push_back(0);
                while (1)
                {
                    if (direct == 1)
                    {
                        if (arr[row][col] == 'S')
                        {
                            fplus(col);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (col == colsize)
                            {
                                col = 0;
                                arr[row][col]++;
                            }
                            fplus(col);
                        }
                        else if (arr[row][col] == 'L')
                        {
                            direct = 3;
                            fminus(row);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (row == 0)
                            {
                                row = rowsize;
                                arr[row][col]++;
                            }
                            fminus(row);
                        }
                        else if (arr[row][col] == 'R')
                        {
                            direct = 4;
                            fplus(row);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (row == rowsize)
                            {
                                row = 0;
                                arr[row][col]++;
                            }
                            fplus(row);
                        }
                        answer.back()++;
                    }
                    else if (direct == 2)
                    {
                        if (arr[row][col] == 'S')
                        {
                            fminus(col);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (col == 0)
                            {
                                col = colsize;
                                arr[row][col]++;
                            }
                            fminus(col);
                        }
                        else if (arr[row][col] == 'L')
                        {
                            direct = 4;
                            fplus(row);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (row == rowsize)
                            {
                                row = 0;
                                arr[row][col]++;
                            }
                            fplus(row);
                        }
                        else if (arr[row][col] == 'R')
                        {
                            direct = 3;
                            fminus(row);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (row == 0)
                            {
                                row = rowsize;
                                arr[row][col]++;
                            }
                            fminus(row);
                        }
                        answer.back()++;
                    }
                    else if (direct == 3)
                    {
                        if (arr[row][col] == 'S')
                        {
                            fminus(row);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (row == 0)
                            {
                                row = rowsize;
                                arr[row][col]++;
                            }
                            fminus(row);
                        }
                        else if (arr[row][col] == 'L')
                        {
                            direct = 2;
                            fminus(col);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (col == 0)
                            {
                                col = colsize;
                                arr[row][col]++;
                            }
                            fminus(col);
                        }
                        else if (arr[row][col] == 'R')
                        {
                            direct = 1;
                            fplus(col);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (col == colsize)
                            {
                                col = 0;
                                arr[row][col]++;
                            }
                            fplus(col);
                        }
                        answer.back()++;
                    }
                    else if (direct == 4)
                    {
                        if (arr[row][col] == 'S')
                        {
                            fplus(row);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (row == rowsize)
                            {
                                row = 0;
                                arr[row][col]++;
                            }
                            fplus(row);
                        }
                        else if (arr[row][col] == 'L')
                        {
                            direct = 1;
                            fplus(col);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (col == colsize)
                            {
                                col = 0;
                                arr[row][col]++;
                            }
                            fplus(col);
                        }
                        else if (arr[row][col] == 'R')
                        {
                            direct = 2;
                            fminus(col);
                            if (arr[row][col] == 2) break;
                            arr[row][col]++;
                            if (col == 0)
                            {
                                col = colsize;
                                arr[row][col]++;
                            }
                            fminus(col);
                        }
                        answer.back()++;
                    }
                }
            }
        }
    }
    


    /*for (int i = 0; i < grid.size() + grid.size() + 1; i += 1)
    {
        for (int j = 0; j < grid[0].length() + grid[0].length() + 1; j += 1)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    */
    //answer.erase(remove_if(answer.begin(), answer.end(), 0), answer.end());
    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i] == 0)
        {
            answer.erase(answer.begin() + i);
            i--;
        }
    }
    return answer;
}
int main()
{
    vector<int>a=solution({ "S" });
    cout << a[0];
}