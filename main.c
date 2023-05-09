#include <stdio.h>
#include "tournament.h"

int main() {
    Team teams[MAX_TEAMS];
    Match matches[MAX_MATCHES_PER_TEAM * MAX_TEAMS / 2];
    int num_teams, num_matches;

    printf("%s", MSG_WELCOME);
    
    // ler as equipas do utilizador
    printf("%s", MSG_ENTER_TEAMS);
    num_teams = read_teams(teams);
    printf("\n");

    // ler os jogadores de cada equipa do utilizador
    for (int i = 0; i < num_teams; i++) {
        printf(MSG_ENTER_PLAYERS, teams[i].name);
        fflush(stdout); // limpar o buffer de saída antes de ler a entrada do utilizador
        for (int j = 0; j < teams[i].num_players; j++) {
            scanf("%s", teams[i].players[j]);
        }
    }
    printf("\n");

    // ler os resultados dos jogos do utilizador
    num_matches = read_matches(teams, matches, num_teams);
    printf("\n");

    // atualizar as equipas com base nos resultados dos jogos
    update_teams(teams, matches, num_matches);

    // imprimir o quadro de pontuações
    printf("%s", MSG_SCOREBOARD);
    print_scoreboard(teams, num_teams);

    // determinar o vencedor
    int winner_index = 0;
    for (int i = 1; i < num_teams; i++) {
        if (teams[i].points > teams[winner_index].points) {
            winner_index = i;
        } else if (teams[i].points == teams[winner_index].points) {
            if (teams[i].goals_for - teams[i].goals_against > teams[winner_index].goals_for - teams[winner_index].goals_against) {
                winner_index = i;
            }
        }
    }
    printf("%s%s\n", MSG_WINNER, teams[winner_index].name);
    printf("%s", MSG_THANKS);

    return 0;
}
