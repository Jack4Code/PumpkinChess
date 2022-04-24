

class BitBoard
{
public:
    unsigned long long bp, br, bn, bb, bq, bk, wp, wr, wn, wb, wq, wk;

    BitBoard();

    void initializedStandardGame();
    void convertBoardToPieceBitBoard(char board[]);
    void printBoard();

};