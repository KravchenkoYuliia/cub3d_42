## Parsing

### Verif file
- [] check that we are using a `.cub` file
- [] if empty lines, go to the next one except in the map
- Check that the file always start with the element
	- [] start with the direction (`NO`, `SO`, `WE`, `EA`)
	- [] path_to_texture
		- [] check that the path exist
		- [] check that the file exist
		- [] check that the extension file is correct
			- [] TODO: format file to be defined
	- [] RGB format
		- [] should start with `C` or `F`
		- [] check value well between `0` and `255`
		- [] check that we have 3 differents value for `R`, `G`, `B`

### Verif map

- [] Check that we only have `1`, `0`, `N`, `S`,`E`, `W`
- [] Check that the map is closed with walls `1`


> test qqch important

```C
int	i = 0;
```