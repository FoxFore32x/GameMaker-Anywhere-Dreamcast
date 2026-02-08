<p align="center">
  <img src="Github assets/gamemaker_anywhere_logo.png" alt="GameMaker Anywhere logo" width="300" />
</p>

## Info
<p align="left">
A work in progress open source port of gamemaker to several consoles (3ds only currently) using devkitpro and C.
https://discord.gg/cc2YA2pChU

This fork is made for Dreamcast support specifically, while also serving for additions that will later be implemented in the main runner.

If Dreamcast support is completed, and some features end up being added, will see if they can be merged into the main repo.

- FoxFore32x
</p>

<br>

<p align="center">
  <img src="Github assets/example.gif" alt="The example gif" width="600" />
</p>

## Current Progress
Feel free to contribute! (i really need the help...)

### Complete
- Setting X and Y
- if statements
- Addition and subtraction
- Room width and height
- room background colors
- Object and Asset drawing

### Todo (sorted from least to most needed)
- "&&" and "||"
- custom variable stuff
- rooms (should be pretty easy)
- instance_create_depth and layer
- scripts
- object referencing
- port to other platforms (just need to replace 3ds apis)
## compiling
(theres a pre compiled 3dsx and cia inside the output folder \Runners\3DS\output)

compiling is currently only recommended with the test project, anything else is almost guaranteed not to work (for now)
this assumes you have devkitpro and citro2d installed
this process will be easier later, just needing you to click the yyp in data.win compiler project

<br>

1. download the repo and extract it to a location without spaces in the path. eg: D:\projects_and_stuff\GameMaker-Anywhere\
2. using gamemaker, open the data.win compiler project and run it 
3. select the yyp of the test project
4. after finishing, go to the test project folder and open the "3DS Data Exported" folder
5. run the "build_sprites_t3x.bat"
6. after completing, copy and paste the data.win to the consoles runner romfs folder
7. copy the t3x in the gfx folder of the test project and copy it in to the romfs gfx folder in the runner
8. copy everything besides the t3x from the test projects gfx folder into the runners root gfx folder
9. open powershell in the root directory of the runner and run make 3dsx
10. if everythings gone right, you should get a 3dsx in the output folder (ignore the rest of the files)
11. (extra) you can compile a cia if you have banner tool and makerom setup, just run make cia instead of make 3dsx
