#ifndef _SOMETHING
#define _SOMETHING

#include "screen.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Player
{
public:
    int money;
    string name;
    Player(string n, int m = 100) : money(m), name(n) {};
};

class Game
{
private:
    vector<Player> players;
    int num_players;
    int pool = 0;
    int win_count = 1;
    const int rule_padding = 40;
    const int padding = 20;
    void turn(Screen& s);
    void print_players(Screen& s, int print_start);
    void print_rules(Screen& s, int print_start);
    void print_title(Screen& s);
    void print_winner(Screen& s);
    void get_bets(Screen& s);
    void rotate_players();
public:
    vector<Player> get_players() const { return this->players; }
    void init(Screen& s);
    void start(Screen& s);
};

#endif

