<h1>get_next_line</h1>
<h2>Project description</h2>
<div>
<!--  <a href="https://github.com/JaeSeoKim/badge42">
    <img align="center" src="https://badge42.herokuapp.com/api/project/samoreno/ft_printf"/>
  </a> -->
  <p>This is the first graphical project at 42 Madrid. The goal is to create a program that opens a window and lets he user play a simple game. The following table shows the requirements:
  <table>
    <tr>
      <th>Program name</th>
      <td>so_long</td>
    </tr>
    <tr>
      <th>Arguments</th>
      <td>A map in format *.ber</td>
    </tr>
    <tr>
      <th>External C functions allowed</th>
      <td>open, close, read, write, printf, malloc, free, perror, strerror, exit and all the functions of the MiniLibX</td>
    </tr>
    <tr>
      <th>Description</th>
      <td>Create a small 2D game in which the hero collects all the chests and leaves through the exit</td>
    </tr>
</table>
  </p>
  </div>
  <div>
  <p>
  The map has to be constructed with 3 components: walls, collectibles, and free space. The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route. At every move, the current number of movements must be displayed in the shell. The player should be able to move in these 4 directions: up, down, left, right with WASD keys. Pressing ESC must close the window and quit the program in a clean way.<br/>
    The format of a valid map is:
    <ul>
      <li>0 for an empty space,</li>
      <li>1 for a wall,</li>
      <li>C for a collectible,</li>
      <li>E for a map exit,</li>
      <li>P for the player’s starting position,</li>
      <li>X for an enemy’s starting position</li>
    </ul>
  Maps must contain at least one exit, one collectible, and only one starting position, be rectangular, and closed by walls. There are valid and invalid maps in the <b>map</b> folder. If any misconfiguration of any kind is encountered in the file, the program exits in a clean way, and returns "Error\n" followed by an explicit error.<br/>
  In addition, there are enemy patrols that move around the map. If the player touches them, the program closes as that means they have lost. The number of movements is also displayed on the top left corner of the game.
  </p>
</div>
<h2>Usage</h2>
<div>
    <p>
        With the Makefile you can compile directly. The rules that it allows are:
        <ul>
         <li>Make: it compiles directly</li>
         <li>Make re: if the project is already compiled, it does it again</li>
         <li>Make clean. Deletes all .o files but the executable remains</li>
         <li>make fclean: deletes all .o files and the executable</li>
    </ul>
    </p>
</div>
