
# RPS

The acronym RPS stands for Rock, Paper, Scissors. The goal of this program is to use dynamic arrays to transition players from active to inactive states. The program will ask the user how many players will be present, as well as their names. It will continue to play as many rounds as necessary until just one player remains. It will display the winner, which is the player with the highest score, at the conclusion.
## Functions

| Name             | Objective                |
| ----------------- | -------------------------- |
| Player | default constructor |
| Player(string n) | value constructor |
| ~Player | deconstructor |
| Display | displays name, throws, and score |
| Score | returns score of player |
| Name | returns name of player |
| TakeTurn | fills the array throw by calling the function Shoot() to fill each index |
| Match | figures out which player has the highest score at the end of all three rounds |
| Shoot | picks a random number for 0-2 |


## Demo

![ex1](https://s7.gifyu.com/images/ezgif.com-gif-maker6bacd3e2a24bef33.gif)
![ex2](https://s7.gifyu.com/images/ezgif.com-gif-maker-14eecee4324b16077.gif)


## License

[MIT](https://choosealicense.com/licenses/mit/)

