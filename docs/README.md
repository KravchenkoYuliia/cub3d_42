
## malloc that we need to free at the end

- general struct t_cub and what is inside it;
- la structure for mlx variable				free(mlx_struct);
- pointer to make a connection with the minilibX	free(mlx_struct->ptr);

## minilibX pairs (create-destroy)

1. mlx_init()	 		-> 	mlx_destroy_display(); free(pointer);
2. mlx_new_window()		-> 	mlx_destroy_window();
3. mlx_new_image()		->	mlx_destroy_image();


## screen size

command: **xdpyinfo | grep dimensions**
result: **dimensions:    2560x1440 pixels (677x381 millimeters)**

