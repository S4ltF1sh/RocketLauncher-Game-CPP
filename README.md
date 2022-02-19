# RocketLauncher Game C++
***This is my little game that uses the SFML library.***

***"Wibu Time!** folder is the folder containing the project running on Visual Studio.*

***testCPP** file is the code I wrote to convert a 1-dimensional array to a matrix for map drawing (you can read about my map creation below)*

Don't mind about "Wibu Time!", the name of this game is "RocketLauncher" :v
 
This game only has 8 levels and it will probably be updated depending on my mood :D

This game has 1 easter egg, try to find it :>

You can adjust level and total number of deaths in Map.txt.
![image](https://user-images.githubusercontent.com/84552830/154812812-7e6cf1a2-f448-4a78-bd2f-a73ca7da5383.png)

***How to create map***

Step 1:

_I use tiled to draw the map as I want, to do this I need a game asset:

*I used:* https://pixelfrog-assets.itch.io/pixel-adventure-1 _  //I designed the rocket myself :D

_To use Tiled easily, you can refer to some instructions:

https://doc.mapeditor.org/en/stable/manual/introduction/#getting-started //Getting started with Tiled.

https://doc.mapeditor.org/en/stable/manual/terrain/ //How to use terrain sets.

![image](https://user-images.githubusercontent.com/84552830/154813256-96018e6c-0059-4c86-8b44-f3e0ec6b58e1.png)

Step 2:

_I save the map file as json.

_And then Open the saved json file and copy data from the array "data" in that file.
![image](https://user-images.githubusercontent.com/84552830/154813639-d44eef7f-7f76-48f9-a907-5c62d51570c1.png)

_And paste that data into the array section in **TestCPP.cpp**, run the code and it will help you convert the data just now into matrix form.
![image](https://user-images.githubusercontent.com/84552830/154813668-ad74665f-1905-44c0-9957-68fc8bd692ab.png)

//You can change the number of row and col depending on the number of tiles in your map.

//Here is the conversion code I wrote and I got confused between rows and columns (You can see in the game code I had to invert the row and column values).

![image](https://user-images.githubusercontent.com/84552830/154813935-e1495c2f-eb28-4520-80c7-1861ded2e7dd.png)

//You can rewrite another conversion code that works for you (note that the Ox and Oy axes in SFML are reversed to Cartesian coordinate system)

Step 3:

_Copy the result that the conversion code prints out and save it to a file so that when the game loads, you will open that file and get the data from it.
![image](https://user-images.githubusercontent.com/84552830/154814162-c51a9632-965b-4e6f-aa48-e3350aa8bac4.png)

//load data from Map.txt file:
![image](https://user-images.githubusercontent.com/84552830/154814209-579fc036-b582-4605-b672-eecfe22a6cd2.png)

//I draw the map based on the name of map's pieces. Each piece will have different functions, 

//for example Trap and Block are 2 different types and they will be divided into 2 different classes and saved to the Map.
![image](https://user-images.githubusercontent.com/84552830/154814349-a08ef82b-227f-408c-84d7-b36cd3816d10.png)
![image](https://user-images.githubusercontent.com/84552830/154814372-8209449d-defd-404d-bdb8-e9e7614e1600.png)

_You can modify each map by modifying the Map files in the folder **MapForm** by following name of map's pieces in folder **Wibu time!\Wibu time!\Data\Textures\Map**


***My game learned a lot about Resource Manager, Rocket Stage and Game Stage from:*** 

https://www.youtube.com/watch?v=ANjk6LsShRo&list=PLZd7ojlRK0bwrL8060OGurG_kaeJc_QOH
