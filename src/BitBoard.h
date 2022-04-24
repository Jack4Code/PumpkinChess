

class BitBoard
{
public:
    unsigned long long bp, br, bn, bb, bq, bk, wp, wr, wn, wb, wq, wk;

    void initializedStandardGame();
    
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
                                 unsigned long long &wk);
};