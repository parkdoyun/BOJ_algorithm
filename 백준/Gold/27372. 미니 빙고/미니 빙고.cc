#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 점수 문자열 구하기
// 점수 문자열 -> 시드 문자열
// DFS?
// 전부 다 확인해봐야 할듯
// 2. 시드 문자열 전부 구해서 사전순으로 string sort
// 3. 첫번째 시드 문자열 출력

vector<string> string_vec;

char origin_board[3][3];

string seed_str; // seed string

// 이미 채워졌으면 1
int chk_board[3][3];

// 점수 문자열 배열
int score_string[10];

// 각 문자의 위치 저장
int char_pos[9][2]; // char_pos[n][0] : y 좌표, char_pos[n][1] : x 좌표

// 한번에 얻는 점수 계산
int cal_score(int ty, int tx)
{
    int tmp_res = 0;
    int flag = 0;
    
    // 행 확인
    for(int i = 0; i < 3; i++)
    {
        if(chk_board[ty][i] == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0) tmp_res++;

    // 열 확인
    flag = 0;
    for(int i = 0; i < 3; i++)
    {
        if(chk_board[i][tx] == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0) tmp_res++;

    // 대각선 확인
    if((ty == 0 && tx == 0) || (ty == 1 && tx == 1) || (ty == 2 && tx == 2))
    {
        flag = 0;
        for(int i = 0; i < 3; i++)
        {
            if(chk_board[i][i] == 0)
            {
                flag = 1;
                break;            
            }
        }
        if(flag == 0) tmp_res++;
    }
    if((ty == 0 && tx == 2) || (ty == 1 && tx == 1) || (ty == 2 && tx == 0))
    {
        flag = 0;
        for(int i = 0; i < 3; i++)
        {
            if(chk_board[2 - i][i] == 0)
            {
                flag = 1;
                break;            
            }
        }
        if(flag == 0) tmp_res++;
    }
    return tmp_res;
}

int dfs_chk[10];
void DFS(int idx, string tmp_str, int len)
{
    if(len == 9)
    {
        string_vec.push_back(tmp_str);
        return;
    }

    for(int i = 0; i < 9; i++)
    {
        if(dfs_chk[i] == 0)
        {
            chk_board[char_pos[i][0]][char_pos[i][1]] = 1;
            if(cal_score(char_pos[i][0], char_pos[i][1]) == score_string[len])
            {
                dfs_chk[i] = 1;
                DFS(i, tmp_str + seed_str[i], len + 1);
                dfs_chk[i] = 0;
            }
            chk_board[char_pos[i][0]][char_pos[i][1]] = 0;
        }
    }
}

void init()
{
    for(int i = 0; i < 10; i++) score_string[i] = -1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++) chk_board[i][j] = 0;
    }
    string_vec.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        init();

        cin >> seed_str;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cin >> origin_board[i][j];
                for(int k = 0; k < 9; k++)
                {
                    if(seed_str[k] == origin_board[i][j])
                    {
                        char_pos[k][0] = i;
                        char_pos[k][1] = j;
                        break;
                    }
                }
            }
        }

        // 점수 문자열 구하기
        for(int i = 0; i < 9; i++)
        {
            int find_flag = 0;
            for(int j = 0; j < 3; j++)
            {
                if(find_flag == 1) break;
                for(int k = 0; k < 3; k++)
                {
                    if(seed_str[i] == origin_board[j][k])
                    {
                        find_flag = 1;
                        chk_board[j][k] = 1;
                        score_string[i] = cal_score(j, k);
                        break;
                    }
                }
            }
        }

        // 시드 문자열 구하기
        for(int i = 0;  i < 3; i++)
        {
            for(int j = 0; j < 3; j++) chk_board[i][j] = 0;
        }

        // DFS
        string empty_str = "";
        for(int i = 0; i < 9; i++)
        {
            chk_board[char_pos[i][0]][char_pos[i][1]] = 1;
            if(cal_score(char_pos[i][0], char_pos[i][1]) == score_string[0])
            {
                dfs_chk[i] = 1;
                DFS(i, empty_str + seed_str[i], 1);
                dfs_chk[i] = 0;
            }
            chk_board[char_pos[i][0]][char_pos[i][1]] = 0;
        }


        // 정렬 및 첫번째 문자열 출력
        for(int i = 0; i < 9; i++) cout << score_string[i];
        
        sort(string_vec.begin(), string_vec.end());
        cout << ' ' << string_vec[0] << '\n';
    }

    return 0;
}