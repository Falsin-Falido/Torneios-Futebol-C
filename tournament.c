#include "tournament.h"

int read_teams(Team *teams) {
    printf("%s", MSG_ENTER_TEAMS);
    for (int i = 0; i < MAX_TEAMS; i++) {
        Team team;
        printf("Nome da equipa %d: ", i+1);
        fgets(team.name, MAX_TEAM_NAME_LENGTH+1, stdin);
        team.name[strcspn(team.name, "\n")] = '\0'; // remove o caracter \n
        if (strcmp(team.name, "") == 0) {
            return i;
        }
        printf(MSG_ENTER_PLAYERS, team.name);
        for (int j = 0; j < MAX_PLAYERS; j++) {
            printf("Jogador %d: ", j+1);
            fgets(team.players[j], MAX_PLAYER_NAME_LENGTH+1, stdin);
            team.players[j][strcspn(team.players[j], "\n")] = '\0'; // remove o caracter \n
            if (strcmp(team.players[j], "") == 0) {
                team.num_players = j;
                break;
            }
        }
        teams[i] = team;
    }
    return MAX_TEAMS;
}
