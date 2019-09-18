# Project Proposal
final project proposal: a doodle jump game

The proposal should be about one page long and describe
what you want your project to do and what libraries or resources you have identiﬁed to use for this project.
You should provide links to outside resources you are planing on using in the project

library I would use
# use  <SFML/Graphics.hpp>,  a multimedia library
## use time.h, keep track of the time

Links:
https://github.com/SFML/SFML -  the SFML/Graphics lib
[SFML](https://github.com/SFML/SFML)

 https://github.com/ebrevdo/arduino/blob/master/libraries/Time/Time.h -  the time.h lib
[Time.h]( https://github.com/ebrevdo/arduino/blob/master/libraries/Time/Time.h)

 simple description of the doodle game:
 In Doodle Jump, the aim is to guide a four-legged creature called "The Doodler" up a never-ending series of platforms without falling.(cited from Wikipedia)

  features of the game (based on the basic doodle jump game):
  1. endless map randomly arranged stairs for the charactor to step on
  2.  first playable version: the user should be able to manipulate the characcter by clicking upperkeys on the keyboard;
  		the character should be able to move up, left and right.
  		If the user doesn't move up, the character should fall automatically by default.
  3. game over state: if the user fail to step on any stair and fall down they should lose
  4. score: keep track of the height of the character currently is at
  	if the character sticks at the same height for more than two minutes then the game should end
  5. no edges (like mod): for example, if the character move to the right-most place, it will show up at the left-most place of the screen

  extra features: (depends on the time)
  5. monster: if the character steps on one monster, it should die immediately
  6. new costume: at some levels, the character can unlock new costumes
  7. top scores: keep track of the top ten scores in a global vector<long> variable

 Image of the character:
 ![GitHub Logo](/images/logo.png)
Format: ![the creature "the doodle"]
(https://www.google.com/search?q=the+doodle+jump&safe=strict&tbm=isch&tbs=rimg:CbTxFUJzrNA4IjiI1PPFeYE-Pa1f20MjzVv3vbC4y5v30uRlSBDoRjvJXJC2vM80bsXr2siS2fzWH2_1z7QHBK3haLyoSCYjU88V5gT49EVeZf3G269FUKhIJrV_1bQyPNW_1cR8zt8Dwmos8kqEgm9sLjLm_1fS5BEvggWvkbH5LioSCWVIEOhGO8lcEXxz1_1PenBIeKhIJkLa8zzRuxesR6qUx9l2_1KPAqEgnayJLZ_1NYfbxFUVlm2SnBhUioSCfPtAcEreFovEVy7mCOq9GHF&tbo=u&sa=X&ved=2ahUKEwjszer0j67aAhVm9IMKHS_XDLUQ9C96BAgAEBs&biw=1536&bih=732&dpr=1.25#imgrc=8-0BwSt4Wi-CeM:)
(https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&ved=2ahUKEwjszer0j67aAhVm9IMKHS_XDLUQjRx6BAgAEAU&url=http%3A%2F%2Fdoodle-jump.wikia.com%2Fwiki%2FNinja_Doodler&psig=AOvVaw0eaXynMEt45O6-9gQFymMf&ust=1523395287904083)