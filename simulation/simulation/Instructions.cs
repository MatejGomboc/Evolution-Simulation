﻿/*
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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace simulation
{
    partial class Animal
    {
        public abstract class Instruction
        {
            public const uint numOfInstructions = 50;

            public bool used = false;

            public Instruction()
            {
                this.used = false;
            }

            public Instruction(Animal animal)
            {
                this.used = false;
                randomise(animal);
            }

            public abstract void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket);

            public abstract void randomise(Animal animal);

            public static Weapon randomWeapon()
            {
                uint indx = Utils.randomUint(0, 2);

                switch (indx)
                {
                    case 0:
                        return Weapon.PAPER;
                    case 1:
                        return Weapon.ROCK;
                    default:
                        return Weapon.SCISSORS;

                }
            }

            //public static Instruction random(Animal animal)
            //{
            //    uint indx = Utils.randomUint(0, numOfInstructions - 1);

            //    switch (indx)
            //    {
            //        default:
            //            return new AddFloatFloatFloat();
            //    }
            //}
        }

        #region Init
        public class InitInt : Instruction
        {
            public uint indx
            {
                get;
                private set;
            }

            public int value
            {
                get;
                private set;
            }

            public InitInt(uint indx, int value)
                : base()
            {
                this.indx = indx;
                this.value = value;
            }

            public InitInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx] = value;
            }

            public override void randomise(Animal animal)
            {
                indx = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                value = Utils.randomInt(minMemIntValue, maxMemIntValue);
            }
        }

        public class InitFloat : Instruction
        {
            public uint indx
            {
                get;
                private set;
            }

            public float value
            {
                get;
                private set;
            }

            public InitFloat(uint indx, float value)
                : base()
            {
                this.indx = indx;
                this.value = value;
            }

            public InitFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx] = value;
            }

            public override void randomise(Animal animal)
            {
                indx = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                value = Utils.randomFloat(minMemFloatValue, maxMemFloatValue);
            }
        }
        #endregion

        #region Copy
        public class CopyIntInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public CopyIntInt(uint indx1, uint indx2)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
            }

            public CopyIntInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = animal.memoryInt[indx2];
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class CopyIntFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public CopyIntFloat(uint indx1, uint indx2)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
            }

            public CopyIntFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = (float)animal.memoryInt[indx2];
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class CopyFloatInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public CopyFloatInt(uint indx1, uint indx2)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
            }

            public CopyFloatInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = (int)animal.memoryFloat[indx2];
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class CopyFloatFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public CopyFloatFloat(uint indx1, uint indx2)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
            }

            public CopyFloatFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = animal.memoryFloat[indx2];
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }
        #endregion

        #region Add
        public class AddIntIntInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public AddIntIntInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public AddIntIntInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(animal.memoryInt[indx2] + animal.memoryInt[indx3], minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class AddIntFloatInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public AddIntFloatInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public AddIntFloatInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(animal.memoryInt[indx2] + (int)animal.memoryFloat[indx3], minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class AddFloatFloatInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public AddFloatFloatInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public AddFloatFloatInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp((int)animal.memoryFloat[indx2] + (int)animal.memoryFloat[indx3], minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class AddIntFloatFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public AddIntFloatFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public AddIntFloatFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp((float)animal.memoryInt[indx2] + animal.memoryFloat[indx3], minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class AddIntIntFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public AddIntIntFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public AddIntIntFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp((float)animal.memoryInt[indx2] + (float)animal.memoryInt[indx3], minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class AddFloatFloatFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public AddFloatFloatFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public AddFloatFloatFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp(animal.memoryFloat[indx2] + animal.memoryFloat[indx3], minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }
        #endregion

        #region Subtract
        public class SubtractIntIntInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public SubtractIntIntInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public SubtractIntIntInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(animal.memoryInt[indx2] - animal.memoryInt[indx3], minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class SubtractIntFloatInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public SubtractIntFloatInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public SubtractIntFloatInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(animal.memoryInt[indx2] - (int)animal.memoryFloat[indx3], minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class SubtractFloatIntInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public SubtractFloatIntInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public SubtractFloatIntInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp((int)animal.memoryFloat[indx2] - animal.memoryInt[indx3], minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class SubtractFloatFloatInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public SubtractFloatFloatInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public SubtractFloatFloatInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp((int)animal.memoryFloat[indx2] - (int)animal.memoryFloat[indx3], minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class SubtractIntFloatFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public SubtractIntFloatFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public SubtractIntFloatFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp((float)animal.memoryInt[indx2] - animal.memoryFloat[indx3], minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class SubtractFloatIntFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public SubtractFloatIntFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public SubtractFloatIntFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp(animal.memoryFloat[indx2] - (float)animal.memoryInt[indx3], minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class SubtractIntIntFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public SubtractIntIntFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public SubtractIntIntFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp((float)animal.memoryInt[indx2] - (float)animal.memoryInt[indx3], minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class SubtractFloatFloatFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public SubtractFloatFloatFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public SubtractFloatFloatFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp(animal.memoryFloat[indx2] - animal.memoryFloat[indx3], minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }
        #endregion

        #region Multiply
        public class MultiplyIntIntInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public MultiplyIntIntInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public MultiplyIntIntInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(animal.memoryInt[indx2] * animal.memoryInt[indx3], minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class MultiplyIntFloatInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public MultiplyIntFloatInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public MultiplyIntFloatInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp((int)animal.memoryFloat[indx2] * animal.memoryInt[indx3], minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class MultiplyFloatFloatInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public MultiplyFloatFloatInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public MultiplyFloatFloatInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp((int)animal.memoryFloat[indx2] * (int)animal.memoryFloat[indx3], minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class MultiplyIntFloatFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public MultiplyIntFloatFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public MultiplyIntFloatFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp((float)animal.memoryInt[indx2] * animal.memoryFloat[indx3], minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class MultiplyIntIntFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public MultiplyIntIntFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public MultiplyIntIntFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp((float)animal.memoryInt[indx2] * (float)animal.memoryInt[indx3], minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class MultiplyFloatFloatFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public MultiplyFloatFloatFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public MultiplyFloatFloatFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp(animal.memoryFloat[indx2] * animal.memoryFloat[indx3], minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }
        #endregion

        #region Divide
        public class DivideIntIntInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public DivideIntIntInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public DivideIntIntInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(Utils.secureDivide(animal.memoryInt[indx2], animal.memoryInt[indx3]), minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class DivideIntFloatInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public DivideIntFloatInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public DivideIntFloatInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(Utils.secureDivide(animal.memoryInt[indx2], (int)animal.memoryFloat[indx3]), minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class DivideFloatIntInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public DivideFloatIntInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public DivideFloatIntInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(Utils.secureDivide((int)animal.memoryFloat[indx2], animal.memoryInt[indx3]), minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class DivideFloatFloatInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public DivideFloatFloatInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public DivideFloatFloatInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(Utils.secureDivide((int)animal.memoryFloat[indx2], (int)animal.memoryFloat[indx3]), minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class DivideIntFloatFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public DivideIntFloatFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public DivideIntFloatFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp(Utils.secureDivide((float)animal.memoryInt[indx2], animal.memoryFloat[indx3]), minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class DivideFloatIntFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public DivideFloatIntFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public DivideFloatIntFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp(Utils.secureDivide(animal.memoryFloat[indx2], (float)animal.memoryInt[indx3]), minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class DivideIntIntFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public DivideIntIntFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public DivideIntIntFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp(Utils.secureDivide((float)animal.memoryInt[indx2], (float)animal.memoryInt[indx3]), minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class DivideFloatFloatFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public DivideFloatFloatFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public DivideFloatFloatFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = Utils.clamp(Utils.secureDivide(animal.memoryFloat[indx2], animal.memoryFloat[indx3]), minMemFloatValue, maxMemFloatValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }
        #endregion

        #region Remainder
        public class RemainderIntInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public RemainderIntInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public RemainderIntInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(Utils.secureRemainer(animal.memoryInt[indx2], animal.memoryInt[indx3]), minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class RemainderIntFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public RemainderIntFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public RemainderIntFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(Utils.secureRemainer(animal.memoryInt[indx2], (int)animal.memoryFloat[indx3]), minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }

        public class RemainderFloatInt : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public RemainderFloatInt(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public RemainderFloatInt(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(Utils.secureRemainer((int)animal.memoryFloat[indx2], animal.memoryInt[indx3]), minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class RemainderFloatFloat : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public RemainderFloatFloat(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public RemainderFloatFloat(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = Utils.clamp(Utils.secureRemainer((int)animal.memoryFloat[indx2], (int)animal.memoryFloat[indx3]), minMemIntValue, maxMemIntValue);
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
            }
        }
        #endregion

        #region Food
        public class ReadFoodEnergy : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public ReadFoodEnergy(uint indx1, uint indx2)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
            }

            public ReadFoodEnergy(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryFloat[indx1] = foodBasket[Utils.wrap(animal.memoryInt[indx2], 0, foodBasket.Length)].energy;
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class ReadNumOfFoodClaimants : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public ReadNumOfFoodClaimants(uint indx1, uint indx2)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
            }

            public ReadNumOfFoodClaimants(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                animal.memoryInt[indx1] = foodBasket[Utils.wrap(animal.memoryInt[indx2], 0, foodBasket.Length)].claimants.Count;
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class ReadFoodClaimantWeapon : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public ReadFoodClaimantWeapon(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public ReadFoodClaimantWeapon(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                int i2 = Utils.wrap(animal.memoryInt[indx2], 0, foodBasket.Length);
                int i3 = Utils.wrap(animal.memoryInt[indx3], 0, foodBasket[i2].claimantWeapons.Count);

                switch (foodBasket[i2].claimantWeapons[i3])
                {
                    case Weapon.PAPER:
                        animal.memoryInt[indx1] = 1;
                        break;
                    case Weapon.ROCK:
                        animal.memoryInt[indx1] = 2;
                        break;
                    case Weapon.SCISSORS:
                        animal.memoryInt[indx1] = 3;
                        break;
                }
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class ReadFoodClaimantIndx : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public ReadFoodClaimantIndx(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public ReadFoodClaimantIndx(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                int i2 = Utils.wrap(animal.memoryInt[indx2], 0, foodBasket.Length);
                int i3 = Utils.wrap(animal.memoryInt[indx3], 0, foodBasket[i2].claimants.Count);

                animal.memoryInt[indx1] = (int)foodBasket[i2].claimants[i3];
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class ClaimFood : Instruction
        {
            public uint indx
            {
                get;
                private set;
            }

            public Weapon weapon
            {
                get;
                private set;
            }

            public ClaimFood(uint indx, Weapon weapon)
                : base()
            {
                this.indx = indx;
                this.weapon = weapon;
            }

            public ClaimFood(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                int i = Utils.wrap(animal.memoryInt[indx], 0, foodBasket.Length);

                if (!foodBasket[i].claimants.Contains(animalIndx))
                {
                    foodBasket[i].claimantWeapons.Add(weapon);
                    foodBasket[i].claimants.Add(animalIndx);
                }
            }

            public override void randomise(Animal animal)
            {
                indx = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                weapon = randomWeapon();
            }
        }
        #endregion

        #region Mating
        public class ReadAnimalHealth : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public ReadAnimalHealth(uint indx1, uint indx2)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
            }

            public ReadAnimalHealth(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                int i = Utils.wrap(animal.memoryInt[indx2], 0, animalPopulation.Count);

                animal.memoryFloat[indx1] = animalPopulation[i].health;
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryFloat.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class ReadAnimalMemLength : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public ReadAnimalMemLength(uint indx1, uint indx2)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
            }

            public ReadAnimalMemLength(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                int i = Utils.wrap(animal.memoryInt[indx2], 0, animalPopulation.Count);

                animal.memoryInt[indx1] = animalPopulation[i].memoryInt.Length + animalPopulation[i].memoryFloat.Length;
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class ReadNumOfAnimalClaimants : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public ReadNumOfAnimalClaimants(uint indx1, uint indx2)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
            }

            public ReadNumOfAnimalClaimants(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                int i = Utils.wrap(animal.memoryInt[indx2], 0, animalPopulation.Count);

                animal.memoryInt[indx1] = animalPopulation[i].claimants.Count;
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class ReadAnimalClaimantWeapon : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public ReadAnimalClaimantWeapon(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public ReadAnimalClaimantWeapon(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                int i2 = Utils.wrap(animal.memoryInt[indx2], 0, animalPopulation.Count);
                int i3 = Utils.wrap(animal.memoryInt[indx3], 0, animalPopulation[i2].claimants.Count);

                switch (animalPopulation[i2].claimantWeapons[i3])
                {
                    case Weapon.PAPER:
                        animal.memoryInt[indx1] = 1;
                        break;
                    case Weapon.ROCK:
                        animal.memoryInt[indx1] = 2;
                        break;
                    case Weapon.SCISSORS:
                        animal.memoryInt[indx1] = 3;
                        break;
                }
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class ReadAnimalClaimantIndx : Instruction
        {
            public uint indx1
            {
                get;
                private set;
            }

            public uint indx2
            {
                get;
                private set;
            }

            public uint indx3
            {
                get;
                private set;
            }

            public ReadAnimalClaimantIndx(uint indx1, uint indx2, uint indx3)
                : base()
            {
                this.indx1 = indx1;
                this.indx2 = indx2;
                this.indx3 = indx3;
            }

            public ReadAnimalClaimantIndx(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                int i2 = Utils.wrap(animal.memoryInt[indx2], 0, animalPopulation.Count);
                int i3 = Utils.wrap(animal.memoryInt[indx3], 0, animalPopulation[i2].claimants.Count);

                animal.memoryInt[indx1] = (int)animalPopulation[i2].claimants[i3];
            }

            public override void randomise(Animal animal)
            {
                indx1 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx2 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                indx3 = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
            }
        }

        public class ClaimAnimal : Instruction
        {
            public uint indx
            {
                get;
                private set;
            }

            public Weapon weapon
            {
                get;
                private set;
            }

            public ClaimAnimal(uint indx, Weapon weapon)
                : base()
            {
                this.indx = indx;
                this.weapon = weapon;
            }

            public ClaimAnimal(Animal animal)
                : base(animal)
            {
            }

            public override void execute(ref Animal animal, ref List<Animal> animalPopulation, uint animalIndx, ref Food[] foodBasket)
            {
                int i = Utils.wrap(animal.memoryInt[indx], 0, animalPopulation.Count);

                if (!animalPopulation[i].claimants.Contains(animalIndx))
                {
                    animalPopulation[i].claimants.Add(animalIndx);
                    animalPopulation[i].claimantWeapons.Add(weapon);
                }
            }

            public override void randomise(Animal animal)
            {
                indx = Utils.randomUint(0, (uint)animal.memoryInt.Length - 1);
                weapon = randomWeapon();
            }
        }
        #endregion
    }
}
