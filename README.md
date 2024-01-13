# Advent_Of_Code_2023
## My files for completing [advent of code, 2023](https://adventofcode.com/2023). I started on the 9th of december.
*I will try to optimize these in the future.
1. [Trebuchet?!](https://github.com/TheFosh/adventOfCode_2023/tree/main/day1/day1):
    * Given an input of strings, each containing at least 1 number in it, I must find the numbers and combine them into a two digit number. The first number found is the first digit, and the second found is the second.
    * For part 1, find this for all lines and add numbers together for the answer to the puzzle.
    * For part 2, there were some words that resemble words (i.e. one, two, ...). These will now count for valid digits in the puzzle.
2. *[Cube Conundrum](https://github.com/TheFosh/adventOfCode_2023/tree/main/day2/day2): 
   * Given an input, each line represents a game of where a random number of cubes is pulled from a bag. The cubes can be red, green, or blue and always put back into the bag after each pull.
   * For part 1, find out which games are possible have a bag of 12 red, 13 green, and 14 blue cubes. Add the number of the valid games together. This is the puzzle answer.
   * For part 2, figure out the smallest possible set of cubes in the bag for each game. Multiply each color of a game together and add these numbers to each games. This the puzzle answer.
3. *[Gear Ratios](https://github.com/TheFosh/adventOfCode_2023/tree/main/day3/day3):
   * Given an input, this forms a 2D grid of numbers and symbols
   * For part 1, some numbers have symbols next to them and some don't. I must add together all numbers near a symbol other than the "." symbol. This is the answer to the puzzle.
   * For part 2, some symbols in the grid are the "*" symbol. I must find these with exactly two numbers next them and multiply them together then add all of these multiplactions. This is the answer to the puzzle.
4. [Scratchcards](https://github.com/TheFosh/adventOfCode_2023/tree/main/day4/day4):
   * The input given is formatted as scratch cards where the winning numbers are on the left side of the '|' symbol and your given numbers are the ones on right side.
   * For part 1, calculate the score for all the cards. The score is based on the number of pairs of your numbers and winning numbers. One pair makes the card one point then another after that pair doubles the score and so on. The score is answer to the puzzle
   * For part 2, count how many cards are infront of you if the orignal cards can generate copies of cards. If a winning card has any number of pairs it generates a number copies of the next cards after it. The number of copies is based on the number of pairs from the original(if card 10 has 2 pairs then it makes a copy of 11 and 12). Copies of cards are also checked if they have winning pairs and can also generate copies after them. Find the number of original cards and copies of cards.
## Will try to continue more
