#include <iostream>
using std::cin; using std::cout; using std::endl;
int main()
{
    int upperb;
    int lowerb = 1;
    char option;

    cout << "What is the upper bound for the game? (the lower bound is 1) \n";
    cin >> upperb;
    int avg = ((lowerb + upperb) / 2);
    cout << "Pick a positive integer between 1 and " << upperb <<'.'<< endl;
    while (upperb != lowerb && option != '=')
    {
        cout << "Is that number greater then (>), less than (<), or equal to (=) "
        << avg << "? " << endl;
        cin >> option;
        switch (option)
        {
            case '>':
            {
                lowerb = avg +1;
                cout << "Since you chose >, your number is between " << lowerb << " and "
                << upperb<< '.'<< endl;
                avg = ((lowerb + upperb) / 2);
            } break;
            case '<':
            {
                upperb = avg -1;
                cout << "Since you chose <, your number is between " << lowerb<< " and "
                << upperb << '.'<< endl;
                avg = (lowerb + upperb) / 2;
            } break;
            case '=':
            {
                break;
            }
        }
    }
    cout << "Your number is "<<(avg)<<"!\n";
}
