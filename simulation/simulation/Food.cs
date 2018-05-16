/*
Copyright (C) 2018 Matej Gomboc (https://github.com/MatejGomboc/Evolution-Simulation)

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

using System.Collections.Generic;
using System.Linq;

namespace simulation
{
    class Food
    {
        public float energy
        {
            get;
            private set;
        }

        public float healthImportance
        {
            get;
            private set;
        }

        public float memLengthImportance
        {
            get;
            private set;
        }

        public uint timer
        {
            get;
            private set;
        }

        public const uint timerMaxValue = 100;

        public List<uint> claimants = null;
        public List<Animal.Weapon> claimantWeapons = null;

        public Food()
        {
            claimants = new List<uint>();
            claimantWeapons = new List<Animal.Weapon>();

            randomise();
        }

        private void randomise()
        {
            energy = Utils.randomFloat(0.0f, 1.0f);
            memLengthImportance = Utils.randomFloat(0.0f, 1.0f);
            healthImportance = Utils.randomFloat(0.0f, 1.0f);
            timer = Utils.randomUint(0, timerMaxValue);
            claimants.Clear();
            claimantWeapons.Clear();
        }

        private void releaseEnergy(ref List<Animal> animalPopulation)
        {
            if (claimants.Count > 1)
            {
                // calculate fitnesses

                float[] fitnesses = new float[claimants.Count];

                float maxHealth = animalPopulation.Max(o => o.health);
                float minHealth = animalPopulation.Min(o => o.health);

                int maxMemLength = animalPopulation.Max(o => o.memoryInt.Length + o.memoryFloat.Length);
                int minMemLength = animalPopulation.Min(o => o.memoryInt.Length + o.memoryFloat.Length);

                for (int i = 0; i < claimants.Count; i++)
                {
                    fitnesses[i] = healthImportance * Utils.secureDivide(animalPopulation[(int)claimants[i]].health - minHealth, maxHealth - minHealth) +
                        memLengthImportance * Utils.secureDivide((float)(animalPopulation[(int)claimants[i]].memoryInt.Length + animalPopulation[(int)claimants[i]].memoryFloat.Length - minMemLength),
                        (float)(maxMemLength - minMemLength));
                }

                // perform tournament competition

                while (claimants.Count > 1)
                {
                    int i1 = Utils.randomInt(0, claimants.Count);

                    int i2;
                    do
                    {
                        i2 = Utils.randomInt(0, claimants.Count);
                    } while (i2 == i1);

                    if ((claimantWeapons[i1] == Animal.Weapon.PAPER) && (claimantWeapons[i2] == Animal.Weapon.ROCK))
                    {
                        claimantWeapons.RemoveAt(i2);
                        claimants.RemoveAt(i2);
                    }
                    else if ((claimantWeapons[i2] == Animal.Weapon.PAPER) && (claimantWeapons[i1] == Animal.Weapon.ROCK))
                    {
                        claimantWeapons.RemoveAt(i1);
                        claimants.RemoveAt(i1);
                    }
                    else if ((claimantWeapons[i1] == Animal.Weapon.PAPER) && (claimantWeapons[i2] == Animal.Weapon.SCISSORS))
                    {
                        claimantWeapons.RemoveAt(i1);
                        claimants.RemoveAt(i1);
                    }
                    else if ((claimantWeapons[i2] == Animal.Weapon.PAPER) && (claimantWeapons[i1] == Animal.Weapon.SCISSORS))
                    {
                        claimantWeapons.RemoveAt(i2);
                        claimants.RemoveAt(i2);
                    }
                    else if ((claimantWeapons[i1] == Animal.Weapon.ROCK) && (claimantWeapons[i2] == Animal.Weapon.SCISSORS))
                    {
                        claimantWeapons.RemoveAt(i2);
                        claimants.RemoveAt(i2);
                    }
                    else if ((claimantWeapons[i2] == Animal.Weapon.ROCK) && (claimantWeapons[i1] == Animal.Weapon.SCISSORS))
                    {
                        claimantWeapons.RemoveAt(i1);
                        claimants.RemoveAt(i1);
                    }
                    else if (fitnesses[i1] > fitnesses[i2])
                    {
                        claimantWeapons.RemoveAt(i2);
                        claimants.RemoveAt(i2);
                    }
                    else if (fitnesses[i2] > fitnesses[i1])
                    {
                        claimantWeapons.RemoveAt(i1);
                        claimants.RemoveAt(i1);
                    }
                    else if (Utils.randomInt(0, 1) == 1)
                    {
                        claimantWeapons.RemoveAt(i2);
                        claimants.RemoveAt(i2);
                    }
                    else
                    {
                        claimantWeapons.RemoveAt(i1);
                        claimants.RemoveAt(i1);
                    }
                }
            }

            if (claimants.Count > 0)
            {
                // feed the winning animal

                animalPopulation[(int)claimants[0]].eatFood(energy);

                // reset food

                randomise();
            }
        }

        public void advanceTimer(ref List<Animal> animalPopulation)
        {
            if (claimants.Count > 0)
            {
                if (timer > 0) --timer;
                else releaseEnergy(ref animalPopulation);
            }
        }
    }
}
