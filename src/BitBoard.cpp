#include <iostream>
#include <bitset>
#include "BitBoard.h"

using namespace std;

class BitBoard
{
public:
    unsigned long long bp, br, bn, bb, bq, bk, wp, wr, wn, wb, wq, wk;

    void initializedStandardGame()
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
    }

    void convertBoardToPieceBitBoard(char board[], unsigned long long &bp,
                                     unsigned long long &br,
                                     unsigned long long &bn,
                                     unsigned long long &bb,
                                     unsigned long long &bq,
                                     unsigned long long &bk,
                                     unsigned long long &wp,
                                     unsigned long long &wr,
                                     unsigned long long &wn,
                                     unsigned long long &wb,
                                     unsigned long long &wq,
                                     unsigned long long &wk)
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
        bp = bitset<64>(bpStr).to_ulong();
        br = bitset<64>(brStr).to_ulong();
        bn = bitset<64>(bnStr).to_ulong();
        bb = bitset<64>(bbStr).to_ulong();
        bq = bitset<64>(bqStr).to_ulong();
        bk = bitset<64>(bkStr).to_ulong();
        wp = bitset<64>(wpStr).to_ulong();
        wr = bitset<64>(wrStr).to_ulong();
        wn = bitset<64>(wnStr).to_ulong();
        wb = bitset<64>(wbStr).to_ulong();
        wq = bitset<64>(wqStr).to_ulong();
        wk = bitset<64>(wkStr).to_ulong();
    }
};