#include "pokedex_classes.hpp"

int main() {
    Pokedex myPokedex;

    // Create and add Squirtle.
    Pokemon squirtle("Squirtle", 100);
    PokemonInfo infoSquirtle("Water", "A small turtle that shoots water streams.", 
        {{"Water Gun", 4}, {"Hydro Pump", 6}, {"Rain Dance", 5}}, {0, 400, 1000});
    myPokedex.add(squirtle, infoSquirtle);

    // Create and add Bulbasaur.
    Pokemon bulbasaur("Bulbasaur", 270);
    PokemonInfo infoBulbasaur("Grass", "Has a seed on its back that grows over time.", 
        {{"Vine Whip", 4}, {"Razor Leaf", 6}, {"Solar Beam", 5}}, {0, 300, 1100});
    myPokedex.add(bulbasaur, infoBulbasaur);

    // Create and add Charmander.
    Pokemon charmander("Charmander", 633);
    PokemonInfo infoCharmander("Fire", "A small lizard with a flame on its tail.", 
        {{"Ember", 4}, {"Flamethrower", 6}, {"Fire Spin", 5}}, {0, 250, 1300});
    myPokedex.add(charmander, infoCharmander);

    // Display all Pokémon (part B of the assignment)
    cout << "DISPLAYING ALL POKEMON IN POKEDEX:\n";
    myPokedex.showAll();

    // Display specific Pokémon (part C of the assignment)
    cout << "\nSEARCH FOR SQUIRTLE:\n";
    myPokedex.show(Pokemon("Squirtle", 870));

    cout << "\nSEARCH FOR PIKACHU:\n";
    myPokedex.show(Pokemon("Pikachu", 390));

    return 0;
}
