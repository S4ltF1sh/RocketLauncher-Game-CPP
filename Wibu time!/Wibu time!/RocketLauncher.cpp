#include "Sources/Application.h"
#include "Sources/GameStateManager/GSPlay.h"
#include <iostream>

std::map<std::string, std::vector<std::vector<int>>> GSPlay::m_mapStorage;
int GSPlay::numMap = 0;
int GSPlay::curMap = 1;
int GSPlay::numDeath = 0;
sf::Text GSPlay::m_numDeath;

int main()
{
    Application app;
    
    app.Run();

    //free(&app);

    return 0;
}