# DnD-generator
This code was built to get a better grasp on the nuances of the C++ language. 
Included in this procedurally written code is a Die Roller and a Character Stat Generator. 

The Die Roller was the original idea for this code but a bored ADHD tangent had it build into a larger scoped project.

As it stands currently, the best way that I could get the code to compile was to integrate a series of inheritance between
each class. I do not believe that this is truly necessary but as it stands, I plan on keeping it this way.

The Die Roller is focused on the main die used in D&D
Those being: d4, d6, d8, d10, d12, d20, d100. 
However I also included Percentile, which as someone pointed out to me, is redundant. I do not care. 
I do plan on building this function out more so that the user can determine the die size to roll down the road.

The Character Stat Generator is just that. 
It is set up to accept 5 methods of rolling stats. These 5 methods were chosen as just the general way I heard/seen
people roll their stats. 
Methods:
1. 4d6 - Drop Lowest Roll
2. 4d6 - Drop Lowest Roll - Reroll 1's
3. 3d6 - No Mulligan
4. 3d6 - Reroll 1's
5. 2d6 + 6
Method 5 is odd to me as the stat average comes out to like 14.5. Which I do not like, leaves little room for fun character
building moments for the sake of party-building, or character ark progression. 

Other than that, the only other path I currently have is to build this code to be able to create 
an entire stat sheet according to whatever the user wants at a whim. 
Lots of menuing will ensue... 
