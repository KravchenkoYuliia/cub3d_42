## Parsing

### Verif file
- [] check that the program only has 1 argument ✅
- [] check that we are using a `.cub` file ✅
- [] check if file is empty 
	- [] if there is nothing inside ✅
	- [] if there only are spaces/tabs/new_lines:
		read lines with get next line -> check it -> put it to struct and 
		if struct is NULL after reading file -> map is empty
- [] if empty lines, go to the next one except in the map
- Check that the file always start with the element
	- [] start with the direction (`NO`, `SO`, `WE`, `EA`)✅
	- [] check that there is every element and without doubles
	- [] path_to_texture
		- [] check that only 1 path is given, otherwise - error msg✅
		- [] check that the path file exist ✅
		- [] check that the extension file is correct ✅
			- [] extension .xpm (X Pixmap) is supported with MinilibX
				function -> mlx_xpm_file_to_image
	- [] RGB format
		- [] should start with `C` or `F`
		- [] check value well between `0` and `255` and only digit character
		- [] check that we have 3 differents value for `R`, `G`, `B` and no more
			- [] if more than 3 write an error message
		- [] check that the values are separated with `,`		
		
	
### Verif map

- [] Check that we only have `1`, `0`, `N`, `S`,`E`, `W`
- [] Check that the map is closed with walls `1`
- [] check that there is only 1 player (letter on the map)
	- [] if no player or more that 1 - error msg
- [] check that map is at the end of file ✅


## MinilibX

- [] TODO check this line "the management of your window must remain smooth: changing to another win-
dow, minimizing, etc."

## Ray Casting

- [] TODO read smth about it


> test qqch important

```C
int	i = 0;
```
