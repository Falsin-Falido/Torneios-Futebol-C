#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEAMS 10
#define MAX_TEAM_NAME_LENGTH 20
#define MAX_PLAYERS 20
#define MAX_PLAYER_NAME_LENGTH 30
#define MAX_MATCHES_PER_TEAM (MAX_TEAMS - 1)
#define MAX_ROUNDS (MAX_TEAMS - 1)

typedef struct {
    char name[MAX_TEAM_NAME_LENGTH+1];
    int num_players;
    char players[MAX_PLAYERS][MAX_PLAYER_NAME_LENGTH+1];
    int num_wins;
    int num_draws;
    int num_losses;
    int points;
    int goals_for;
    int goals_against;
} Team;

typedef struct {
    char home_team[MAX_TEAM_NAME_LENGTH+1];
    char away_team[MAX_TEAM_NAME_LENGTH+1];
    int home_score;
    int away_score;
} Match;

int read_teams(Team *teams);
void print_team(Team team);
void print_teams(Team *teams, int num_teams);
int read_matches(Team *teams, Match *matches, int num_teams);
void update_teams(Team *teams, Match *matches, int num_matches);
void print_matches(Match *matches, int num_matches);
void print_scoreboard(Team *teams, int num_teams);

// strings em Português de Portugal
const char *MSG_WELCOME = "Bem-vindo ao torneio!\n";
const char *MSG_ENTER_TEAMS = "Por favor, introduza os nomes das equipas:\n";
const char *MSG_ENTER_PLAYERS = "Por favor, introduza o nome dos jogadores da equipa %s:\n";
const char *MSG_ENTER_MATCHES = "Por favor, introduza os resultados dos jogos:\n";
const char *MSG_SCOREBOARD = "Quadro de Pontuações\n";
const char *MSG_WINNER = "O vencedor do torneio é: ";
const char *MSG_THANKS = "Obrigado por jogar!\n";

#endif /* TOURNAMENT_H */
