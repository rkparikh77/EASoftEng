#ifndef DYNAMIC_RIVALRIES_H
#define DYNAMIC_RIVALRIES_H

#include <string>
#include <vector>
#include <unordered_map>

//
// Forward declarations
//
class Team;
class Coach;
class Player;
class Game;
class Season;

//
// =========================
// Rivalry
// =========================
// Tracks rivalry state between two teams
//
class Rivalry {
public:
    Rivalry(Team* teamA, Team* teamB);

    void recordGameResult(const Game& game);
    void updateIntensity();
    int getIntensity() const;
    Team* getTeamA() const;
    Team* getTeamB() const;

private:
    Team* m_teamA;
    Team* m_teamB;
    int m_gamesPlayed;
    int m_teamAWins;
    int m_teamBWins;
    int m_intensity;
};


//
// =========================
// LegacyProfile
// =========================
// Stores historical legacy data for a team or coach
//
class LegacyProfile {
public:
    LegacyProfile();

    void recordWin();
    void recordLoss();
    void addChampionship();
    int getWins() const;
    int getLosses() const;
    int getChampionships() const;

private:
    int m_wins;
    int m_losses;
    int m_championships;
};


//
// =========================
// Team
// =========================
// Represents a college football team
//
class Team {
public:
    Team(const std::string& name);

    void addPlayer(Player* player);
    void setCoach(Coach* coach);
    void recordWin();
    void recordLoss();

    std::string getName() const;
    Coach* getCoach() const;
    LegacyProfile& getLegacyProfile();

private:
    std::string m_name;
    Coach* m_coach;
    std::vector<Player*> m_players;
    LegacyProfile m_legacy;
};


//
// =========================
// Coach
// =========================
// Represents a head coach
//
class Coach {
public:
    Coach(const std::string& name);

    void assignTeam(Team* team);
    void recordWin();
    void recordLoss();

    std::string getName() const;
    LegacyProfile& getLegacyProfile();
    Team* getTeam() const;

private:
    std::string m_name;
    Team* m_team;
    LegacyProfile m_legacy;
};


//
// =========================
// Player
// =========================
// Represents an individual player
//
class Player {
public:
    Player(const std::string& name, int rating);

    std::string getName() const;
    int getRating() const;
    void setRating(int rating);

private:
    std::string m_name;
    int m_rating;
};


//
// =========================
// Game
// =========================
// Represents a played game between two teams
//
class Game {
public:
    Game(Team* home, Team* away);

    void setScore(int homeScore, int awayScore);
    Team* getWinner() const;
    Team* getLoser() const;
    Team* getHomeTeam() const;
    Team* getAwayTeam() const;

private:
    Team* m_home;
    Team* m_away;
    int m_homeScore;
    int m_awayScore;
};


//
// =========================
// Season
// =========================
// Manages a full season of games and rivalries
//
class Season {
public:
    Season(int year);

    void addGame(const Game& game);
    void updateRivalries();
    Rivalry* getRivalry(Team* a, Team* b);

    int getYear() const;

private:
    int m_year;
    std::vector<Game> m_games;
    std::vector<Rivalry> m_rivalries;
};

#endif
