/*
Copyright (C) 2019 Matej Gomboc (https://github.com/MatejGomboc/Evolution-Simulation)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <cstdint>
#include <vector>
#include <set>

class Food;

class Animal
{
public:
	enum class Weapon
	{
		rock,
		paper,
		scissors
	};

private:
	uint8_t m_fitness;
	Weapon m_weapon;

	// die parameters
	uint8_t m_fit_loss_rate;

	// eat parameters
	float m_eat_prob;

	// mating parameters
	float m_mate_prob;
	std::set<Animal* const> m_claimants;

	// mutation parameters
	float m_mutate_prob;

	static bool decide(const float probability);
	void add_claimant(Animal* const animal);

public:
	Animal(void);
	Animal(const uint8_t fitness, const Weapon weapon, const uint8_t fit_loss_rate, const float eat_prob,
		const float mate_prob, const float mutate_prob);
	static bool fight(Animal* const animal1, Animal* const animal2);
	static Animal* const mate(Animal* const animal1, Animal* const animal2);
	void mutate(void);
	void ageing(void);
	void eat_food(const uint8_t energy);
	Animal* const tournament(void);
	static Weapon random_weapon(void);
	static float random_prob(void);
	static uint8_t random_int(void);
	uint8_t get_fitness(void) const;
	void simulate(const std::vector<Animal* const>& animals, const std::vector<Food* const>& food);
};

#endif
