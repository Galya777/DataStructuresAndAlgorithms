#include <iostream>

int main() {
    std::string necklace;
    std::cin >> necklace;

    int left_white = 0, left_black = 0, left_yellow = 0;
    int right_white = 0, right_black = 0, right_yellow = 0;

    // �������� ���� ���������� � ����� ��������� �� ����� ������
    for (char bead : necklace) {
        if (bead == 'W') {
            left_white++;
        }
        else if (bead == 'B') {
            left_black++;
        }
        else if (bead == 'Y') {
            left_yellow++;
        }
    }

    // �������� ����������� �� ������ ������ � ������� ������
    right_white = left_white;
    right_black = left_black;
    right_yellow = left_yellow;

    // ��������� ����� �������
    int max_beads = left_yellow + right_yellow;

    // ���������� ��������, ����� �� ���� �������������� ������
    if (left_white + left_black < right_white + right_black) {
        max_beads += left_white + left_black;
    }
    else {
        max_beads += right_white + right_black;
    }

    std::cout << "���������� ���� �������: " << max_beads << std::endl;

    return 0;
}
