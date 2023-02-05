#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {

    int i, j;

    //1단계 소문자 변환
    for (i = 0; i < new_id.length(); i++) {
        new_id[i] = tolower(new_id[i]);
    }

    //2단계 문자 제거
    for (i = 0; i < new_id.length(); ) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
            || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            i++;
            continue;
        }

        new_id.erase(new_id.begin() + i);
    }

    //3단계 2번이상 연속된 .을 하나의 마침표로
    for (i = 1; i < new_id.length();) {
        if (new_id[i] == '.' && new_id[i - 1] == '.') {
            new_id.erase(new_id.begin() + i);
        }
        else {
            i++;
            continue;
        }
    }

    //4단계  마침표가 처음이나 끝에 위치한다면 제거

    if (new_id.front() == '.')
        new_id.erase(new_id.begin());
    if (new_id.back() == '.')
        new_id.erase(new_id.end() - 1);


    //5단계  빈 문자열이면, new_id에 'a'를 대입한다.

    if (new_id.empty() == true)
        new_id = 'a';


    //6단계    길이가 16자 이상이면, new_id에 15개의 문자를 제외한 나머지 문자들을 모두 제거한다.

    if (new_id.length() >= 16)
        new_id.assign(new_id, 0, 15);
    if (new_id.back() == '.')
        new_id.erase(new_id.end() - 1);

    // 7단계  2보다 작으면 '삽입'해서 길이가 3이될때까지 붙임
    char last;
    last = new_id[new_id.length() - 1];
    while (new_id.length() <= 2) {
        new_id.append(1, last);
    }

    string answer = new_id;
    return answer;
}