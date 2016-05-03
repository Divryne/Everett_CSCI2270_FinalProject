#ifndef GALLOW_H
#define GALLOW_H

#include <string>

enum class Difficulty {
    EASY,
    MEDIUM,
    HARD
};

enum class Subject {
    ANIMALS,
    LOCATIONS,
    TELEVISION,
    BOOKS,
    MOVIES
};

struct GuessedChar
{
    char c;
    GuessedChar* next;

    GuessedChar(char c) : c(c), next(nullptr) {}
};

class Gallows
{
private:
    int lives;
    int wins;
    int losses;
    Subject subject;
    std::string word;
    std::string progress;
    GuessedChar* guessedHead;

    static const std::string animalsWordBank[];
    static const std::string locationsWordBank[];
    static const std::string televisionWordBank[];
    static const std::string booksWordBank[];
    static const std::string moviesWordBank[];

public:
    Gallows(Difficulty difficulty, Subject subject, int prevWins, int prevLosses);
    ~Gallows();

    void guessCharacter(char c);
    void displayProgress();
    void displayInfo();
    void displayVictory();
    void displayScore();
    void addWin();
    void addLoss();
    int getWins();
    int getLosses();
    bool hasWon();
    bool hasDied();

    std::string getSubject();
    std::string getWord();
    int getCharacters();
    int getLives();
};

#endif
