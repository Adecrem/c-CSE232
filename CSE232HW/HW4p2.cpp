#include<iostream>
using std::cin; using std::cout;
int main() {
    int n1, n2, n4, n5;
    cin >> n1 >> n4;
    if (n1 > n4) {
        n5 = n4 + 1;
        n5 = n5 + n1;
        n1 = n5 - n1;
        n5 = n5 - n1;
        n2 = n5;

        int tot_lines = n2 - n1, line = 0, n3;
        while (tot_lines != -1) {
            int count = n2, i;
            if (line % 2 == 0) {
                for (i = 0; i <= tot_lines; i++)
                    cout << count-- << ' ';
                n3 = n2;
                n2 = n1;
                n1 = n3 - 1;
            } else {
                for (i = 0; i <= tot_lines; i++)
                    cout << count++ << ' ';
                n3 = n2;
                n2 = n1;
                n1 = n3 + 1;
            }
            line++;
            cout << "\n";
            tot_lines--;
        }
    } else {
        n2 = n4 - 1;
        int tot_lines = n2 - n1, line = 0, n3;
        while (tot_lines != -1) {
            int count = n1, i;
            if (line % 2 == 0) {
                for (i = 0; i <= tot_lines; i++)
                    cout << count++ << ' ';
                n3 = n1;
                n1 = n2;
                n2 = n3 + 1;
            } else {
                for (i = 0; i <= tot_lines; i++)
                    cout << count-- << ' ';
                n3 = n1;
                n1 = n2;
                n2 = n3 - 1;
            }
            line++;
            cout << "\n";
            tot_lines--;
        }
    }
}
