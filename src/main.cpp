#include "StarShip.hpp"
#include "AsteroidHorde.hpp"
#include <unistd.h>

static int gameLoop(StarShip &player, int asteroinds)
{
    int row;
    int col;
    int ch;
    int lastMax = 25;
    char prinCollision = 0;

    player.resetStarShip();
    getmaxyx(stdscr, row, col);
    SpaceObject starts[asteroinds];
    for (int i = 0; i < asteroinds; i++)
    {
        starts[i] = SpaceObject((float)(rand() * time(NULL) % col), (float)(rand() * time(NULL) % row + 4), (i % 5 == 0 ? 0.05f : 0.02f), (i % 5 == 0 ? "*" : "."));
    }
    AsteroidHorde meteors = AsteroidHorde(asteroinds);
    meteors.setRandomPositionToAll(0, col, 5, row);
    long satrt = time(NULL);
    while ((ch = getch()) != 27 && player.getInGame())
    {
        erase();
        for (int k = 0; k < col; k++)
        {
            mvaddch(3, k, '_');
        }
        attron(COLOR_PAIR(4));
        mvprintw(2, 5, ("Live: " + std::to_string(player.getLive())).c_str());
        attron(COLOR_PAIR(5));
        mvprintw(2, 15, ("Killed Asteroids: " + std::to_string(player.getKillAsteroids())).c_str());
        attron(COLOR_PAIR(3));
        for (int i = 0; i < asteroinds; i++)
        {
            starts[i].printObject();
            if (starts[i].getPosX() <= 0)
                starts[i].setPosX(col + (rand() * time(NULL) % col));
            else
                starts[i].moveLeft();
            usleep(50);
        }
        attron(COLOR_PAIR(2));
        meteors.drawAllMeteors(col);
        attron(COLOR_PAIR(1));
        player.bulletChangeState(col, meteors);
        if (prinCollision)
        {
            player.printCollisionEfferc();
            prinCollision--;
        }
        else
            player.printObject();
        switch (ch)
        {
        case KEY_DOWN:
            if (player.getPosY() < row)
                player.moveDown();
            break;
        case KEY_UP:
            if (player.getPosY() > 6)
                player.moveUp();
            break;
        case KEY_LEFT:
            if (player.getPosX() > 0)
                player.moveLeft();
            break;
        case KEY_RIGHT:
            if (player.getPosX() < col)
                player.moveRight();
            break;
        case ' ':
            player.shoot();
            break;
        default:
            break;
        }
        if (player.checkCollision(meteors))
            prinCollision = 30;
        if (player.getKillAsteroids() > lastMax)
        {
            meteors.setSpeedToAll(meteors.getMeteors()[0].getSpeed() * 1.3);
            lastMax += lastMax;
        }
        refresh();
        usleep(3000);
    }
    if (player.getInGame() == false || player.getLive() == 0)
    {
        erase();
        attron(COLOR_PAIR(6));
        mvprintw(row / 2, (col / 2) - 10, "--  YOU LOSE  --");

        refresh();
        usleep(6000000);
    }
    erase();
    endwin();
    player.setScore(player.getKillAsteroids() + (time(NULL) - satrt));
    return (0);
}

static void initAll()
{
    initscr();
    nonl();
    cbreak();
    echo();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, true);
    attron(A_BOLD);
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_CYAN);
}

static int print_mn(int bestScore, int lastScore)
{
    int max_x;
    int max_y;
    getmaxyx(stdscr, max_y, max_x);
    WINDOW *win = newwin(max_y / 2, max_x / 2, max_y / 2 - ((max_y / 2) / 2), max_x / 2 - ((max_x / 2) / 2));
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    keypad(win, true);
    erase();
    std::string choise[5] = {"LEVEL  1", "LEVEL  2", "LEVEL  3", "LEVEL  4", "  EXIT  "};

    int ind_choise = 22;
    int highlight = 0;

    while (ind_choise != '\r')
    {
        wclear(win);
        box(win, 0, 0);
        mvwprintw(win, 0, (max_x / 2) / 2 - 10, "><< FT_RETRO >><");
        mvwprintw(win, 2, (max_x / 2) / 2 - 10, ("Best Score: " + std::to_string(bestScore)).c_str());
        mvwprintw(win, 3, (max_x / 2) / 2 - 10, ("Last Score: " + std::to_string(lastScore)).c_str());
        for (int i = 0; i < 5; i++)
        {
            if (i == highlight)
                wattron(win, A_REVERSE);
            mvwprintw(win, i + ((max_y / 2) / 2) - 3, ((max_x / 2) / 2) - 6, choise[i].c_str());
            wattroff(win, A_REVERSE);
        }
        ind_choise = wgetch(win);
        switch (ind_choise)
        {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == 5)
                highlight = 4;
            break;
        default:
            break;
        }
    }
    endwin();
    return highlight;
}

int main(void)
{
    int choose = 22;
    int maxScore = 0;
    initAll();
    StarShip st = StarShip();
    while (choose != 4)
    {
        choose = print_mn(maxScore, st.getScore());
        if (choose == 0)
            gameLoop(st, 30);
        else if (choose == 1)
            gameLoop(st, 50);
        else if (choose == 2)
            gameLoop(st, 60);
        else if (choose == 3)
            gameLoop(st, 80);
        if (st.getScore() > maxScore)
            maxScore = st.getScore();
    }
    return (0);
}
