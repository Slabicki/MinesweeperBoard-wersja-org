
#ifndef MINESWEEPERBOARD_MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_MINESWEEPERBOARD_H


enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};


class MinesweeperBoard
{

    Field board[100][100];
    int width;
    int height;
    bool First_Move;
    //bool IsBig(int row,int col)const;
    GameMode mode;

public:
    MinesweeperBoard(int width, int height, GameMode mode );
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    bool isRevealed(int row, int col) const;
    GameState getGameState() const;
    //GameMode getGameMode() const;
    char getFieldInfo(int row, int col) const;
    bool IsBig(int row,int col)const;
    bool hasMine(int row, int col)const;
    void removeFlag(int row, int col);
    void Create_NewMine();

};




#endif //MINESWEEPERBOARD_MINESWEEPERBOARD_H
