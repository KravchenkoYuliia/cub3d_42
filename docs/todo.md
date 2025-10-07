## Parsing

### Parsing must be done in 2 stages
####Part1
 - [x] Split line and if it's `NO` `SO` `EA` `WE` `F` or `C` -> work with it

#### Part 2
 - [x] EVERYTHING that is not from Part 1 -> is a map (all type of errors as well)
 - [] working with map without split -> character by character





### Verif file
- [x] check that the program only has 1 argument 
- [x] check that we are using a `.cub` file 
- [x] check if file is empty 
	- [x] if there is nothing inside 
	- [x] if there only are spaces/tabs/new_lines
- [x] if empty lines, go to the next one except in the map
- Check that the file always start with the element
	- [x] start with the direction (`NO`, `SO`, `WE`, `EA`)
	- [x] check that there is every element and without doubles
	- [x] path_to_texture
		- [x] check that only 1 path is given, otherwise - error msg
		- [x] check that the path file exist 
		- [x] check that the extension file is correct 
			- [x] extension .xpm (X Pixmap) is supported with MinilibX
				function -> mlx_xpm_file_to_image
	- [x] RGB format
		- [x] there only are 2 elements ('C' or 'F' + rgb color) 
		- [x] should start with `C` or `F` 
		- [x] check value well between `0` and `255` and only digit character 
		- [x] check that we have 3 differents value for `R`, `G`, `B` and no more 
			- [x] if more than 3 write an error message 
		- [x] check that the values are separated with `,`
		- [x] only two ',' 
		- [x] no ',' at the start and at the end of RGB
		

### Verif map

- [x] no empty lines in map 
- [x] Check that we only have `1`, `0`, `N`, `S`,`E`, `W`, SPACE 
- [x] check that there is only 1 player (letter on the map)
	- [x] if no player or more that 1 - error msg
- [x] check that map is at the end of file 
- [] Check that the map is closed with walls `1`
- [] handle spaces:
	- [] make the map rectangular to parse the spaces from the outside of the map
	- [] all spaces from the outside of the map replace (temporarily??) with smth else
	- [] now recheck all the map and all spaces found are considered now as inside spaces - replace with 		`0` to mark floor

## MinilibX

- [] TODO check this line "the management of your window must remain smooth: changing to another win-
dow, minimizing, etc."

## Ray Casting

- [] TODO read smth about it


> test qqch important

```C
int	i = 0;
```
