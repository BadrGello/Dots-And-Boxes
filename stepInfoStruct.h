typedef struct
{

    int playerTurn;
    int p1Score;
    int p2Score;
    int player1Moves;
    int player2Moves;
    int remMoves;
    int r1,c1,r2,c2;
    int moveChecker;
    int winChecker1;
    int winChecker2;
    int dfsActive;
    //char Grid[20][20];

} stepInfoStruct;
