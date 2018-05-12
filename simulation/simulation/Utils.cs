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

using System;

namespace simulation
{
    public static class Utils
    {
        private static Random random = new Random();

        public static float clamp(float value, float min, float max)
        {
	        if (min > max) throw new ArithmeticException("MIN > MAX in clamp function.");

	        if (value > max)
		        return max;
	        else if (value < min)
		        return min;
	        else
		        return value;
        }

        public static int clamp(int value, int min, int max)
        {
            if (min > max) throw new ArithmeticException("MIN > MAX in clamp function.");

            if (value > max)
                return max;
            else if (value < min)
                return min;
            else
                return value;
        }

        public static uint clamp(uint value, uint min, uint max)
        {
            if (min > max) throw new ArithmeticException("MIN > MAX in clamp function.");

            if (value > max)
                return max;
            else if (value < min)
                return min;
            else
                return value;
        }

        public static float wrap(float value, float min, float max)
        {
            if (min > max) throw new ArithmeticException("MIN > MAX in wrap function.");
	        if (min == max) return min;

	        float difference = max - min;

	        while (value < min)
		        value += difference;

	        while (value > max)
		        value -= difference;

	        return value;
        }

        public static int wrap(int value, int min, int max)
        {
            if (min > max) throw new ArithmeticException("MIN > MAX in wrap function.");
            if (min == max) return min;

            int difference = max - min;

            while (value < min)
                value += difference;

            while (value > max)
                value -= difference;

            return value;
        }

        public static uint wrap(uint value, uint min, uint max)
        {
            if (min > max) throw new ArithmeticException("MIN > MAX in wrap function.");
            if (min == max) return min;

            uint difference = max - min;

            while (value < min)
                value += difference;

            while (value > max)
                value -= difference;

            return value;
        }

        public static float randomFloat(float min, float max)
        {
            if (min > max)
                throw new ArithmeticException("MIN > MAX in randomFloat function.");
            else if (min == max)
                return min;
            else
                return ((float)random.NextDouble() * (max - min) + min);
        }

        public static int randomInt(int min, int max)
        {
            if (min > max)
                throw new ArithmeticException("MIN > MAX in randomFloat function.");
            else if (min == max)
                return min;
            else
                return random.Next(min, max + 1);
        }

        public static uint randomUint(uint min, uint max)
        {
            if (min > max)
                throw new ArithmeticException("MIN > MAX in randomFloat function.");
            else if (min == max)
                return min;
            else
                return (uint)random.Next((int)min, (int)max + 1);
        }

        public static int secureDivide(int value1, int value2)
        {
            if (value1 == value2)
                return 1;
            else if (value2 == 0)
            {
                if (value1 > 0)
                    return int.MaxValue;
                else
                    return int.MinValue;
            }
            else
                return value1 / value2;
        }

        public static float secureDivide(float value1, float value2)
        {
            if (value1 == value2)
                return 1.0f;
            else if (value2 == 0.0f)
            {
                if (value1 > 0.0f)
                    return float.PositiveInfinity;
                else
                    return float.NegativeInfinity;
            }
            else
                return value1 / value2;
        }

        public static int secureRemainer(int value1, int value2)
        {
            if (value1 == value2)
                return 0;
            else if (value2 == 0)
                return 0;
            else
                return value1 % value2;
        }
    }
}
