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
    char board[64] = {'.'};

    for (int i = 0; i < 12; i++)
    {
        unsigned long long piece;
        char pieceChar = '.';
        switch (i)
        {
        case 0:
            piece = bp;
            pieceChar = 'p';
            break;
        case 1:
            piece = br;
            pieceChar = 'r';
            break;
        case 2:
            piece = bn;
            pieceChar = 'n';
            break;
        case 3:
            piece = bb;
            pieceChar = 'b';
            break;
        case 4:
            piece = bq;
            pieceChar = 'q';
            break;
        case 5:
            piece = bk;
            pieceChar = 'k';
            break;
        case 6:
            piece = wp;
            pieceChar = 'P';
            break;
        case 7:
            piece = wr;
            pieceChar = 'R';
            break;
        case 8:
            piece = wn;
            pieceChar = 'N';
            break;
        case 9:
            piece = wb;
            pieceChar = 'B';
            break;
        case 10:
            piece = wq;
            pieceChar = 'Q';
            break;
        case 11:
            piece = wk;
            pieceChar = 'K';
            break;
        }

        string strBoard = bitset<64>(piece).to_string();

        for(int j=0; j<64; j++)
        {
            if(strBoard[j] == '1')
            {
                board[j] = pieceChar;
            }
            else
            {
                board[j] = '.';
            }
        }
    }

    for(int i=0; i<64; i++)
    {
        cout << board[i];
        if(i%7 == 0)
        {
            cout << "\n";
        }
    }
}
