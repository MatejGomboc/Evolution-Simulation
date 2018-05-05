/*
Copyright (C) 2018 Matej Gomboc

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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace simulation
{
    partial class Animal
    {
        public enum Weapon
        {
            PAPER,
            ROCK,
            SCISSORS
        }

        public const float maxMemFloatValue = 1000.0f;
        public const float minMemFloatValue = -1000.0f;

        public const int maxMemIntValue = 1000;
        public const int minMemIntValue = -1000;

        public float health
        {
            get;
            private set;
        }

        public List<uint> claimants
        {
            get;
            private set;
        }

        public List<Weapon> claimantWeapons
        {
            get;
            private set;
        }

        public int[] memoryInt
        {
            get;
            private set;
        }

        public float[] memoryFloat
        {
            get;
            private set;
        }

        public Instruction[] program
        {
            get;
            private set;
        }

        public Animal(Instruction[] newProgram, int[] newMemoryInt, float[] newMemoryFloat)
        {
            health = 1.0f;
            claimants = new List<uint>();
            claimantWeapons = new List<Weapon>();
            program = newProgram;
            memoryInt = newMemoryInt;
            memoryFloat = newMemoryFloat;
        }

        public void eatFood(float foodEnergy)
        {
            health += foodEnergy;
        }
    }
}
