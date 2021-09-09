#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {

    int i, j;

    //1�ܰ� �ҹ��� ��ȯ
    for (i = 0; i < new_id.length(); i++) {
        new_id[i] = tolower(new_id[i]);
    }

    //2�ܰ� ���� ����
    for (i = 0; i < new_id.length(); ) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
            || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            i++;
            continue;
        }

        new_id.erase(new_id.begin() + i);
    }

    //3�ܰ� 2���̻� ���ӵ� .�� �ϳ��� ��ħǥ��
    for (i = 1; i < new_id.length();) {
        if (new_id[i] == '.' && new_id[i - 1] == '.') {
            new_id.erase(new_id.begin() + i);
        }
        else {
            i++;
            continue;
        }
    }

    //4�ܰ�  ��ħǥ�� ó���̳� ���� ��ġ�Ѵٸ� ����

    if (new_id.front() == '.')
        new_id.erase(new_id.begin());
    if (new_id.back() == '.')
        new_id.erase(new_id.end() - 1);


    //5�ܰ�  �� ���ڿ��̸�, new_id�� 'a'�� �����Ѵ�.

    if (new_id.empty() == true)
        new_id = 'a';


    //6�ܰ�    ���̰� 16�� �̻��̸�, new_id�� 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����Ѵ�.

    if (new_id.length() >= 16)
        new_id.assign(new_id, 0, 15);
    if (new_id.back() == '.')
        new_id.erase(new_id.end() - 1);

    // 7�ܰ�  2���� ������ '����'�ؼ� ���̰� 3�̵ɶ����� ����
    char last;
    last = new_id[new_id.length() - 1];
    while (new_id.length() <= 2) {
        new_id.append(1, last);
    }

    string answer = new_id;
    return answer;
}