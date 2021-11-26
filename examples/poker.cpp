#include <iostream>
#include "poker.h"

using std::cout, std::cin, std::endl;

void Game::init(Screen& s)
{
    this->print_title(s);
    int startX = s.getWidth()/2-16;
    s.setPos(startX, s.getY()+5);
    s.print("Enter number of players: ");
    s.setPos(s.getX()+25, s.getY());
    int num;
    cin >> num;
    this->num_players = num;

    s.setPos(startX, s.getY()+1);
    for (int i = 0; i < num; ++i)
    {
        s.setPos(startX, s.getY());
        string enter_player = "Enter player "+std::to_string(i+1)+" name: ";
        s.print(enter_player);
        s.setPos(s.getX()+enter_player.length(), s.getY());
        string name;
        cin >> name;
        Player player(name);
        this->players.push_back(player);
    }
}

void Game::print_rules(Screen& s, int print_start)
{
    s.setPos(s.getWidth()-this->rule_padding, print_start);
    s.print("Royal Flush");
    s.setPos(s.getWidth()-this->rule_padding, ++print_start);
    s.print("Straight Flush");
    s.setPos(s.getWidth()-this->rule_padding, ++print_start);
    s.print("4 of a Kind");
    s.setPos(s.getWidth()-this->rule_padding, ++print_start);
    s.print("Full House");
    s.setPos(s.getWidth()-this->rule_padding, ++print_start);
    s.print("Flush");
    s.setPos(s.getWidth()-this->rule_padding, ++print_start);
    s.print("Straight");
    s.setPos(s.getWidth()-this->rule_padding, ++print_start);
    s.print("3 of a Kind");
    s.setPos(s.getWidth()-this->rule_padding, ++print_start);
    s.print("2 Pair");
    s.setPos(s.getWidth()-this->rule_padding, ++print_start);
    s.print("1 Pair");
    s.setPos(s.getWidth()-this->rule_padding, ++print_start);
    s.print("High Card");
    s.setPos(s.getWidth()-this->rule_padding, ++print_start);
}

void Game::print_players(Screen& s, int print_start)
{
    s.setPos(20, print_start);
    for (Player p : this->players)
    {
        s.print(p.name+": "+std::to_string(p.money));
        s.setPos(20, s.getY()+1);
    }
    s.setPos(20, s.getY()+5);
    s.setMode(MODES::BOLD);
    s.print("Pool: "+std::to_string(this->pool));
    s.setMode(MODES::RESET);
}

void Game::print_title(Screen& s)
{
    s.setPos(s.getWidth()/2 - 5, s.getY()+1);
    s.setMode(MODES::BOLD);
    s.setMode(MODES::ITALIC);
    s.print("Poker");
    s.setMode(MODES::RESET);
}

void Game::print_winner(Screen& s)
{
        s.setPos(20, s.getHeight()-this->players.size()-10);
        s.clearDown();
        this->win_count = 1;
        s.print("Winner: ");
        s.setPos(28, s.getHeight()-this->players.size()-10);
        int winner;
        cin >> winner;
        --winner;
        this->players.at(winner).money += this->pool;
        this->pool = 0;
}

void Game::rotate_players()
{
    Player temp = this->players.at(0);
    this->players.erase(this->players.begin());
    this->players.push_back(temp);
}

void Game::get_bets(Screen& s)
{
    s.setPos(20, s.getHeight()-this->players.size()-10);
    s.setMode(MODES::BOLD);
    s.print("Enter Bet Amount");
    s.setMode(MODES::RESET);
    s.setPos(20, s.getY()+1);

    for (Player& p : this->players)
    {
        s.setPos(20, s.getY());
        s.print(p.name+": ");
        s.setPos(s.getX()+p.name.length()+2, s.getY());
        int amount;
        cin >> amount;
        p.money -= amount;
        this->pool += amount;
    }
}

void Game::turn(Screen& s)
{
    s.home();
    s.clear();
    s.hideCursor();
    this->print_title(s);

    int print_start = s.getY()+10;

    this->print_players(s, print_start);
    this->print_rules(s, print_start);

    s.showCursor();
    this->get_bets(s);

    if (this->win_count == 5)
    {
        this->print_winner(s);
    }

    this->rotate_players();
}

void Game::start(Screen& s)
{
    while (true)
    {
        this->turn(s);
        ++this->win_count;
    }
}

