#include <iostream>
#include <bitset>
#include "BitBoard.h"

using namespace std;

BitBoard::BitBoard()
{
    this->initializedStandardGame();
}

void BitBoard::initializedStandardGame()
{
    char board[] = {
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
        '.', '.', '.', '.', '.', '.', '.', '.',
        '.', '.', '.', '.', '.', '.', '.', '.',
        '.', '.', '.', '.', '.', '.', '.', '.',
        '.', '.', '.', '.', '.', '.', '.', '.',
        'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};

    convertBoardToPieceBitBoard(board);
}

void BitBoard::convertBoardToPieceBitBoard(char board[])
{
    string bpStr = "0000000000000000000000000000000000000000000000000000000000000000";
    string brStr = "0000000000000000000000000000000000000000000000000000000000000000";
    string bnStr = "0000000000000000000000000000000000000000000000000000000000000000";
    string bbStr = "0000000000000000000000000000000000000000000000000000000000000000";
    string bqStr = "0000000000000000000000000000000000000000000000000000000000000000";
    string bkStr = "0000000000000000000000000000000000000000000000000000000000000000";
    string wpStr = "0000000000000000000000000000000000000000000000000000000000000000";
    string wrStr = "0000000000000000000000000000000000000000000000000000000000000000";
    string wnStr = "0000000000000000000000000000000000000000000000000000000000000000";
    string wbStr = "0000000000000000000000000000000000000000000000000000000000000000";
    string wqStr = "0000000000000000000000000000000000000000000000000000000000000000";
    string wkStr = "0000000000000000000000000000000000000000000000000000000000000000";

    for (int i = 0; i < 64; i++)
    {
        switch (board[i])
        {
        case 'p':
            bpStr[i] = '1';
            break;
        case 'r':
            brStr[i] = '1';
            break;
        case 'n':
            bnStr[i] = '1';
            break;
        case 'b':
            bbStr[i] = '1';
            break;
        case 'q':
            bqStr[i] = '1';
            break;
        case 'k':
            bkStr[i] = '1';
            break;
        case 'P':
            wpStr[i] = '1';
            break;
        case 'R':
            wrStr[i] = '1';
            break;
        case 'N':
            wnStr[i] = '1';
            break;
        case 'B':
            wbStr[i] = '1';
            break;
        case 'Q':
            wqStr[i] = '1';
            break;
        case 'K':
            wkStr[i] = '1';
            break;
        }
    }
    this->bp = bitset<64>(bpStr).to_ulong();
    this->br = bitset<64>(brStr).to_ulong();
    this->bn = bitset<64>(bnStr).to_ulong();
    this->bb = bitset<64>(bbStr).to_ulong();
    this->bq = bitset<64>(bqStr).to_ulong();
    this->bk = bitset<64>(bkStr).to_ulong();
    this->wp = bitset<64>(wpStr).to_ulong();
    this->wr = bitset<64>(wrStr).to_ulong();
    this->wn = bitset<64>(wnStr).to_ulong();
    this->wb = bitset<64>(wbStr).to_ulong();
    this->wq = bitset<64>(wqStr).to_ulong();
    this->wk = bitset<64>(wkStr).to_ulong();
}

void BitBoard::printBoard()
{
    char board[64];

    for(int i=0; i<64; i++)
    {
        board[i] = '.';
    }

    for (int i = 0; i < 12; i++)
    {
        char pieceChar = '.';
        string strBoard;
        switch (i)
        {
        case 0:
            strBoard  = bitset<64>(bp).to_string();
            pieceChar = 'p';
            break;
        case 1:
            strBoard  = bitset<64>(br).to_string();
            pieceChar = 'r';
            break;
        case 2:
            strBoard  = bitset<64>(bn).to_string();
            pieceChar = 'n';
            break;
        case 3:
            strBoard  = bitset<64>(bb).to_string();
            pieceChar = 'b';
            break;
        case 4:
            strBoard  = bitset<64>(bq).to_string();
            pieceChar = 'q';
            break;
        case 5:
            strBoard  = bitset<64>(bk).to_string();
            pieceChar = 'k';
            break;
        case 6:
            strBoard  = bitset<64>(wp).to_string();
            pieceChar = 'P';
            break;
        case 7:
            strBoard  = bitset<64>(wr).to_string();
            pieceChar = 'R';
            break;
        case 8:
            strBoard  = bitset<64>(wn).to_string();
            pieceChar = 'N';
            break;
        case 9:
            strBoard  = bitset<64>(wb).to_string();
            pieceChar = 'B';
            break;
        case 10:
            strBoard  = bitset<64>(wq).to_string();
            pieceChar = 'Q';
            break;
        case 11:
            strBoard  = bitset<64>(wk).to_string();
            pieceChar = 'K';
            break;
        }

        for(int j=0; j<64; j++)
        {
            if(strBoard[j] == '1')
            {
                board[j] = pieceChar;
            }
        }
    }

    for(int i=0; i<64; i++)
    {
        cout << board[i] << " ";
        if((i == 7) || (i == 15) || (i == 23) || (i == 31) || (i == 39) || (i == 47) || (i == 55))
        {
            cout << "\n";
        }
    }
    cout << "\n";
}

unsigned long long BitBoard::generatePawnMoves(bool isWhite)
{
    unsigned long long possibleMoves = isWhite ? this->wp : this->bp;

    possibleMoves = isWhite ? possibleMoves << 8 : possibleMoves >> 8;

    return possibleMoves;
}



