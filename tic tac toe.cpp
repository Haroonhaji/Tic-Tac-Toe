

// TIC TAC TOE

#include <bits/stdc++.h>

using namespace std;

int x = 1;

void show(char A[3][3]) {
    cout << "\nCurrent Board:\n";
    cout << "  0 1 2\n";  // Column index
    for (int i = 0; i < 3; i++) {
        cout << i << " ";  // Row index
        for (int j = 0; j < 3; j++) {
            if (A[i][j] == ' ') 
                cout << "- ";
            else 
                cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int check(char A[3][3]) {
    int y = 0, z = 0, a = 0, b = 0, c = 0, d = 0, e = 0;
    char player;
    
    if (x % 2 == 1) 
        player = 'X';
    else 
        player = 'O';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[i][j] == player) {
                if (i + j == 2) e++;
                if (i == 0) y++;
                if (i == 1) z++;
                if (i == 2) a++;
                if (j == 0) b++;
                if (j == 1) c++;
                if (j == 2) d++;
            }
        }
    }

    if (e == 3 || y == 3 || z == 3 || a == 3 || b == 3 || c == 3 || d == 3) {
        cout << "Player " << player << " is the winner!" << endl;
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[i][j] == ' ') { 
                x++; 
                return 1;
            }
        }
    }

    cout << "It's a tie!" << endl;
    return 0;
}

void input(char A[3][3]) {
    int i, j;
    char player;
    
    if (x % 2 == 1) 
        player = 'X';
    else 
        player = 'O';

    cout << "Player " << player << " should select a position (row and column): " << endl;
    cin >> i >> j;

    if (i < 0 || i >= 3 || j < 0 || j >= 3 || A[i][j] != ' ') {
        cout << "Invalid move! Please select again." << endl;
        input(A);
        return;
    }

    A[i][j] = player;
    show(A);

    if (check(A)) {
        input(A);
    }
}

int main() {
    char A[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    show(A);
    input(A);
}

