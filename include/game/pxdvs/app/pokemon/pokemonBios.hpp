#ifndef POKEMON_BIOS_H
#define POKEMON_BIOS_H

struct Pokemon;
typedef struct PokemonGrowDataBios PokemonGrowDataBios;
typedef struct PokemonSeikakuDataBios PokemonSeikakuDataBios;
typedef struct PokemonSeikakuRateBios PokemonSeikakuRateBios;

extern "C" u32 pokemonSeikakuRateDataBiosGetWaru(PokemonSeikakuRateBios*);
extern "C" u32 pokemonSeikakuRateDataBiosGetKake(PokemonSeikakuRateBios*);
extern "C" PokemonSeikakuRateBios* pokemonSeikakuRateDataBiosGetPtr(u32);
extern "C" u32 pokemonSeikakuDataBiosGetNimblenessRateDataId(PokemonSeikakuDataBios*);
extern "C" u32 pokemonSeikakuDataBiosGetSpeDefRateDataId(PokemonSeikakuDataBios*);
extern "C" u32 pokemonSeikakuDataBiosGetSpeAtkRateDataId(PokemonSeikakuDataBios*);
extern "C" u32 pokemonSeikakuDataBiosGetPhyDefRateDataId(PokemonSeikakuDataBios*);
extern "C" u32 pokemonSeikakuDataBiosGetPhyAtkRateDataId(PokemonSeikakuDataBios*);
extern "C" PokemonSeikakuDataBios* pokemonSeikakuDataBiosGetPtr(u32);
extern "C" PokemonGrowDataBios* pokemonGrowDataBiosGetPtr(u8);
extern "C" int pokemonGrowDataBiosGetExp(PokemonGrowDataBios*, unsigned char);
extern "C" void pokemonBiosCopy(const Pokemon *, const Pokemon *);


#endif
