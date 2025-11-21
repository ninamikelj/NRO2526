Primerjava metod:

GriddedInterpolant je najhitrejša, ker že ve, kje v mreži je iskana točka (deluje le na urejeni mreži podatkov). Ni treba pregledovati vsake celice ali vozlišča posebej.

ScatteredInterpolant je najpočasnejša, ker mora ugotoviti, kje znotraj vseh podatkov leži iskana točka (išče v trikotnikih po poljubno razporejenih podatkih oz povedano na drug način, metoda gre skozi kompleksno geometrijo poljubnih vozlišč - kar je zelo počasno).

Lastna bilinearna interpolacija je hitrejša od ScatteredInterpolant, ampak počasnejša od GriddedInterpolant ker ročno pregleduje vse celice, da najde tisto, v kateri je točka.
