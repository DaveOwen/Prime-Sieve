#Prime-Sieve
Program to find a set amount of prime numbers to a set limit. Change the range variable to choose what the upper limit for the search will be. The code will run a set amount of times according the the 'RUNS' variable, which is later calculated to get the average speed of each run. This is done to get a more accurate reading.

##Optimization in Visual Studio
Go to: Project > *ProjectName* Properties > C/C++ > Optimization. 

Select the following settings:
  - Optimization = Maximize Speed (/O2)
  - Favor Size Or Speed = Favour fast code (/Ot)

Go to: Project > *ProjectName* Properties > C/C++ > Code Generation.
Select the following setting:
 - Basic Runtime Checks = Default
