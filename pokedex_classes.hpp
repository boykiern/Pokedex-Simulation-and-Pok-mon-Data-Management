#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <array>

using namespace std;

#ifndef POKEDEX_CLASSES_HPP
#define POKEDEX_CLASSES_HPP

// Class representing a Pokémon with a name and experience points.
class Pokemon {
private:
    string name;
    int experience;

public:
    Pokemon(const string& initialName, int initialXP) : name(initialName), experience(initialXP) {}

    string getName() const { return name; }
    int getExperience() const { return experience; }

    // Overload == operator to compare Pokémon by name.
    bool operator==(const Pokemon& other) const {
        return name == other.name;
    }
};

// Hash function for Pokémon to use them as keys in unordered_map.
struct PokemonHash {
    size_t operator()(const Pokemon& p) const {
        return hash<string>()(p.getName());
    }
};

// Class storing detailed information about a Pokémon.
class PokemonInfo {
private:
    string type;
    string description;
    vector<pair<string,int>> availableAttacksPerLevel;
    array<int, 3> experienceThresholds;

public:
    PokemonInfo(const string& type, const string& description, 
                const vector<pair<string,int>>& attacks, const array<int, 3>& thresholds) 
        : type(type), description(description), availableAttacksPerLevel(attacks), experienceThresholds(thresholds) {}

    string getType() const { return type; }
    string getDescription() const { return description; }
    vector<pair<string,int>> getAttacks() const { return availableAttacksPerLevel; }
    array<int, 3> getThresholds() const { return experienceThresholds; }
};

// Pokedex class managing all Pokémon and their information.
class Pokedex {
private:
    unordered_map<Pokemon, PokemonInfo, PokemonHash> data;

public:
    void add(const Pokemon& p, const PokemonInfo& info) {
        data.emplace(p, info);
    }

    // Display all Pokémon in the Pokedex.
    void showAll() const {
        for (auto& pair : data) {
            const auto& p = pair.first;
            const auto& info = pair.second;

            cout << "----------------------------------------------------------\n";
            cout << "Name: " << p.getName() << "\nXP: " << p.getExperience() << "\n";
            cout << "Type: " << info.getType() << "\n";
            cout << "Description: " << info.getDescription() << "\n";
            cout << "Attacks:\n";
            for (auto& attack : info.getAttacks())
                cout << "- " << attack.first << " Damage: " << attack.second << "\n";
            cout << "Level thresholds:\n";
            for (int xpRequired : info.getThresholds())
                cout << "- " << xpRequired << " XP\n";
        }
    }

    // Display a specific Pokémon by name.
    void show(const Pokemon& search) const {
        auto it = data.find(search);
        if (it != data.end()) {
            const auto& p = it->first;
            const auto& info = it->second;

            cout << "Name: " << p.getName() << "\nXP: " << p.getExperience() << "\n";
            cout << "Type: " << info.getType() << "\n";
            cout << "Description: " << info.getDescription() << "\n";
            cout << "Attacks:\n";
            for (const auto& attack : info.getAttacks())
                cout << "- " << attack.first << " Damage: " << attack.second << "\n";
            cout << "Level thresholds:\n";
            for (int xpRequired : info.getThresholds())
                cout << "- " << xpRequired << " XP\n";
        } else {
            cout << "Pokémon not found\n";
        }
    }
};

#endif
